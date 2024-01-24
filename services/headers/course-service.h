//
// Created by vinniciusj on 15/09/23.
//

#include <stdio.h>

#include "../../models/course.h"
#include "../../models/status.h"

#ifndef ACADEMUS_COURSE_SERVICE_H
#define ACADEMUS_COURSE_SERVICE_H

// Insere um curso no arquivo lista
// Pré-condição: um novo curso e um arquivo aberto para escrita
// Pós-condição: status da inserção do curso
Status * insert_course(Course course, int currentPosition, FILE * file);

// Busca um curso pelo código na lista
// Pré-condição: código do curso e um arquivo lista aberto para leitura
// Pós-condição: curso ou NULL caso não tenha sido encontrado
Course * get_course_by_code(int code, int currentPosition, FILE * file);

// Valida o curso e retorna uma mensagem de feedback de acordo com o resultado
// Pré-condição: um novo curso e um arquivo aberto para leitura
// Pós-condição: mensagem de feedback para ser mostrada (código 1 para sucesso e 0 para erro)
Status * validate_course(Course course, FILE * file);

#endif //ACADEMUS_COURSE_SERVICE_H
