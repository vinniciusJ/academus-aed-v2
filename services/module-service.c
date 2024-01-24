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

// Pré-condição: um novo módulo e um arquivo aberto para escrita
// Pós-condição: módulo salvo no arquivo lista
Status * insert_module(Module module, FILE * file){
    Header * header = read_header(file);
    ModuleNode node = { module, header->root_position };

    Status * status = validate_module(module);
    /*
    if(status->code == 1) {
        if (header->free_position == -1) {
            set_node(&node, sizeof(ModuleNode), header->top_position, file); // Escrevendo nó no arquivo lista
            header->root_position = header->top_position;
            header->top_position++;
        } else {
            ModuleNode *aux = read_node(header->free_position, sizeof(ModuleNode), file);

            set_node(&node, sizeof(ModuleNode), header->free_position, file);
            header->root_position = header->free_position;
            header->root_position = aux->next;

            aux = free_space(aux);
        }

        set_header(header, file);
    }

    free_space(header);
     */

    return status;
}

Position get_module_position(Module module, Header * header, FILE * file){
   int position = header->root_position;
    int previous = header->root_position;

    ModuleNode * aux = NULL;
    /*
       int subject_code = module.subject_code;
       int academic_year = module.academic_year;

       while(position != -1  && (aux = read_node(position, sizeof(ModuleNode), file)) != NULL){
           if(aux->value.academic_year == academic_year && aux->value.subject_code == subject_code){
               break;
           }

           previous = position;
           position = aux->next;

           aux = free_space(aux);
       }

       Position module_position = { position, previous, aux->next, aux };

       return module_position;
        */
    Position module_position = { position, previous, 0, aux};

    return module_position;
}

// Retira um módulo do arquivo lista
// Pré-condição: arquivo aberto para escrita e deve ser um arquivo lista
// Pós-condição: módulo retirado da lista caso pertença a ela
void remove_module(Module module, FILE * file){
    /*Header * header = read_header(file);

    Position position = get_module_position(module, header, file);

    if(position.current != -1){
        if(position.current == position.previous){
            header->root_position = position.next;
        }
        else{
            ModuleNode * previous = read_node(position.previous, sizeof(ModuleNode), file);

            previous->next = position.next;
            set_node(previous, sizeof(ModuleNode), position.previous, file);
            free_space(previous);
        }

        position.value->next = header->free_position;
        header->free_position = position.current;

        set_node(position.value, sizeof(ModuleNode), position.current, file);
        set_header(header, file);

        free_space(position.value);
    }

    free_space(header);*/
}

ModuleNode * get_module_by_course(int course_code, int start_position, FILE * modules_file, FILE * subjects_file){
    /* Header * header = read_header(modules_file);

     ModuleNode * module_node = NULL;
     Subject * subject = NULL;

     int position = start_position == -1 ? header->root_position : start_position;

     if(is_list_empty(header)){
         return NULL;
     }

     while(position != -1){
         module_node = read_node(position, sizeof(ModuleNode), modules_file);

         Module module = module_node->value;
         subject = get_subject_by_code(module.subject_code, subjects_file);

         if(subject != NULL && subject->course_code == course_code){
             return module_node;
         }

         position = module_node->next;
     }
 */
     return NULL;

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