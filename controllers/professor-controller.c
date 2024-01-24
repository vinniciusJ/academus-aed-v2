//
// Created by vinniciusj on 13/09/23.
//
#include "headers/professor-controller.h"
#include "../views/headers/professor-view.h"
#include "../views/headers/views.h"
#include "../utils/headers/file.h"
#include "../utils/headers/utils.h"
#include "../app.h"
#include "../models/professor.h"
#include "../services/headers/professor-service.h"
#include "../utils/headers/list.h"

// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_professor_router(){
    int option = 0;

    show_professor_menu();
    option = input_option();

    system("clear");

    switch (option) {
        case 0:
            start_app_router();
            break;
        case 1:
            create_professor();
            break;
        case 2:
            show_professors();
            break;
        default:
            show_invalid_option_message();
            start_professor_router();
    }

    start_professor_router();
}

// Lida com a criação do professor
// Pré-condição: nenhuma
// Pós-condição: professor criado e inserido no arquivo
void create_professor() {
    FILE * file = open_bin_tree_file("professor.bin");
    Header * header = read_header(file);

    Professor * professor = input_professor();

    Status * status = insert_professor(*professor, header->root_position, file);

    if(status->code == 1) {
        show_sucess_message(status->message);
        show_professor_table_header();
        show_professor(*professor);
    } else {
        show_error_message(status->message);
    }

    free_space(status);
    free_space(professor);
    fclose(file);

    wait_to_continue();
}

void show_professors_in_order(int currentPosition, FILE *file) {
    if (currentPosition == -1) {
        return;
    }

    ProfessorNode *professor_node = read_node(currentPosition, sizeof(ProfessorNode), file);

    // Traverse the left subtree
    show_professors_in_order(professor_node->left, file);

    // Process the current node (display the course information)
    show_professor(professor_node->value);

    // Traverse the right subtree
    show_professors_in_order(professor_node->right, file);

}

// Lida com a visualização de todos os professores
// Pré-condição: nenhuma
// Pós-condição: mostra todos os professores cadastrados no arquivo
void show_professors(){
    FILE * file = open_bin_tree_file("professor.bin");
    Header * header = read_header(file);

    int position = header->root_position;
    ProfessorNode * course_node = NULL;


    if(is_list_empty(header)){
        show_alert("Não há nenhum curso cadastrado!");
        return;
    }

    show_professor_table_header();

    show_professors_in_order(header->root_position, file);

    fclose(file);
    wait_to_continue();
 }