//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_SUBJECT_VIEW_H
#define ACADEMUS_SUBJECT_VIEW_H

#include "../../models/subject.h"
#include "../../models/course.h"

// Imprime o menu de opções da seção de disciplinas
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de disciplinas é impresso no terminal
void show_subject_menu();

// Requere do usuário as informações de uma disciplina e retorna ela
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de disciplina é retornado e deve ser desalocado posteriormente
Subject * input_subject();

// Mostra no terminal uma linha que representa uma matéria cadastrada, deve ser usada em tabelas
// Pré-condição: matéria
// Pós-condição: matéria é mostrado em tela
void show_subject(Subject subject, Course course);

// Mostra o cabeçalho da tabela das matérias
// Pré-condição: nenhuma
// Pós-condição: Cabeçalho mostrado, portanto as linhas devem vir a seguir
void show_subject_table_header();

#endif //ACADEMUS_SUBJECT_VIEW_H
