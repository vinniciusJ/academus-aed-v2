//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "headers/course-view.h"
#include "../models/course.h"
#include "../utils/headers/utils.h"
#include "headers/views.h"

// Imprime o menu de opções da seção de cursos
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção é impresso no terminal
void show_course_menu(){
    printf("+------------------------SISTEMA ACADEMUS------------------------+\n");
    printf("|------------------------Seção de cursos-------------------------|\n");
    printf("|[0] Voltar                                                      |\n");
    printf("|[1] Cadastrar curso                                             |\n");
    printf("|[2] Listar todos os cursos                                      |\n");
    printf("+----------------------------------------------------------------+\n");
}

// Requere do usuário as informações de um curso e retorna ele
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de curso é retornado e deve ser desalocado posteriormente
Course * input_course(){
    printf("------------------------SISTEMA ACADEMUS--------------------------\n");
    printf("-----------------------Cadastro de cursos-------------------------\n\n");

    Course * course = (Course *) alloc(sizeof(Course));

    do {
        printf("Digite o código do curso: ");
        scanf("%d%*c", &course->code);
    } while(!is_valid_natural(course->code));

    do {
        printf("\nDigite o nome do curso (até %d caracteres): ", MAX_NAME_LENGTH);
        scanf("%[^\n]%*c", course->name);
    } while (!is_valid_string(course->name, MAX_NAME_LENGTH));

    do {
        printf("\n[E] Exatas | [B] Biológicas | [H] Humanas\n");
        printf("Digite a área do curso: ");
        scanf("%c%*c", &course->area);
    } while(!is_valid_area(course->area));

    system("clear");

    return course;
}

// Mostra no terminal uma linha que representa um curso cadastrado, deve ser usada em tabelas
// Pré-condição: curso
// Pós-condição: curso é mostrado em tela
void show_course(Course course){
    printf("| %9d| %-49s| %-10s|\n", course.code, course.name, get_knowledge_area(course.area));
    printf("|----------|--------------------------------------------------|-----------|\n");
}

// Mostra o cabeçalho da tabela dos cursos
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void show_course_table_header() {
    printf("+-------------------------------------------------------------------------+\n");
    printf("| %-10s| %-49s| %-11s|\n", "Código", "Nome", "Área");
    printf("|----------|--------------------------------------------------|-----------|\n");
}

// Mostra o cabeçalho da seção de listagem de cursos
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void show_course_list_heading() {
    printf("------------------------SISTEMA ACADEMUS-----------------------------------\n");
    printf("-----------------------Listagem de cursos----------------------------------\n\n");
}

// Diz se o caracter é uma área válida
// Pré-condição: caracter
// Pós-condição: nenhuma
int is_valid_area(char area) {
    if(area == 'E' || area == 'H' || area == 'B') return 1;
    else {
        show_error_message("Área inválida! Por favor digite novamente");
        return 0;
    }
}