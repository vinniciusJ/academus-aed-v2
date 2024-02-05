//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_MODULE_CONTROLLER_H
#define ACADEMUS_MODULE_CONTROLLER_H

// Inicia a navegação na seção de módulo
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_module_router();

// Lida com a criação de um módulo
// Pré-condição: nenhuma
// Pós-condição: módulo criado e inserido no arquivo
void create_module();

// Lida com a visualização de todos os módulos
// Pré-condição: nenhuma
// Pós-condição: mostra todos os módulos cadastrados no arquivo
void show_modules();

void delete_module();

void show_module_codes_by_layer();

// Mostra as posições livres dos modulos
// Pré-condição: nenhuma
// Pós-condição: Mostra a lista de posições
void show_free_positions();

#endif //ACADEMUS_MODULE_CONTROLLER_H
