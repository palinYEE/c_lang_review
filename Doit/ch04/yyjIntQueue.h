#ifndef __yyjIntQueue
#define __yyjIntQueue

typedef struct 
{
    int max;
    int num;
    int *que;
}IntQueue;

// 큐 초기화
int Initialize(IntQueue *q, int max);

// 인큐
int Enqueue(IntQueue *q, int x);

// 디큐
int Dequeue(IntQueue *q);

// 큐 프린트
void Print(IntQueue *q);

#endif