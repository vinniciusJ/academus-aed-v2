//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_MODULE_H
#define ACADEMUS_MODULE_H

// Entidade que assoia cada professor às disciplinas que ele ministra em cada ano letivo
typedef struct {
    int subject_code;
    int professor_code;
    int academic_year;
    char * code;
} Module;

typedef struct {
    Module value;
    int left;
    int right;
} ModuleNode;

#endif //ACADEMUS_MODULE_H
