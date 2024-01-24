//
// Created by nikoly on 13/10/23.
//
#include <stdio.h>

#ifndef ACADEMUS_SERVICE_H
#define ACADEMUS_SERVICE_H

// Lida com a inclusão em lote
// Pré-condição: nenhuma
// Pós-condição: inclusão de dados no arquivo de lote concluida
void insert_in_batch(FILE * file);

// Lê os dados de um curso do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Course (caracter C já ter sido lido)
// Pós-condição: inclusão do curso
void handle_course(const char *line);

// Lê os dados de uma disciplina do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Subject (caracter D já ter sido lido)
// Pós-condição: inclusão da disciplina
void handle_subject(const char *line);

// Lê os dados de um professor(a) do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Professor (caracter P já ter sido lido)
// Pós-condição: inclusão do professor(a)
void handle_professor(const char *line);

// Lê os dados de um modulo do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Module (caracter P já ter sido lido)
// Pós-condição: inclusão do professor(a)
void handle_module(const char *line);

#endif //ACADEMUS_SERVICE_H
