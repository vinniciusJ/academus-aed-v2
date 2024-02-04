//
// Created by vinniciusj on 14/09/23.
//
//
// Created by vinniciusj on 14/09/23.
//
#include <stdio.h>

#include "headers/utils.h"

// Aloca um espaço dinâmico na memória
// Pŕe-condição: tamanho do espaço a ser alocado na memória
// Pós-condição: retorna um ponteiro referenciado ao enedreço alocado
void * alloc(size_t size){
    void * ptr = malloc(size);

    if(ptr == NULL){
        printf("Não há espaço em memória\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

// Libera um espaço alocado dinamicamente na memória
// Pré-condição: o endereço alocado dinamicamente
// Pós-condição: retorna um endereço NULL
void * free_space(void * ptr){
    free(ptr);

    return NULL;
}

char* concatenate_integers(int num1, int num2) {
    int length = snprintf(NULL, 0, "%d", num1) + snprintf(NULL, 0, "%d", num2) + 1;

    char* result = (char*)malloc(length);

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    snprintf(result, length, "%d%d", num1, num2);

    return result;
}
