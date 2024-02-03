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
#include "../utils/headers/queue.h"

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
            show_module_codes_by_layer();
            break;
        case 4:
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
    FILE * module_file = open_bin_tree_file(MODULES_FILE);
    FILE * professor_file = open_bin_tree_file("professor.bin");
    FILE * subject_file = open_bin_tree_file("subject.bin");

    Header * module_header = read_header(module_file);
    Header * professor_header = read_header(professor_file);
    Header * subject_header = read_header(subject_file);

    Module * module = input_module();

    Status * status = insert_module(*module, module_header->root_position, module_file);

    if(status->code == 1) {
       show_sucess_message(status->message);
       Professor * professor = get_professor_by_code(module->professor_code, professor_header->root_position,
                                                     professor_file);
       Subject * subject = get_subject_by_code(module->subject_code, subject_header->root_position, subject_file);
       show_module_table_header();
       show_module(*module, *subject, *professor);
    } else {
       show_error_message(status->message);
    }

    free_space(module);
    free_space(status);
    fclose(module_file);
    fclose(professor_file);
    fclose(subject_file);

    wait_to_continue();
}

void show_modules_recursive(int course_code, int module_position, FILE *module_file, FILE *subject_file, FILE
*professor_file){
    if(module_position == -1){
        return;
    }

    ModuleNode *module_node = get_module_by_course(course_code, module_position, module_file, subject_file);

    if (module_node == NULL) {
        return;
    }

    Module module = module_node->value;

    Header * professor_header = read_header(professor_file);
    Header * subject_header = read_header(subject_file);

    Professor *professor = get_professor_by_code(module.professor_code,professor_header->root_position,
                                                 professor_file);
    Subject *subject = get_subject_by_code(module.subject_code, subject_header->root_position, subject_file);

    show_module(module, *subject, *professor);

    show_modules_recursive(course_code, module_node->left, module_file, subject_file, professor_file);
    show_modules_recursive(course_code, module_node->right, module_file, subject_file, professor_file);

    free_space(module_node);
    free_space(subject);
    free_space(professor);
}

void show_courses_recursive(int course_position, FILE *module_file, FILE *subject_file, FILE *professor_file, FILE *courses_file) {
    if (course_position == -1) {
        return;
    }

    Header * module_header = read_header(module_file);
    CourseNode *course_node = read_node(course_position, sizeof(CourseNode), courses_file);

    show_module_course(course_node->value.name);
    show_module_table_header();

    show_modules_recursive(course_node->value.code, module_header->root_position, module_file, subject_file, professor_file);

    show_courses_recursive(course_node->left, module_file, subject_file, professor_file, courses_file);
    show_courses_recursive(course_node->right, module_file, subject_file, professor_file, courses_file);

    free_space(course_node);
    free_space(module_header);
}


// Lida com a visualização de todos os módulos
// Pré-condição: nenhuma
// Pós-condição: mostra todos os módulos cadastrados no arquivo
void show_modules() {
    FILE *module_file = open_bin_tree_file(MODULES_FILE);
    FILE *professor_file = open_bin_tree_file("professor.bin");
    FILE *subject_file = open_bin_tree_file("subject.bin");
    FILE *courses_file = open_bin_tree_file("course.bin");

    Header *course_header = read_header(courses_file);

    if (is_list_empty(course_header)) {
        show_alert("Nenhum curso e módulo cadastrados");
        return;
    }

    show_courses_recursive(course_header->root_position, module_file, subject_file, professor_file, courses_file);

    fclose(subject_file);
    fclose(module_file);
    fclose(courses_file);
    fclose(professor_file);

    free_space(course_header);

    wait_to_continue();
}

void delete_course(){
    FILE * modules_file = open_bin_tree_file(MODULES_FILE);
    FILE * professor_file = open_bin_tree_file("professor.bin");
    FILE * subject_file = open_bin_tree_file("subject.bin");

    Header * professor_header = read_header(professor_file);
    Header * subject_header = read_header(subject_file);
    Header * module_header = read_header(modules_file);

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

    Professor * professor = get_professor_by_code(module->professor_code,professor_header->root_position,
                                                  professor_file);
    Subject  * subject = get_subject_by_code(module->subject_code, subject_header->root_position, subject_file);

    show_module_table_header();
    show_module(*module, *subject, *professor);

    int confirmed = confirm_action("Você deseja remover este módulo de disciplina?");

    if(confirmed){
        system("clear");
        remove_module(*module, module_header->root_position, modules_file);
        show_sucess_message("Módulo de disciplina excluído com sucesso");

        wait_to_continue();
    }
}

void show_module_codes_by_layer(){
    FILE * file = open_bin_tree_file("module.bin");
    Header * header = read_header(file);

    ModuleNode * root = read_node(header->root_position, sizeof(ModuleNode), file);
    Queue * queue = create_queue();

    enqueue(root, queue);

    while(!is_queue_empty(queue)){
        ModuleNode * current = dequeue(queue);

        printf("%d%d ", current->value.academic_year, current->value.subject_code);

        if(current->left != -1){
            current = read_node(current->left, sizeof (ModuleNode), file);
            enqueue(current, queue);
        }

        if(current->right != -1){
            current = read_node(current->right, sizeof (ModuleNode), file);

            enqueue(current, queue);
        }
    }

    clean_queue(queue);
}