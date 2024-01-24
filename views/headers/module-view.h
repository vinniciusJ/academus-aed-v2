//
// Created by vinniciusj on 13/09/23.
//
#include "../../models/module.h"
#include "../../models/professor.h"
#include "../../models/subject.h"

#ifndef ACADEMUS_MODULE_VIEW_H
#define ACADEMUS_MODULE_VIEW_H

// Imprime o menu o cabeçalho do menu da seção de módulos
// Pré-condição: nenhuma
// Pós-condição: cabeçalho impresso no terminal
void show_module_menu_header();

// Imprime o menu de opções da seção de módulos
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de módulos é impresso no terminal
void show_module_menu();

// Requere do usuário as informações de um módulo e retorna ele
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de módulo é retornado e deve ser desalocado posteriormente
Module * input_module();

// Mostra o cabeçalho da tabela dos módulos
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void show_module_table_header();

void show_module_course(char * course_name);

// Mostra no terminal uma linha que representa um módulos cadastrado, deve ser usada em tabelas
// Pré-condição: módulo
// Pós-condição: módulo é impresso no terminal
void show_module(Module module, Subject subject, Professor professor);

void show_emtpy_table_row();

#endif //ACADEMUS_MODULE_VIEW_H
