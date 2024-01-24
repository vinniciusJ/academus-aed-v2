//
// Created by vinniciusj on 13/09/23.
//
#define NAME_LENGTH 50

#ifndef ACADEMUS_PROFESSOR_H
#define ACADEMUS_PROFESSOR_H

typedef struct {
    int code;
    char name[NAME_LENGTH];
} Professor;

typedef struct {
    Professor value;
    int left;
    int right;
} ProfessorNode;

#endif //ACADEMUS_PROFESSOR_H
