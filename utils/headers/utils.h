//
// Created by vinniciusj on 14/09/23.
//
#include <stdlib.h>

#ifndef ACADEMUS_MEMORY_H
#define ACADEMUS_MEMORY_H

// Aloca um espaço dinâmico na memória
// Pŕe-condição: tamanho do espaço a ser alocado na memória
// Pós-condição: retorna um ponteiro referenciado ao enedreço alocado
void * alloc(size_t size);

// Libera um espaço alocado dinamicamente na memória
// Pré-condição: o endereço alocado dinamicamente
// Pós-condição: retorna um endereço NULL
void * free_space(void * ptr);

// Concatena dois inteiros em uma string
// Pré-condição: dois inteiros
// Pós-condição: uma string com o seguinte padrão `${num1}${num2}`
char* concatenate_integers(int num1, int num2);

#endif //ACADEMUS_MEMORY_H
