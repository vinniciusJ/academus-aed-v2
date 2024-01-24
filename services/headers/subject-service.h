//
// Created by vinniciusj on 15/09/23.
//

#include <stdio.h>

#include "../../models/subject.h"
#include "../../models/status.h"

#ifndef ACADEMUS_SUBJECT_SERVICE_H
#define ACADEMUS_SUBJECT_SERVICE_H

// Insere um value no arquivo lista
// Pré-condição: uma nova disciplina e um arquivo aberto para escrita
// Pós-condição: status da inserção da disciplina
Status * insert_subject(Subject subject, int current_position, FILE * file);

// Busca uma disciplina pelo código na lista
// Pré-condição: código da disciplina e um arquivo lista aberto para leitura
// Pós-condição: disciplina ou NULL caso não tenha sido encontrado
Subject * get_subject_by_code(int code, int current_position, FILE * file);

// Valida a disciplina e retorna um status da inserção de acordo com o resultado
// Pré-condição: uma nova disciplina e um arquivo aberto para leitura
// Pós-condição: status para a inserção (código 1 para sucesso e 0 para erro)
Status * validate_subject(Subject subject, FILE * file);

#endif //ACADEMUS_SUBJECT_SERVICE_H
