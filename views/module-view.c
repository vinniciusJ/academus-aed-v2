//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "../utils/headers/utils.h"
#include "./headers/module-view.h"
#include "headers/views.h"
#include "../models/header.h"

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
    printf("|[2] Listar módulos                                              |\n");
    printf("|[3] Listar códigos por camada                                   |\n");
    printf("|[4] Remover módulo                                              |\n");
    printf("|[5] Imprimir posições livres                                    |\n");
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

    //system("clear");

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
    printf("| %10s| %10s| %-10s| %18s| %-49s| %-49s|\n", "Cod", "Ano letivo", "Série", "Cod. Disciplina", "Disciplina", "Professor");
    printf("|-----------|-----------|----------|-------------------|--------------------------------------------------|--------------------------------------------------|\n");
}

// Mostra no terminal uma linha que representa um módulos cadastrado, deve ser usada em tabelas
// Pré-condição: módulo
// Pós-condição: módulo é impresso no terminal
void show_module(Module module, Subject subject, Professor professor){
    printf("| %10s| %9d| %10d| %18d| %-49s| %-49s|\n", concatenate_integers(module.academic_year, module.subject_code), module.academic_year, subject.year, subject.code, subject.name, professor.name);
    printf("|-----------|-----------|----------|-------------------|--------------------------------------------------|--------------------------------------------------|\n");
}

// Mostra as posições que estão livres no arquivo
// Pré-condição: cabeçalho
// Pós-condição: lista é impressa no terminal
void show_free_positions(Header * header) {
    printf(""
           "Posições Livres:\n");

    for (int i = 0; i < header->num_free_positions; i++) {
        printf("%d -> ", header->free_positions[i]);
    }

    printf("NULL");

    printf("\nTotal: %d\n", header->num_free_positions);
    wait_to_continue();

}