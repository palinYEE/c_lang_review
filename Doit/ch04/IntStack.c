#include<stdio.h>
#include<stdlib.h>
#include"IntStack.h"

int Initialize(IntStack *s, int max){
    s->ptr = 0;
    // 스택이 없을 경우 max = 0으로 하고 return -1 으로 한다.
    if((s->stk = calloc(max, sizeof(int)))==NULL){
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x){
    // 스택이 가득 찼을 경우는 return -1
    if(s->ptr >= s->max)
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

int Pop(IntStack *s, int *x){
    if(s->ptr <= 0)
        return -1;
    *x = s->stk[s->ptr--];  // ptr 값이 수정됨
    return 0;
}

int Peek(const IntStack *s, int *x){
    if(s->ptr <= 0)
        return -1;
    *x = s->stk[s->ptr-1];  // ptr 값이 수정안됨
    return 0;
}

int Capacity(const IntStack *s){
    return s->max;
}

int Size(const IntStack *s){
    return s->ptr;
}

int IsEmpty(const IntStack *s){
    return s->ptr <= 0;
}

int IsFull(const IntStack *s){
    return s->ptr >= s->max;
}

int Search(const IntStack *s, int x){
    int i;
    for(i=0; i<s->max; i++){
        if(s->stk[i] == x)
            return i;
    }
    return -1;
}

void Print(const IntStack *s){
    int i;
    for(i=0; i<s->max; i++){
        printf("%d ", s->stk[i]);
    }
    putchar('\n');
}

void Terminate(IntStack *s){
    if(s->stk != NULL)
        free(s->stk);
    s->max = s->ptr = 0;
}