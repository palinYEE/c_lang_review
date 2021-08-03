/*
    1. recur3 함수를 다시 비재귀적으로 구현하세요. 
    2. 하노이탑을 숫자가 아닌 문자열로 기둥 이름을 출력하도록 프로그램을 수정하시오. 
    3. 하노이탑의 move 함수를 비재귀적으로 수정하시오.
*/
#include<stdio.h>
#include"IntStack.h"

void recur3_pro1(int n){
    IntStack stk;
    Initialize(&stk, 100);

    Top:
    if(n > 0){
        Push(&stk, n);
        n = n-2;
        goto Top;
    }
    if(!IsEmpty(&stk)){
        n = n + 3;
        
    }
}

void move(int no, int x, int y){
    if(no > 1)
        move(no-1, x, 6-x-y);
    printf("원반 [%d]를 %c 기둥에서 %c 기둥으로 옮김 \n", no, x+64, y+64);

    if(no > 1)
        move(no-1, 6-x-y, y);    
}

int main(){
    int n;
    int temp;
    printf("1. recur3 함수를 다시 비재귀적으로 구현하세요. \n");
    printf("  - n 값을 입력하세요 : ");
    scanf("%d", &n);
    
    temp = n;
    recur3(n);
    printf("=============\n");
    temp = n;
    recur3_pro1(n);

    printf("2. 하노이탑을 숫자가 아닌 문자열로 기둥 이름을 출력하도록 프로그램을 수정하시오.\n");
    move(n, 1, 3);
    return 0;
}