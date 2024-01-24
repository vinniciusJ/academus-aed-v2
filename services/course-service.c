//
// Created by vinniciusj on 15/09/23.
//
#include <string.h>
#include "../utils/headers/list.h"
#include "headers/course-service.h"
#include "../utils/headers/utils.h"

// Insere um curso no arquivo lista
// Pré-condição: um novo curso e um arquivo aberto para escrita
// Pós-condição: status da inserção do curso
Status * insert_course(Course course, int current_position, FILE * file) {
    Header * header = read_header(file);
    Status * status = validate_course(course, file);

    if(current_position == -1){
        CourseNode node = {course, -1, -1};

        set_node(&node, sizeof(CourseNode), header->top_position, file);
        header->root_position = header->top_position;
        header->top_position++;
    }
    else {
        CourseNode * current_node = read_node(current_position, sizeof(CourseNode), file);

        if(course.code < current_node->value.code){
            if(current_node->left == -1){
                CourseNode node = {course, -1, -1};

                set_node(&node, sizeof(CourseNode), header->top_position, file);

                current_node->left = header->top_position;
                header->top_position++;


            }
            else {
                insert_course(course, current_node->left, file);
            }

        }
        else if(course.code > current_node->value.code){
            if(current_node->right == -1){
                CourseNode node = {course, -1, -1};

                set_node(&node, sizeof(CourseNode), header->top_position, file);

                current_node->right = header->top_position;
                header->top_position++;
            }
            else {
                insert_course(course, current_node->right, file);
            }
        }

        set_node(current_node, sizeof(CourseNode), current_position, file);
    }

    set_header(header, file);
    free_space(header);

    return status;
}

// Busca um curso pelo código na lista
// Pré-condição: código do curso e um arquivo lista aberto para leitura
// Pós-condição: curso ou NULL caso não tenha sido encontrado
Course * get_course_by_code(int code, int current_position, FILE * file){
    Header * header = read_header(file);

    if(is_list_empty(header) || current_position == -1){
        return NULL;
    }

    CourseNode * node = read_node(current_position, sizeof(CourseNode), file);

   if(node != NULL){
       if(code < node->value.code){
           return get_course_by_code(code, node->left, file);
       }
       else if(code > node->value.code){
           return get_course_by_code(code, node->right, file);
       }

       return &node->value;
   }

    return NULL;
}

// Valida o curso e retorna um status da inserção de acordo com o resultado
// Pré-condição: um novo curso e um arquivo aberto para leitura
// Pós-condição: status para a inserção (código 1 para sucesso e 0 para erro)
Status * validate_course(Course course, FILE * file) {
    Status * status = (Status *) alloc(sizeof(Status));
/*
    if(get_course_by_code(course.code, file)) {
        status->code = 0;
        char message[256];
        sprintf(message, "Já existe um curso cadastrado com o código %d! Portanto o curso não foi cadastrado.", course.code);
        strcpy(status->message, message);
    } else {
        status->code = 1;
        strcpy(status->message, "Curso cadastrado com sucesso!");
    }
/*/
    return status;
}
