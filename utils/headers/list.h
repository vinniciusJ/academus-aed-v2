//
// Created by vinniciusj on 14/09/23.
//

#include "../../models/header.h"
#include <stdio.h>

#ifndef ACADEMUS_LIST_H
#define ACADEMUS_LIST_H

// Lê uma nó da lista em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista e a posição deve ser uma posição válida da lista
// Pós-condição: ponteiro para nó lido é retornado
void * read_node(int position, size_t size, FILE * file);

// Escreve um nó em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista, deve passar o tamanho do nó e a posição deve ser valida no arquivo
// Pós-condição: nó escrito no arquivo
void set_node(void * node, size_t size, int position, FILE * file);

// Criar uma lista nova em um arquivo
// Pré-condição: arquivo aberto para leitura/escrita
// Pós-condição: arquivo é inicializado com uma lista vazia
void create_empty_list(FILE * file);

// Lê o cabeçalho do arquivo contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e deve ser um arquivo de lista
// Pós-condição: retorna o ponteiro para o cabeçalho lido
Header * read_header(FILE * file);

// Escreve no arquivo o cabeç alho contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: cabeçaalho escrito no arquivo
void set_header(Header * header, FILE * file);

// Verifica se a lista está vazia
// Pré-condição: o cabeçalho do arquivo
// Pós-condição: retorna se a lista está vazia
int is_list_empty(Header * header);

#endif //ACADEMUS_LIST_H
