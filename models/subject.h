//
// Created by vinniciusj on 13/09/23.
//
#define NAME_LENGTH 50

#ifndef ACADEMUS_MODULES_H
#define ACADEMUS_MODULES_H

typedef struct {
    int code;
    char name[NAME_LENGTH];
    int course_code;
    int year;
} Subject;

typedef struct {
    Subject value;
    int left;
    int right;
} SubjectNode;

#endif //ACADEMUS_MODULES_H
