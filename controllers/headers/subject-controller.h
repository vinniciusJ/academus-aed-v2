//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_SUBJECT_CONTROLLER_H
#define ACADEMUS_SUBJECT_CONTROLLER_H

// Inicia a navegação na seção de disciplina
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_subject_router();

// Lida com a criação de disciplina
// Pré-condição: nenhuma
// Pós-condição: disciplina criada e inserido no arquivo
void create_subject();

// Lida com a visualização de todos as matérias
// Pré-condição: nenhuma
// Pós-condição: mostra todos as matérias cadastradas no arquivo
void show_subjects();

#endif //ACADEMUS_SUBJECT_CONTROLLER_H
