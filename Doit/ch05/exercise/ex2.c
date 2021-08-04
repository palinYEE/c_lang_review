/*
    1. recur3 함수를 다시 비재귀적으로 구현하세요. 
    void recur3(int n){
        if(n > 0){
            recur3(n-1);
            recur3(n-2);
            printf("%d\n", n);
        }
    }
    2. 하노이탑을 숫자가 아닌 문자열로 기둥 이름을 출력하도록 프로그램을 수정하시오. 
    3. 하노이탑의 move 함수를 비재귀적으로 수정하시오.
*/
#include<stdio.h>
#include"IntStack.h"

void recur3(int n){
    if(n > 0){
        recur3(n-1);
        recur3(n-2);
        printf("%d ", n);
    }
}

void recur3_prob(int n){
    // 실패
    int temp, temp2;
    IntStack stk;
    IntStack stk2;

    Initialize(&stk, 100);
    Initialize(&stk2, 100);

    Top:
    if(n > 0){
        Push(&stk, n);
        n = n - 1;
        goto Top;
    }
    if(!(IsEmpty(&stk))){
        Pop(&stk, &temp);
        if (temp - 2 <= 0){
            printf("%d ", temp);
            if(!(IsEmpty(&stk2))){
                Pop(&stk2, &temp2);
                printf("%d ", temp2);
            }
        }else{
            Push(&stk2, temp);
        }
        n = temp-2;
        goto Top;
    }

    printf("\n");
    Terminate(&stk);

}

void recur3_web(int n){
    int code = 0;
    IntStack stack, seper;
    Initialize(&stack, 100);
    Initialize(&seper, 100);

    while(1){
        while(code == 0 && n > 0){
            Push(&stack, n--);
            Push(&seper, 1);
        }

        if(!IsEmpty(&stack)){
            Pop(&stack, &n);
            Pop(&seper, &code);
            if(n - 2 >= 1 && code == 1){
                code = 2;
                Push(&stack, n);
                Push(&seper, code);

                n = n-2;
                code = 0;
            }
            else{
                printf("%d ", n);
            }
            continue;
        }
        break;
    }
    printf("\n");
}

void move(int no, int x, int y){
    if(no > 1)
        move(no-1, x, 6-x-y);
    printf("원반 [%d]를 %c 기둥에서 %c 기둥으로 옮김 \n", no, x+64, y+64);

    if(no > 1)
        move(no-1, 6-x-y, y);    
}

void hanoi(int n, int from, int to){
    int sw = 0;
    IntStack nstack, fstack, tstack, sstack;
    Initialize(&nstack, 100);
    Initialize(&fstack, 100);
    Initialize(&tstack, 100);
    Initialize(&sstack, 100);

    while(1){
        while(sw == 0 && n > 1){
            Push(&nstack, n--);
            Push(&fstack, from);
            Push(&tstack, to);
            Push(&sstack, 1);

            to = 6 - from - to;
        }
        printf("원반 [%d]를 %c 기둥에서 %c 기둥으로 옮김 \n", n, from+64, to+64);

        if(n > 1){
            n--;
            sw = 0;
            from = 6 - from - to;
            continue;
        }

        if(IsEmpty(&nstack)){
            break;
        }
        else{
            Pop(&nstack, &n);
            Pop(&fstack, &from);
            Pop(&tstack, &to);
            Pop(&sstack, &sw);
        }
    }
}
int main(){
    int n;
    int temp;
    printf("1. recur3 함수를 다시 비재귀적으로 구현하세요. \n");
    printf("  - n 값을 입력하세요 : ");
    scanf("%d", &n);
    // recur3_prob(n);
    recur3_web(n);
    recur3(n);
    printf("\n");
    printf("2. 하노이탑을 숫자가 아닌 문자열로 기둥 이름을 출력하도록 프로그램을 수정하시오.\n");
    move(n, 1, 3);
    printf("============\n");
    hanoi(n, 1, 3);
    return 0;
}