//
// Created by lnw on 2021/10/24.
//

#ifndef STACK01_QUEUE_H
#define STACK01_QUEUE_H
#include<stdio.h>
#include <stdlib.h>
#include "ELEMTYPE.h"
typedef struct QUEUE{//尾插，头出
    struct QUEUE *next;
    Elemtype data;
}queue;
typedef struct QUEUE_HEAD{
    queue *head;
    queue *tail;
}queue_head;
int InitQueue(queue_head *Q){
    Q->head = malloc(sizeof (queue));
    if(Q->head == NULL)
        return 0;
    Q->tail = Q->head;
    Q->head->next = NULL;
    return 1;
}
int EnterQueue(queue_head *Q,Elemtype x){//入队
    queue *insert;
    insert = malloc(sizeof (queue));
    insert->data = x;
    insert->next = NULL;
    Q->tail->next = insert;
    Q->tail = insert;
    return 1;
}
int DeleteQueue(queue_head *Q,Elemtype *x){
    queue *deleteData;
    if(Q->head == Q->tail)
        return 0;
    deleteData = Q->head->next;
    *x = deleteData->data;
    Q->head->next = deleteData->next;
    if(Q->tail == deleteData)
        Q->tail = Q->head;
    free(deleteData);
    return 1;
}
int GetHead(queue_head Q,Elemtype *x){
    if(Q.head == Q.tail)
        return 0;
    *x = Q.head->next->data;
    return 1;
}
#endif //STACK01_QUEUE_H
