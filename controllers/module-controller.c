//
// Created by vinniciusj on 13/09/23.
//
#include <stdlib.h>
#include <stdio.h>

#include "./headers/module-controller.h"
#include "../views/headers/views.h"
#include "../views/headers/module-view.h"
#include "../app.h"
#include "../utils/headers/file.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"
#include "../services/headers/module-service.h"
#include "../services/headers/professor-service.h"
#include "../services/headers/subject-service.h"
#include "../models/course.h"

#define MODULES_FILE "module.bin"

// Inicia a navegação na seção de módulo
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_module_router(){
    int option = 0;

    show_module_menu();
    option = input_option();

    system("clear");

    switch (option) {
        case 0:
            start_app_router();
            break;
        case 1:
            create_module();
            break;
        case 2:
            show_modules();
            break;
        case 3:
            delete_course();
            break;
        default:
            show_invalid_option_message();
            start_module_router();
    }

    start_module_router();
}

// Lida com a criação de um módulo
// Pré-condição: nenhuma
// Pós-condição: módulo criado e inserido no arquivo
void create_module(){
    /*FILE * file = open_bin_tree_file(MODULES_FILE);
    FILE * professor_file = open_bin_tree_file("professor.bin");
    FILE * subject_file = open_bin_tree_file("subject.bin");
    Module * module = input_module();

    Status * status = insert_module(*module, file);

    if(status->code == 1) {
        show_sucess_message(status->message);
        Professor * professor = get_professor_by_code(module->professor_code, professor_file);
        Subject * subject = get_subject_by_code(module->subject_code, subject_file);
        show_module_table_header();
        show_module(*module, *subject, *professor);
    } else {
        show_error_message(status->message);
    }

    free_space(module);
    free_space(status);
    fclose(file);
    fclose(professor_file);
    fclose(subject_file);

    wait_to_continue();
     */
}

// Lida com a visualização de todos os módulos
// Pré-condição: nenhuma
// Pós-condição: mostra todos os módulos cadastrados no arquivo
void show_modules(){
    /*FILE * module_file = open_bin_tree_file(MODULES_FILE);
    FILE * professor_file = open_bin_tree_file("professor.bin");
    FILE * subject_file = open_bin_tree_file("subject.bin");
    FILE * courses_file = open_bin_tree_file("course.bin");

    Header * course_header = read_header(courses_file);
    Header * module_header = read_header(module_file);

    ModuleNode * module_node = NULL;
    CourseNode * course_node = NULL;

    int course_position = course_header->root_position, module_position = module_header->root_position;

    if(is_list_empty(course_header)){
        show_alert("Nenhum curso e módulo cadastrados");
        return;
    }

    while(course_position != -1){
        course_node = read_node(course_position, sizeof(CourseNode), courses_file);

        show_module_course(course_node->value.name);
        show_module_table_header();

        while(module_position != -1){
            module_node = get_module_by_course(course_node->value.code, module_position, module_file, subject_file);

            if(module_node == NULL) {
                break;
            }

            Module module = module_node->value;

            Professor * professor = get_professor_by_code(module.professor_code, professor_file);
            Subject * subject = get_subject_by_code(module.subject_code, subject_file);

            show_module(module, *subject, *professor);

            module_position = module_node->next;

            free_space(module_node);
            free_space(subject);
            free_space(professor);
        }

        course_position = course_node->next;
        module_position = module_header->root_position;;

        free_space(course_node);
    }

    fclose(subject_file);
    fclose(module_file);
    fclose(courses_file);
    fclose(professor_file);

    free_space(module_header);
    free_space(course_header);

    wait_to_continue();/*/

}

void delete_course(){
    /*FILE * modules_file = open_bin_tree_file(MODULES_FILE);
    FILE * professor_file = open_bin_tree_file("professor.bin");
    FILE * subject_file = open_bin_tree_file("subject.bin");

    show_module_menu_header();

    printf("\n");
    int academic_year = input_number("Informe o ano letivo");
    int subject_code = input_number("Informe o código da disciplina");
    printf("\n");

    Module * module = get_module_by(academic_year, subject_code, modules_file);

    if(module == NULL){
        show_alert("Não foi possível encontrar nenhum módulo de disciplina");
        return;
    }

    Professor * professor = get_professor_by_code(module->professor_code, professor_file);
    Subject  * subject = get_subject_by_code(module->subject_code, subject_file);

    show_module_table_header();
    show_module(*module, *subject, *professor);

    int confirmed = confirm_action("Você deseja remover este módulo de disciplina?");

    if(confirmed){
        system("clear");
        remove_module(*module, modules_file);
        show_sucess_message("Módulo de disciplina excluído com sucesso");

        wait_to_continue();
    }*/
}