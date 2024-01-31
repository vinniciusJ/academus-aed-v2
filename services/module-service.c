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

typedef struct {
    int current;
    int previous;
    int next;
    ModuleNode * value;
} Position;

char* concatenate_integers(int num1, int num2) {
    int length = snprintf(NULL, 0, "%d", num1) + snprintf(NULL, 0, "%d", num2) + 1;

    char* result = (char*)malloc(length);

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    snprintf(result, length, "%d%d", num1, num2);

    return result;
}

// Pré-condição: um novo módulo e um arquivo aberto para escrita
// Pós-condição: módulo salvo no arquivo lista
Status * insert_module(Module module, int current_position, FILE * file){
    Header * header = read_header(file);

    module.code = concatenate_integers(module.academic_year, module.subject_code);

    ModuleNode node = {module, -1, -1};

    Status * status = validate_module(module);

    if(current_position == -1){
        set_node(&node, sizeof(ModuleNode), header->top_position, file);
        header->root_position = header->top_position;
        header->top_position++;
    }
    else {
        ModuleNode * current_node = read_node(current_position, sizeof(ModuleNode), file);

        if(strcmp(module.code, current_node->value.code) < 0){
            if(current_node->left == -1){
                set_node(&node, sizeof(ModuleNode), header->top_position, file);

                current_node->left = header->top_position;
                header->top_position++;
            }
            else {
                insert_module(module, current_node->left, file);
            }
        }
        else if(strcmp(module.code, current_node->value.code) > 0){
            if(current_node->right == -1){
                set_node(&node, sizeof(ModuleNode), header->top_position, file);

                current_node->right = header->top_position;
                header->top_position++;
            }
            else {
                insert_module(module, current_node->right, file);
            }
        }

        set_node(current_node, sizeof(ModuleNode), current_position, file);
    }

    set_header(header, file);
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

 Module * get_module_by(int academic_year, int subject_code, FILE * modules_file){
     /*Header * header = read_header(modules_file);
     ModuleNode * module_node = NULL;

     int position = header->root_position;

     if(is_list_empty(header)){
         return NULL;
     }

     while(position != -1){
         module_node = read_node(position, sizeof(ModuleNode), modules_file);

         Module module = module_node->value;

         if(module.subject_code == subject_code && module.academic_year == academic_year){
             return &module_node->value;
         }

         position = module_node->next;
     }
    */
     return NULL;
 }

 // Valida o módulo e retorna um status da inserção de acordo com o resultado
 // Pré-condição: um novo módulo
 // Pós-condição: status para a inserção (código 1 para sucesso e 0 para erro)
 Status * validate_module(Module module) {
     FILE * subject_file = open_bin_tree_file("subject.bin");
     FILE * professor_file = open_bin_tree_file("professor.bin");
     Status * status = (Status *) alloc(sizeof(Status));
     status->code = 0;

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