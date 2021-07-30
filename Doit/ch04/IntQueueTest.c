#include<stdio.h>
#include"IntQueue.h"

int main(){
    IntQueue que;

    if(Initialize(&que, 64) == -1){
        puts("\a오류 : 큐 생성에 실패하였습니다. ");
        return 1;
    }

    while(1){
        int m, x;

        printf("현재 데이터 수 %d / %d \n", Size(&que), Capacity(&que));
        printf("(1)인큐 (2)디큐 (3)피크 (4)출력 : ");
        scanf("%d", &m);

        switch (m){
        case 1:
            printf("데이터 : ");
            scanf("%d", &x);
            if(Enqueue(&que, x) == -1){
                puts("\a오류 : 인큐에 실패하였습니다.");
            }
            break;
        
        case 2: 
            if(Dequeue(&que, &x) == -1){
                puts("\a오류 : 디큐에 실패하였습니다.");
            }
            else{
                printf("디큐한 데이터는 %d 입니다.\n", x);
            }
            break;

        case 3:
            if(Peek(&que, &x) == -1){
                puts("\a오루 : 피크에 실패하였습니다.");
            }
            else{
                printf("피크한 데이터는 %d 입니다. \n", x);
            }
            break;
        case 4:
            Print(&que);
            break;
        }
    }
    Terminate(&que);
    return 0;
}