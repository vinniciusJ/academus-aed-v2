//
// Created by vinniciusj on 13/09/23.
//
#include<stdio.h>

#ifndef ACADEMUS_COURSE_CONTROLLER_H
#define ACADEMUS_COURSE_CONTROLLER_H

// Inicia a navegação na seção de cursos
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_course_controller();

// Lida com a criação do curso
// Pré-condição: nenhuma
// Pós-condição: curso criado e inserido no arquivo course.bin
void create_course();

// Função recursiva para mostrar em ordem os cursos
// Pré-condição: arquivo aberto para leitura
// Pós-condição: mostra os cursos ordenados pelo código
void show_courses_inorder(int currentPosition, FILE *file);

// Lida com a visualização de todos os cursos
// Pré-condição: nenhuma
// Pós-condição: mostra todos os cursos cadastrados no arquivo
void show_courses();



#endif //ACADEMUS_COURSE_CONTROLLER_H
