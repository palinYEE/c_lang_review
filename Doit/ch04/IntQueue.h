#ifndef __IntQueue
#define __IntQueue

typedef struct 
{
    int max;    // 큐의 최대 용량
    int num;    // 현재의 요소 개수
    int front;  // 프런트
    int rear;   // 리어
    int *que;   // 큐의 맨 앞 요소에에 대한 포인터
}IntQueue;

// 큐 초기화
int Initialize(IntQueue *q, int max);

// 인큐
int Enqueue(IntQueue *q, int x);

// 디큐
int Dequeue(IntQueue *q, int x);

// 피크
int Peek(IntQueue *q, int *x);

// 큐 청소
void Clear(IntQueue *q);

// 큐의 최대 용량
int Capacity(const IntQueue *q);

// 큐에 저장된 데이터 개수
int Size(const IntQueue *q);

// 큐 비어있는지 여부 확인
int Empty(const IntQueue *q);

// 큐가 가득 찼는지 여부 확인
int isFull(const IntQueue *q);

// 검색
int Search(const IntQueue *q, int x);

//모든 데이터 출력
void Print(const IntQueue *q);

// 큐 종료
void Terminate(IntQueue *q);
#endif