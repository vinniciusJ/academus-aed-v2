//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_PROFESSOR_VIEW_H
#define ACADEMUS_PROFESSOR_VIEW_H

#include "../../models/professor.h"
#include "../../models/module.h"

// Imprime o menu de opções da seção de professores
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de professores é impresso no terminal
void show_professor_menu();

// Requere do usuário as informações de um professor e retorna ele
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de professor é retornado e deve ser desalocado posteriormente
Professor * input_professor();


// Mostra o cabeçalho da tabela dos professores
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void show_professor_table_header();

// Mostra no terminal uma linha que representa um professor cadastrado, deve ser usada em tabelas
// Pré-condição: professor
// Pós-condição: professor é mostrado em tela
void show_professor(Professor professor);

#endif //ACADEMUS_PROFESSOR_VIEW_H
