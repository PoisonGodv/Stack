//
// Created by lnw on 2021/10/24.
//

#ifndef STACK01_STACK_H
#define STACK01_STACK_H
#include <stdlib.h>
#include <stdio.h>
#include "ELEMTYPE.h"
typedef struct Stack{//链栈，头插法，从头入栈，出栈，头指针相当于栈顶指针
    Elemtype data;
    struct Stack *next;
}stack,*linkstack;
int InitStack(linkstack *S){//将一个没有初始化的栈初始化为空
    *S = (stack*)malloc(sizeof (stack));
    (*S)->next = NULL;
    return 1;
}
int ClearStack(linkstack *S){
    linkstack clear;
    while (!S){
        clear = *S;
        (*S) = (*S)->next;
        free(clear);
    }
    return 1;
}
int Push(linkstack *S,Elemtype x){
    linkstack newInsert;
    newInsert = malloc(sizeof (stack));
    if(!newInsert)
        return 0;
    newInsert->data = x;
    newInsert->next = (*S)->next;
    (*S)->next = newInsert;
    return 1;
}
int Pop(linkstack *S,Elemtype *x){//出栈，用x带回
    linkstack returnData;
    if((*S)->next!=NULL){
        returnData = (*S)->next;
        *x = returnData->data;
        (*S)->next = (*S)->next->next;
        free(returnData);
        return 1;
    }
    return 0;
}
int LinkStackIsEmpty(linkstack S){
    if(S->next == NULL)
        return 1;//为空
    return 0;//非空
}

#endif //STACK01_STACK_H
