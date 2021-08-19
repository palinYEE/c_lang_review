// 스택 헤더
#ifndef __IntStack
#define __IntStack

typedef struct {
    int max;        // 스택의 최대 용량 (max == len(stk))
    int ptr;        // 스택 포인터, 스택에 쌓여있는 데이터의 개수를 나타내는 맴버.
    int *stk;       // 스택으로 푸시된 데이터를 저장할 용도의 배열을 가리키는 포인터.
}IntStack;

// 스택 초기화
int Initialize(IntStack *s, int max);

// 스택 데이터 푸시
int Push(IntStack *s, int x);

// 스택 데이터 팝
int Pop(IntStack *s, int *x);

// 스택 데이터 피크
int Peek(const IntStack *s, int *x);

// 스택 비우기
void Clear(IntStack *s);

// 스택의 최대 용량 
int Capacity(const IntStack *s);

// 스택이 비어있는지 여부
int IsEmpty(const IntStack *s);

int Size(const IntStack *s);

// 스택이 가득 찼는지 확인
int isFull(const IntStack *s);

// 스택에서 검색
int Search(const IntStack *s, int x);

// 모든 데이터 검색
void Print(const IntStack *s);

// 스택 종료
void Terminate(IntStack *s);

#endif