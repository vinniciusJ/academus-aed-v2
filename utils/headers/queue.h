//
// Created by vinniciusj on 01/02/24.
//

#include <stdlib.h>
#include "../../models/module.h"

#ifndef ACADEMUS_QUEUE_H
#define ACADEMUS_QUEUE_H

typedef struct QueueNode {
    ModuleNode * value;
    struct QueueNode * next;
} QueueNode;

typedef struct  {
    struct QueueNode * front;
    struct QueueNode * rear;
} Queue;

Queue * create_queue();
int is_queue_empty(Queue * queue);
void enqueue(ModuleNode * value, Queue * queue);
ModuleNode * dequeue(Queue * queue);
void clean_queue(Queue * queue);

#endif //ACADEMUS_QUEUE_H
