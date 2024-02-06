//
// Created by vinniciusj on 15/09/23.
//
#include <string.h>
#include "headers/subject-service.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"
#include "headers/course-service.h"
#include "../utils/headers/file.h"

// Insere um value no arquivo lista
// Pré-condição: uma nova disciplina e um arquivo aberto para escrita
// Pós-condição: status da inserção da disciplina
Status * insert_subject(Subject subject, int current_position, FILE * file){
    Header * header = read_header(file);
    Status * status = validate_subject(subject, file);

    SubjectNode node = {subject, -1, -1};

    if(header->root_position == -1){
        set_node(&node, sizeof(SubjectNode), header->top_position, file);

        header->root_position = header->top_position;
        header->top_position++;

        set_header(header, file);

        return status;
    }

    SubjectNode * current_node = read_node(current_position, sizeof(SubjectNode), file);

    if(subject.code < current_node->value.code){
        if(current_node->left == -1){
            set_node(&node, sizeof(SubjectNode), header->top_position, file);

            current_node->left = header->top_position;
            header->top_position++;

            set_header(header, file);
        }
        else {
            insert_subject(subject, current_node->left, file);
        }

    }
    else if(subject.code > current_node->value.code){
        if(current_node->right == -1){
            set_node(&node, sizeof(SubjectNode), header->top_position, file);

            current_node->right = header->top_position;
            header->top_position++;

            set_header(header, file);
        }
        else {
            insert_subject(subject, current_node->right, file);
        }
    }

    set_node(current_node, sizeof(SubjectNode), current_position, file);

    free_space(header);

    return status;
}

// Busca uma disciplina pelo código na lista
// Pré-condição: código da disciplina e um arquivo lista aberto para leitura
// Pós-condição: disciplina ou NULL caso não tenha sido encontrado
Subject * get_subject_by_code(int code, int current_position, FILE * file){
    Header * header = read_header(file);

    if(is_list_empty(header) || current_position == -1){
        return NULL;
    }

    SubjectNode * node = read_node(current_position, sizeof(SubjectNode), file);

    if(node != NULL){
        if(code < node->value.code){
            return get_subject_by_code(code, node->left, file);
        }
        else if(code > node->value.code){
            return get_subject_by_code(code, node->right, file);
        }

        return &node->value;
    }

    return NULL;
}

// Valida a disciplina e retorna um status da inserção de acordo com o resultado
// Pré-condição: uma nova disciplina e um arquivo aberto para leitura
// Pós-condição: status para a inserção (código 1 para sucesso e 0 para erro)
Status * validate_subject(Subject subject, FILE * file) {
    FILE * course_file = open_bin_tree_file("course.bin");
    Status * status = (Status *) alloc(sizeof(Status));
    status->code = 0;

    /*char message[1000];

    int code_already_exists = !!get_subject_by_code(subject.code, file);
    int invalid_course = !get_course_by_code(subject.course_code, course_file);

    if(code_already_exists && invalid_course) {
        sprintf(message, "Já existe uma disciplina cadastrada com o código %d e não existe um curso cadastrado com o código %d! Portanto, a disciplina não foi cadastrada.", subject.code, subject.course_code);
    }

    else if(code_already_exists) {
        sprintf(message, "Já existe uma disciplina cadastrada com o código %d! Portanto, a disciplina não foi cadastrada.", subject.code);
    }

    else if(invalid_course) {
        sprintf(message, "Não existe um curso cadastrado com o código %d! Portanto, a disciplina não foi cadastrada.", subject.course_code);
    }

    else {
        status->code = 1;
        sprintf(message, "Disciplina cadastrada com sucesso!");
    }

    strcpy(status->message, message);

    fclose(course_file);
     */
    return status;
}