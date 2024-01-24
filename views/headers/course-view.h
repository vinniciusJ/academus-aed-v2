//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_COURSE_VIEW_H
#define ACADEMUS_COURSE_VIEW_H

#include "../../models/course.h"

// Imprime o menu de opções da seção de cursos
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção é impresso no terminal
void show_course_menu();

// Requere do usuário as informações de um curso e retorna ele
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de curso é retornado e deve ser desalocado posteriormente
Course * input_course();

// Mostra no terminal um curso cadastrado
// Pré-condição: curso
// Pós-condição: curso é mostrado em tela
void show_course(Course course);

// Mostra o cabeçalho da tabela dos cursos
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void show_course_table_header();

// Mostra o cabeçalho da seção de listagem de cursos
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void show_course_list_heading();

// Diz se o caracter é uma área válida
// Pré-condição: caracter
// Pós-condição: nenhuma
int is_valid_area(char area);

#endif //ACADEMUS_COURSE_VIEW_H
