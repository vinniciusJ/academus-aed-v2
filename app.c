//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>
#include <stdlib.h>

#include "app.h"
#include "controllers/headers/course-controller.h"
#include "controllers/headers/subject-controller.h"
#include "controllers/headers/professor-controller.h"
#include "controllers/headers/module-controller.h"
#include "controllers/headers/controller.h"
#include "views/headers/views.h"

// Imprime o menu de opções no terminal
// Pré-condição: nenhuma
// Pós-condição: o menu é impresso no terminal
void show_menu(){
    printf("+------------------------SISTEMA ACADEMUS------------------------+\n");
    printf("|[0] - Sair do sistema                                           |\n");
    printf("|[1] - Ir para a seção de cursos                                 |\n");
    printf("|[2] - Ir para a seção de disciplinas                            |\n");
    printf("|[3] - Ir para a seção de professores                            |\n");
    printf("|[4] - Ir para a seção de módulos                                |\n");
    printf("|[5] - Importar dados em lote                                    |\n");
    printf("+----------------------------------------------------------------+\n");
}

// Inicia a navegação do sistema e redireciona para o recurso solicitado
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado
void start_app_router(){
    system("clear");
    int option = 0;

    show_menu();
    option = input_option();

    system("clear");

    switch (option) {
        case 0:
            exit(EXIT_SUCCESS);
        case 1:
            start_course_controller();
            break;
        case 2:
            start_subject_router();
            break;
        case 3:
            start_professor_router();
            break;
        case 4:
            start_module_router();
            break;
        case 5:
            create_in_batch();
            break;
        default:
            show_invalid_option_message();
            wait_to_continue();
            start_app_router();
    }

    wait_to_continue();
    start_app_router();
}