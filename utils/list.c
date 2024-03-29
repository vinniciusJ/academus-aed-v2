//
// Created by vinniciusj on 14/09/23.
//
#include <stdlib.h>

#include "headers/utils.h"
#include "../models/header.h"
#include "headers/list.h"

// Lê uma nó da lista em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista e a posição deve ser uma posição válida da lista
// Pós-condição: ponteiro para nó lido é retornado
void * read_node(int position, size_t size, FILE * file){
    if(position == -1){
        return NULL;
    }

    void * item = alloc(size);

    fseek(file, sizeof(Header) + position * size, SEEK_SET);
    fread(item, size, 1, file);

    return item;
}

// Escreve um nó em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista, deve passar o tamanho do nó e a posição deve ser valida no arquivo
// Pós-condição: nó escrito no arquivo
void set_node(void * node, size_t size, int position, FILE * file){
    fseek(file, sizeof(Header) + position * size, SEEK_SET);
    fwrite(node, size, 1, file);
}

// Escreve no arquivo o cabeç alho contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: cabeçaalho escrito no arquivo
void set_header(Header * header, FILE * file){
    fseek(file, 0, SEEK_SET);
    fwrite(header, sizeof(Header), 1, file);
}

// Criar uma lista nova em um arquivo
// Pré-condição: arquivo aberto para leitura/escrita
// Pós-condição: arquivo é inicializado com uma lista vazia
void create_empty_list(FILE *file) {
    Header *header = (Header *) alloc(sizeof(Header));

    header->root_position = -1;
    header->top_position = 0;
    header->num_free_positions = 0;

    for (int i = 0; i < MAX_FREE_POSITIONS; ++i) {
        header->free_positions[i] = -1;
    }

    set_header(header, file);

    free_space(header);
}

// Lê o cabeçalho do arquivo contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e deve ser um arquivo de lista
// Pós-condição: retorna o ponteiro para o cabeçalho lido
Header * read_header(FILE * file){
    Header * header = (Header *) alloc(sizeof(Header));

    fseek(file, 0, SEEK_SET);
    fread(header, sizeof(Header), 1, file);

    return header;
}
// Verifica se a lista está vazia
// Pré-condição: o cabeçalho do arquivo
// Pós-condição: retorna se a lista está vazia
int is_list_empty(Header * header){
    return header->root_position == -1;
}


