#include<stdio.h>
#include<stdlib.h>
#include"yyjIntQueue.h"

// 큐 초기화
int Initialize(IntQueue *q, int max){
    q->num = 0;
    q->max = max;

    if((q->que = calloc(max, sizeof(int))) == NULL){
        puts("큐 생성에 실패하였습니다. ");
        return -1;
    }
    return 1;
}

// 인큐
int Enqueue(IntQueue *q, int x){
    if(q->num >= q->max){
        puts("더이상 큐에 데이터를 넣을 수 없습니다. ");
        return -1;
    }
    q->que[q->num] = x;
    q->num++;
    return 1;
}

// 디큐
int Dequeue(IntQueue *q){
    int value, i;

    if(q->num < 0){
        puts("큐에 데이터가 남아있지 않습니다. ");
        return -1;
    
    }
    value = q->que[0];
    for(i=1; i<q->num; i++){
        q->que[i-1] = q->que[i];
    }
    q->que[i] = 0;
    q->num--;

    return value;
}

// 큐 프린트
void Print(IntQueue *q){
    int i;

    for(i=0; i<q->num; i++){
        printf("%d ", q->que[i]);
    }
    printf("\n");
}
