//
// Created by vinniciusj on 15/09/23.
//
#include <string.h>
#include "headers/module-service.h"
#include "headers/subject-service.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"

#include "../models/subject.h"
#include "../utils/headers/file.h"
#include "headers/professor-service.h"

// Pré-condição: um novo módulo e um arquivo aberto para escrita
// Pós-condição: módulo salvo no arquivo lista
Status * insert_module(Module module, int current_position, FILE * file){
    Header * header = read_header(file);
    Status * status = validate_module(module);

    ModuleNode node = {module, -1, -1};

    int insert_position;

    if (header->num_free_positions > 0) {
        insert_position = header->free_positions[--(header->num_free_positions)];
    } else {
        insert_position = header->top_position++;
    }

    if(header->root_position == -1){
        set_node(&node, sizeof(ModuleNode), insert_position, file);
        header->root_position = insert_position;
        set_header(header, file);

        return status;
    }

    ModuleNode * current_node = read_node(current_position, sizeof(ModuleNode), file);

    if(module.code < current_node->value.code){
        if(current_node->left == -1){
            set_node(&node, sizeof(ModuleNode), insert_position, file);
            current_node->left = insert_position;
            set_header(header, file);
        }
        else {
            insert_module(module, current_node->left, file);
        }

    }
    else if(module.code > current_node->value.code){
        if(current_node->right == -1){
            set_node(&node, sizeof(ModuleNode), insert_position, file);
            current_node->right = insert_position;
            set_header(header, file);
        }
        else {
            insert_module(module, current_node->right, file);
        }
    }

    set_node(current_node, sizeof(ModuleNode), current_position, file);

    free_space(header);

    return status;
}

ModuleNode * get_module_by_course(int course_code, int current_position, FILE * modules_file, FILE * subjects_file){
    if(current_position == -1){
        return NULL;
    }

    Header * subject_header = read_header(subjects_file);

    ModuleNode * module_node = read_node(current_position, sizeof(ModuleNode), modules_file);
    Subject * subject = get_subject_by_code(module_node->value.subject_code, subject_header->root_position,
                                                subjects_file);

    free_space(subject_header);

    if(subject != NULL && subject->course_code == course_code){
        return module_node;
    }
    else if(course_code < subject->course_code){
        return get_module_by_course(course_code, module_node->left, modules_file, subjects_file);
    }
    else {
        return get_module_by_course(course_code, module_node->right, modules_file, subjects_file);
    }
}

int get_min_node(int current_position, FILE * file){
    if(current_position == -1){
        return -1;
    }

    ModuleNode * current = read_node(current_position, sizeof(ModuleNode), file);

    while(current->left != -1){
        current = read_node(current->left, sizeof(ModuleNode), file);
    }

    return current_position;
}

int remove_module(Module module, int current_position, FILE * file) {
    if (current_position == -1) {
        return -1;
    }

    Header *header = read_header(file);
    ModuleNode *node = read_node(current_position, sizeof(ModuleNode), file);

    char *module_code = concatenate_integers(module.academic_year, module.subject_code);
    char *node_code = concatenate_integers(node->value.academic_year, node->value.subject_code);

    if (strcmp(module_code, node_code) < 0) {
        node->left = remove_module(module, node->left, file);
        set_node(node, sizeof(ModuleNode), current_position, file);
    }
    else if (strcmp(module_code, node_code) > 0) {
        node->right = remove_module(module, node->right, file);
        set_node(node, sizeof(ModuleNode), current_position, file);
    }
    else {
        if (node->left == -1) {
            int right = node->right;

            printf("num free before: %d\n", header->num_free_positions);
            header->free_positions[header->num_free_positions] = current_position;
            header->num_free_positions++;

            printf("num free aft: %d\n", header->num_free_positions);
            set_header(header, file);

            printf("free: %d == %d", header->free_positions[header->num_free_positions], current_position);

            free_space(header);
            free_space(node);
            free_space(node_code);
            free_space(module_code);

            return right;
        }
        else if (node->right == -1) {
            int left = node->left;

            printf("num free bef: %d\n", header->num_free_positions);
            header->free_positions[header->num_free_positions++] = current_position;
            set_header(header, file);

            printf("num free aft: %d\n", header->num_free_positions);
            printf("free: %d == %d", header->free_positions[header->num_free_positions], current_position);

            free_space(header);
            free_space(node);
            free_space(node_code);
            free_space(module_code);

            return left;
        }

        int min_position = get_min_node(node->right, file);
        ModuleNode *min_node = read_node(min_position, sizeof(ModuleNode), file);

        node->value = min_node->value;

        node->right = remove_module(node->value, node->right, file);
    }

    set_node(node, sizeof(ModuleNode), current_position, file);

    free_space(node_code);
    free_space(module_code);
    free_space(header);

    return current_position;
}

 Module * get_module_by(int academic_year, int subject_code, FILE * modules_file){
     Header *header = read_header(modules_file);
     ModuleNode *module_node = NULL;

     int position = header->root_position;

     if (is_list_empty(header)) {
         return NULL;
     }

     while (position != -1) {
         module_node = read_node(position, sizeof(ModuleNode), modules_file);

         Module module = module_node->value;

         if (module.subject_code == subject_code && module.academic_year == academic_year) {
             return &module_node->value;
         } else if (academic_year < module.academic_year || (academic_year == module.academic_year && subject_code < module.subject_code)) {
             // If the target module should be in the left subtree
             position = module_node->left;
         } else {
             // If the target module should be in the right subtree
             position = module_node->right;
         }
     }

     return NULL;
 }

 // Valida o módulo e retorna um status da inserção de acordo com o resultado
 // Pré-condição: um novo módulo
 // Pós-condição: status para a inserção (código 1 para sucesso e 0 para erro)
 Status * validate_module(Module module) {
     FILE * subject_file = open_bin_tree_file("subject.bin");
     FILE * professor_file = open_bin_tree_file("professor.bin");
     Status * status = (Status *) alloc(sizeof(Status));
     status->code = 1;

     /*char message[1000];

     int subject_exists = !!get_subject_by_code(module.subject_code, subject_file);
     int professor_exists = !!get_professor_by_code(module.professor_code, professor_file);

     if(!subject_exists && !professor_exists) {
         sprintf(message, "Não existe uma disciplina cadastrada com o código %d e não existe um professor(a) cadastrado(a) com o código %d! Portanto, o módulo não foi cadastrado.", module.subject_code, module.professor_code);
     }

     else if(!subject_exists) {
         sprintf(message, "Não existe uma disciplina cadastrada com o código %d! Portanto, o módulo não foi cadastrado.", module.subject_code);
     }

     else if(!professor_exists) {
         sprintf(message, "Não existe um professor(a) cadastrado(a) com o código %d! Portanto, o módulo não foi cadastrado.", module.professor_code);
     }

     else {
         status->code = 1;
         sprintf(message, "Módulo cadastrado com sucesso!");
     }

     strcpy(status->message, message);

     fclose(professor_file);
     fclose(subject_file);
      */
     return status;
 }