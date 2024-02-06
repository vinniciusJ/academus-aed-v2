//
// Created by vinniciusj on 15/09/23.
//
#include <stdio.h>

#include "../../models/professor.h"
#include "../../models/status.h"

#ifndef ACADEMUS_PROFESSOR_SERVICE_H
#define ACADEMUS_PROFESSOR_SERVICE_H

// Insere um value no arquivo lista
// Pré-condição: um novo professor, uma posicao inicial, um arquivo aberto para escrita
// Pós-condição: status da inserção do professor
Status * insert_professor(Professor professor, int current_position, FILE * file);

// Busca um professor pelo código na lista
// Pré-condição: código do professor e um arquivo lista aberto para leitura
// Pós-condição: professor ou NULL caso não tenha sido encontrado
Professor * get_professor_by_code(int code, int current_position, FILE * file);

// Valida o professor e retorna um status da inserção de acordo com o resultado
// Pré-condição: um novo professor e um arquivo aberto para leitura
// Pós-condição: status para a inserção (código 1 para sucesso e 0 para erro)
Status * validate_professor(Professor professor, FILE * file);

#endif //ACADEMUS_PROFESSOR_SERVICE_H
