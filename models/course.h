//
// Created by vinniciusj on 13/09/23.
//

#define MAX_NAME_LENGTH 50

#ifndef ACADEMUS_COURSE_H
#define ACADEMUS_COURSE_H

typedef struct {
    int code;
    char name[MAX_NAME_LENGTH];
    char area; // E (Exatas) | H (Humanas) | B (Biológicas)
} Course;

typedef struct {
    Course value;
    int left;
    int right;
} CourseNode;

#endif //ACADEMUS_COURSE_H
