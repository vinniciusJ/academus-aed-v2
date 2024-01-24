//
// Created by vinniciusj on 14/09/23.
//
#include <stdlib.h>

#include "headers/file.h"
#include "headers/list.h"

// Abre um arquivo
// Pré-condição: nome válido de arquivo e o modo para abertura
// Pós-condição: retorna um arquivo aberto
FILE  * open_bin_tree_file(char * filename){
    FILE * file_exists = fopen(filename, "rb");

    if(file_exists == NULL){
        FILE * file = fopen(filename, "w+b");

        create_empty_list(file);

        return file;
    }

    fclose(file_exists);

    return fopen(filename, "r+b");
}

// Abre um arquivo txt para leitura
// Pré-condição: nenhuma
// Pós-condição: retorna o arquivo aberto para leitura
FILE * open_read_file(char * filename) {
    FILE * file;
    file = fopen(filename, "r");

    if(file == NULL) {
        printf("\nNão foi possível abrir o arquivo!\n");
        return 0;
    }

    return file;
}