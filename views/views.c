//
// Created by vinniciusj on 13/09/23.
//
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "stdio.h"
#include "headers/views.h"

// Escaneia um valor inteiro pelo terminal informado pelo usuário
// Pré-condição: nenhuma
// Pós-condição: retorna o valor digitado pelo usuário
int input_option(){
    int option = 0;

    printf("Escolha uma opção das listadas acima: ");
    scanf("%d%*c", &option);
    printf("\n");

    return option;
}

// Imprime uma mensagem de erro para uma opção inválida
// Pré-condição: nenhuma
// Pós-condição: mensagem de erro impressa no terminal
void show_invalid_option_message(){
    printf("Opção inválida, informe uma opção valida!\n\n5");
}

// Imprime uma mensagem de sucesso recebida por parâmetro
// Pré-condição: nenhuma
// Pós-condição: mensagem de sucesso impressa no terminal em verde
void show_sucess_message(char * message) {
    printf("\n\033[1;32m  %s \033[1;0m\n\n", message);
}

// Imprime uma mensagem de erro recebida por parâmetro
// Pré-condição: nenhuma
// Pós-condição: mensagem de erro impressa no terminal em vermelho
void show_error_message(char * message) {
    printf("\n\033[31m %s \033[1;0m\n\n", message);
}

char * get_knowledge_area(char code){
    switch (code) {
        case 'E':
            return "Exatas";
        case 'B':
            return "Biológicas";
        case 'H':
            return "Humanas";
        default:
            return "";
    }
}

// Imprime uma mensagem de alerta com a cor amarela
// Pré-condição: uma mensagem de alerta
// Pós-condição: mensagem impressa no terminal
void show_alert(char * alert){
    printf("\033[1;33m\u26A0 %s\033[0m\n", alert);

    wait_to_continue();
}

void wait_to_continue(){
    int c;

    printf("\nPressione 'Enter' para continuar...");

    fflush(stdout);

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);

    system("clear");
}

int input_number(char * label){
    int number = 0;

    printf("%s: ", label);
    scanf("%d%*c", &number);

    return number;
}

int confirm_action(char * label){
    char action;

    printf("%s [y/n]: ", label);
    scanf("%c%*c", &action);

    return toupper(action) == 'Y';
}

// Diz se o código é válido
// Pré-condição: inteiro
// Pós-condição: inteiro validado
int is_valid_natural(int code) {
    if(code < 0) {
        show_error_message("Valor inválido! Por favor, digite novamente.");
        return 0;
    }
    return 1;
}

// Diz se a string ultrapassou o tamanho máximo
// Pré-condição: string e máximo de caracters
// Pós-condição: string validada
int is_valid_string(char * str, int max) {
    if (strlen(str) > max) {
        //show_error_message("A string digitada ultrapassa o tamanho máximo permitido! Por favor, digite novamente.");
        return 0;
    }
    return 1;
}

char * input_string(char * label){
    char * aux = NULL;

    printf("%s: ", label);
    scanf("%[^\n]%*c", aux);

    char * value = (char *) malloc(strlen(aux));

    strcpy(value, aux);

    return value;
}