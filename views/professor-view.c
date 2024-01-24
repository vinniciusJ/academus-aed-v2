//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>
#include "headers/professor-view.h"
#include "../models/professor.h"
#include "../utils/headers/utils.h"
#include "headers/views.h"

// Imprime o menu de opções da seção de professores
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de professores é impresso no terminal
void show_professor_menu(){
    printf("+------------------------SISTEMA ACADEMUS------------------------+\n");
    printf("|----------------------Seção de professores----------------------|\n");
    printf("|[0] Voltar                                                      |\n");
    printf("|[1] Cadastrar professor(a)                                      |\n");
    printf("|[2] Listar todos os professores(as)                             |\n");
    printf("+----------------------------------------------------------------+\n");
}

// Requere do usuário as informações de um professor e retorna ele
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de professor é retornado e deve ser desalocado posteriormente
Professor * input_professor(){
    printf("------------------------SISTEMA ACADEMUS--------------------------\n");
    printf("-----------------------Cadastro de professor(a)-------------------------\n\n");

    Professor * professor = (Professor *) alloc(sizeof(Professor));

    do {
        printf("Digite o código do professor(a): ");
        scanf("%d%*c", &professor->code);
    } while(!is_valid_natural(professor->code));

    printf("Digite o nome do professor(a) (até %d caracteres): ", NAME_LENGTH);
    scanf("%[^\n]%*c", professor->name);

    system("clear");
    return professor;
}


// Mostra o cabeçalho da tabela dos cursos
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void show_professor_table_header(){
    printf("+-------------------------------------------------------------+\n");
    printf("| %-10s| %-49s|\n", "Código", "Nome");
    printf("|----------|--------------------------------------------------|\n");
}

// Mostra no terminal uma linha que representa um professor cadastrado, deve ser usada em tabelas
// Pré-condição: professor
// Pós-condição: professor é mostrado em tela
void show_professor(Professor professor){
    printf("| %9d| %-49s|\n", professor.code, professor.name);
    printf("|----------|--------------------------------------------------|\n");
}