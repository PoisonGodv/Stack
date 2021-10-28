//
// Created by lnw on 2021/10/24.
//

#ifndef STACK01_SEQUENCESTACK_H
#define STACK01_SEQUENCESTACK_H
#define SSTACK_LENGTH 1
#include "ELEMTYPE.h"
typedef struct SEQUENCESTACK{
    Elemtype data[SSTACK_LENGTH];
    int top;
}sequencestack;
int InitSStack(sequencestack *S){
    S->top = -1;
    return 1;
}
int SIsFull(sequencestack S){//栈满用0，空用1
    if(S.top >= SSTACK_LENGTH-1)
        return 0;
    return 1;
}
int SIsEmpty(sequencestack S){
    return (S.top == -1?1:0);//栈空用1，满用0
}
int SPush(sequencestack *S,Elemtype x){
    if(SIsFull(*S)==0)
        return 0;//栈满
    S->top++;
    S->data[S->top] = x;
    return 1;
}

int SPop(sequencestack *S,Elemtype *x){
    if(SIsEmpty(*S)==1)
        return 0;
    *x = S->data[S->top];
    S->data[S->top].carNumber = 0;
    S->top--;
    return 1;
}
int SGetTop(sequencestack *S,Elemtype *x){
    if(SIsEmpty(*S) == 1)
        return 0;
    *x = S->data[S->top];
    return 1;
}
#endif //STACK01_SEQUENCESTACK_H
