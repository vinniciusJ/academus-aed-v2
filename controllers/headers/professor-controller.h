//
// Created by vinniciusj on 13/09/23.
//
#include<stdio.h>

#ifndef ACADEMUS_PROFESSOR_CONTROLLER_H
#define ACADEMUS_PROFESSOR_CONTROLLER_H

// Inicia a navegação na seção de professor
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_professor_router();

// Lida com a criação do professor
// Pré-condição: nenhuma
// Pós-condição: professor criado e inserido no arquivo
void create_professor();

// Função recursiva para mostrar em ordem os professores
// Pré-condição: arquivo aberto para leitura
// Pós-condição: mostra os professores ordenados pelo código
void show_professors_in_order(int currentPosition, FILE *file);

// Lida com a visualização de todos os professores
// Pré-condição: nenhuma
// Pós-condição: mostra todos os professores cadastrados no arquivo
void show_professors();

#endif //ACADEMUS_PROFESSOR_CONTROLLER_H
