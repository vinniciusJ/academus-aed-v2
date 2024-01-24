//
// Created by vinniciusj on 13/09/23.
//

#include "headers/course-controller.h"
#include "../views/headers/course-view.h"
#include "../app.h"
#include "../views/headers/views.h"
#include "../utils/headers/file.h"
#include "../utils/headers/list.h"
#include "../services/headers/course-service.h"
#include "../utils/headers/utils.h"

// Inicia a navegação na seção de cursos
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_course_controller(){
    int option = 0;

    show_course_menu();
    option = input_option();

    system("clear");

    switch (option) {
        case 0:
            start_app_router();
            break;
        case 1:
            create_course();
            break;
        case 2:
            show_courses();
            break;
        default:
            show_invalid_option_message();
            start_course_controller();
    }

    start_course_controller();
}

// Lida com a criação do curso
// Pré-condição: nenhuma
// Pós-condição: curso criado e inserido no arquivo course.bin
void create_course() {
    FILE * file = open_bin_tree_file("course.bin");

    Course * course = input_course();
    Header * header = read_header(file);

    Status * status = insert_course(*course, header->root_position, file);

    if(status->code == 1) {
        show_sucess_message(status->message);
        show_course_table_header();
        show_course(*course);
    } else {
        show_error_message(status->message);
    }

    wait_to_continue();

    free_space(course);
    free_space(status);
    fclose(file);
}

void show_courses_inorder(int currentPosition, FILE *file) {
    if (currentPosition == -1) {
        return;
    }

    CourseNode *course_node = read_node(currentPosition, sizeof(CourseNode), file);

    // Traverse the left subtree
    show_courses_inorder(course_node->left, file);

    // Process the current node (display the course information)
    show_course(course_node->value);

    // Traverse the right subtree
    show_courses_inorder(course_node->right, file);

}


// Lida com a visualização de todos os cursos
// Pré-condição: nenhuma
// Pós-condição: mostra todos os cursos cadastrados no arquivo
void show_courses() {
   FILE * file = open_bin_tree_file("course.bin");
    Header * header = read_header(file);

    int position = header->root_position;
    CourseNode * course_node = NULL;

    show_course_list_heading();

    if(is_list_empty(header)){
        show_alert("Não há nenhum curso cadastrado!");
        return;
    }

    show_course_table_header();

    show_courses_inorder(header->root_position, file);

    fclose(file);
    wait_to_continue();

}