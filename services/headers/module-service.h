//
// Created by vinniciusj on 15/09/23.
//
#include <stdio.h>

#include "../../models/module.h"
#include "../../models/status.h"

#ifndef ACADEMUS_MODULE_SERVICE_H
#define ACADEMUS_MODULE_SERVICE_H

// Insere um value no arquivo lista
// Pré-condição: um novo módulo e um arquivo aberto para escrita
// Pós-condição: módulo salvo no arquivo lista
Status * insert_module(Module module, FILE * file);

// Retira um módulo do arquivo lista
// Pré-condição: arquivo aberto para escrita e deve ser um arquivo lista
// Pós-condição: módulo retirado da lista caso pertença a ela
void remove_module(Module module, FILE * file);

ModuleNode * get_module_by_course(int course_code, int start_position, FILE * modules_file, FILE * subjects_file);

Module * get_module_by(int academic_year, int subject_code, FILE * modules_file);

// Valida o módulo e retorna um status da inserção de acordo com o resultado
// Pré-condição: um novo módulo
// Pós-condição: status para a inserção (código 1 para sucesso e 0 para erro)
Status * validate_module(Module module);

#endif //ACADEMUS_MODULE_SERVICE_H
