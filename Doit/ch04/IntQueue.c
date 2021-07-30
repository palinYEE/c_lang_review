#include<stdio.h>
#include<stdlib.h>
#include"IntQueue.h"

// 큐 초기화
int Initialize(IntQueue *q, int max){
    q->num = q->front = q->rear = 0;
    if((q->que = calloc(max, sizeof(int))) == NULL){
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

// 인큐
int Enqueue(IntQueue *q, int x){
    if(q->num >= q->max){
        return -1;
    }
    else{
        q->num++;
        q->que[q->rear++] = x;
        if(q->rear == q->max){
            q->rear = 0;
        }
        return 0;
    }
}

// 디큐
int Dequeue(IntQueue *q, int *x){
    if(q->num <= 0){
        return -1;
    }
    else{
        q->num--;
        *x = q->que[q->front++];
        if(q->front == q->max){
            q->front = 0;
        }
        return 0;
    }
}

// 피크
int Peek(IntQueue *q, int *x){
    if(q->num <= 0){
        return -1; 
    }
    else{
        *x = q->que[q->front];
        return 0;
    }
}

// 큐 청소
void Clear(IntQueue *q){
    q->max = q->front = q->num = q->rear = 0;
}

// 큐의 최대 용량
int Capacity(const IntQueue *q){
    return q->max;
}

// 큐에 저장된 데이터 개수
int Size(const IntQueue *q){
    return q->num;
}

// 큐 비어있는지 여부 확인
int Empty(const IntQueue *q){
    return q->num <= 0;
}

// 큐가 가득 찼는지 여부 확인
int isFull(const IntQueue *q){
    return q->num >= q->max;
}

// 검색
int Search(const IntQueue *q, int x){
    int i, idx;
    for(i=0; i<q->num; i++){
        idx = (i + q->front) % q->max;
        if(q->que[idx] == x)
            return idx;
    }
    return -1;
}

//모든 데이터 출력
void Print(const IntQueue *q){
    int i, idx; 
    for(i=0; i<q->num; i++){
        idx = (i + q->front) % q->max;
        printf("%d ", q->que[idx]);
    }
    printf("\n");
}

// 큐 종료
void Terminate(IntQueue *q){
    if(q->que != NULL){
        free(q->que);
    }
    q->max = q->front = q->num = q->rear = 0;
}
