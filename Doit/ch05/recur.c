#include<stdio.h>
#include "IntStack.h"

void recur(int n){
    if(n>0){
        recur(n-1);
        printf("%d\n", n);
        recur(n-2);
    }
}

// 꼬리 함수 제거
void recur2(int n){
    Top:
        if(n>0){
            recur(n-1);
            printf("%d\n", n);
            n = n-2;
            goto Top;
        }
}

void recurStack(int n){
    IntStack stk;
    Initialize(&stk, 100);

    Top:
    if(n > 0){
        Push(&stk, n);
        n = n-1; 
        goto Top;
    }
    if(!IsEmpty(&stk)){
        Pop(&stk, &n);
        printf("%d\n", n);
        n = n - 2;
        goto Top;
    }
    
    Terminate(&stk);
}

int main(){
    int x;
    printf("정수를 입력하세요. : ");
    scanf("%d", &x);
    // recur(x);
    // recur2(x);
    recurStack(x);
    return 0;
}