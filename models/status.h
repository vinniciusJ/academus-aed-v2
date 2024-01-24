//
// Created by nikoly on 14/10/23.
//
#define MAX_MESSAGE_LENGTH 200

#ifndef ACADEMUS_STATUS_H
#define ACADEMUS_STATUS_H

typedef struct {
    int code;
    char message[MAX_MESSAGE_LENGTH];
} Status;

#endif //ACADEMUS_STATUS_H
