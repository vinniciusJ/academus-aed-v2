//
// Created by vinniciusj on 15/09/23.
//
#include <string.h>
#include "headers/professor-service.h"
#include "../utils/headers/list.h"
#include "../utils/headers/utils.h"

// Insere um value no arquivo lista
// Pré-condição: um novo professor, uma posicao inicial, um arquivo aberto para escrita
// Pós-condição: status da inserção do professor
Status * insert_professor(Professor professor, int current_position, FILE * file){
    Header * header = read_header(file);
    Status * status = validate_professor(professor, file);

    ProfessorNode node = {professor, -1, -1};

    if(header->root_position == -1){
        set_node(&node, sizeof(ProfessorNode), header->top_position, file);

        header->root_position = header->top_position;
        header->top_position++;

        set_header(header, file);

        return status;
    }

    ProfessorNode * current_node = read_node(current_position, sizeof(ProfessorNode), file);

    if(professor.code < current_node->value.code){
        if(current_node->left == -1){
            set_node(&node, sizeof(ProfessorNode), header->top_position, file);

            current_node->left = header->top_position;
            header->top_position++;

            set_header(header, file);
        }
        else {
            insert_professor(professor, current_node->left, file);
        }

    }
    else if(professor.code > current_node->value.code){
        if(current_node->right == -1){
            set_node(&node, sizeof(ProfessorNode), header->top_position, file);

            current_node->right = header->top_position;
            header->top_position++;

            set_header(header, file);
        }
        else {
            insert_professor(professor, current_node->right, file);
        }
    }

    set_node(current_node, sizeof(ProfessorNode), current_position, file);

    free_space(header);

    return status;
}

// Busca um professor pelo código na lista
// Pré-condição: código do professor e um arquivo lista aberto para leitura
// Pós-condição: professor ou NULL caso não tenha sido encontrado
Professor * get_professor_by_code(int code, int current_position, FILE * file){
    Header * header = read_header(file);

    if(is_list_empty(header) || current_position == -1){
        return NULL;
    }

    ProfessorNode * node = read_node(current_position, sizeof(ProfessorNode), file);

    if(node != NULL){
        if(code < node->value.code){
            return get_professor_by_code(code, node->left, file);
        }
        else if(code > node->value.code){
            return get_professor_by_code(code, node->right, file);
        }

        return &node->value;
    }

    return NULL;
}

// Valida o professor e retorna um status da inserção de acordo com o resultado
// Pré-condição: um novo professor e um arquivo aberto para leitura
// Pós-condição: status para a inserção (código 1 para sucesso e 0 para erro)
Status * validate_professor(Professor professor, FILE * file) {
    Status * status = (Status *) alloc(sizeof(Status));
    /*
    if(get_professor_by_code(professor.code, file)) {
        status->code = 0;
        char message[256];
        sprintf(message, "Já existe um(a) professor(a) com o código %d! Portanto o(a) professor(a) não foi cadastrado(a).", professor.code);
        strcpy(status->message, message);
    } else {
        status->code = 1;
        strcpy(status->message, "Professor(a) cadastrado(a) com sucesso!");
    }
    */
    return status;
}
