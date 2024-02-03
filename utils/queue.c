//
// Created by vinniciusj on 01/02/24.
//

#include "headers/queue.h"
#include "headers/utils.h"

#include <stdlib.h>
#include <string.h>

Queue * create_queue(){
    Queue * queue = alloc(sizeof(Queue));

    queue->front = queue->rear = NULL;

    return queue;
}
int is_queue_empty(Queue * queue){
    return queue->front == NULL;
}

void enqueue(ModuleNode * value, Queue * queue){
    QueueNode * node = (QueueNode *) alloc(sizeof(ModuleNode));

    node->value = value;
    node->next = NULL;

    if(is_queue_empty(queue)){
        queue->front = queue->rear = node;
    }
    else{
        queue->rear->next = node;
        queue->rear = node;
    }
}

ModuleNode * dequeue(Queue * queue){
    if(is_queue_empty(queue)){
        return NULL;
    }

    ModuleNode * last_data = queue->front->value;

    QueueNode * aux = queue->front;
    queue->front = queue->front->next;

    if(queue->front == NULL){
        queue->rear = NULL;
    }

    free_space(aux);

    return last_data;
}
void clean_queue(Queue * queue){
    while(is_queue_empty(queue)){
        dequeue(queue);
    }

    free_space(queue);
}


