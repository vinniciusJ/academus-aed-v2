//
// Created by vinniciusj on 14/09/23.
//
#include <stdio.h>

#ifndef ACADEMUS_FILE_H
#define ACADEMUS_FILE_H

// Abre um arquivo
// Pré-condição: nome válido de arquivo e o modo para abertura
// Pós-condição: retorna um arquivo aberto
FILE * open_bin_tree_file(char * filename);

// Abre um arquivo txt para leitura
// Pré-condição: nenhuma
// Pós-condição: retorna o arquivo aberto para leitura
FILE * open_read_file(char * filename);

#endif //ACADEMUS_FILE_H
