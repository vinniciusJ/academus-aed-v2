//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "../utils/headers/utils.h"
#include "./headers/module-view.h"
#include "headers/views.h"

// Imprime o menu o cabeçalho do menu da seção de módulos
// Pré-condição: nenhuma
// Pós-condição: cabeçalho impresso no terminal
void show_module_menu_header(){
    printf("+------------------------SISTEMA ACADEMUS------------------------+\n");
    printf("|------------------------Seção de módulos------------------------|\n");
}

// Imprime o menu de opções da seção de módulos
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de módulos é impresso no terminal
void show_module_menu(){
    show_module_menu_header();

    printf("|[0] Voltar                                                      |\n");
    printf("|[1] Cadastrar módulo                                            |\n");
    printf("|[2] Listar módulos por curso                                    |\n");
    printf("|[3] Remover módulo                                              |\n");
    printf("+----------------------------------------------------------------+\n");
}

// Requere do usuário as informações de um módulo e retorna ele
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de módulo é retornado e deve ser desalocado posteriormente
Module * input_module(){
    show_module_menu_header();

    Module * module = (Module *) alloc(sizeof(Module));

    do {
        printf("Digite o ano letivo: ");
        scanf("%d%*c", &module->academic_year);
    } while(!is_valid_natural(module->academic_year));

    do {
        printf("Digite o código da disciplina: ");
        scanf("%d%*c", &module->subject_code);
    } while(!is_valid_natural(module->subject_code));

    do {
        printf("Digite o código do professor: ");
        scanf("%d%*c", &module->professor_code);
    } while(!is_valid_natural(module->professor_code));

    system("clear");

    return module;
}

void show_module_course(char * course_name){
    printf("\n+----------------------------------------------------------------------------------------------------------------------------+\n");
    printf("| Curso: %-115s |\n", course_name);
    printf("+--------------------------------------------------------------------------------------------------------------------+-------+\n");
}

// Mostra o cabeçalho da tabela dos módulos
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void show_module_table_header(){
    printf("| %10s| %-10s| %-49s| %-49s|\n", "Ano letivo", "Série", "Disciplina", "Professor");
    printf("|-----------|----------|--------------------------------------------------|--------------------------------------------------|\n");
}

// Mostra no terminal uma linha que representa um módulos cadastrado, deve ser usada em tabelas
// Pré-condição: módulo
// Pós-condição: módulo é impresso no terminal
void show_module(Module module, Subject subject, Professor professor){
    printf("| %10d| %9d| %-49s| %-49s|\n", module.academic_year, subject.year, subject.name, professor.name);
    printf("|-----------|----------|--------------------------------------------------|--------------------------------------------------|\n");
}

void show_emtpy_table_row(){
    printf("| %-122s |\n", "Nenhum registro encontrado");
    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
}
