#include<stdio.h>
#include"yyjIntQueue.h"

int main(){
    IntQueue q;

    if(Initialize(&q, 64) == -1){
        return 0;
    }

    while(1){
        int menu, input, output;
        printf("(1) Enqueue (2) Dequeue (3) Print : ");
        scanf("%d", &menu);
        if(menu == 0) break;
        switch (menu)
        {
        case 1:
            printf("넣을 데이터를 입력하세요. : ");
            scanf("%d", &input);
            if(Enqueue(&q, input) == -1){
                printf("\a오류 : 인큐에 실패하였습니다. \n");
                return 0;
            };
            break;
        case 2:
            output = Dequeue(&q);
            if(output == -1){
                printf("\a오류 : 디큐에 실패하였습니다. \n");
                return 0;
            }
            printf("디큐한 데이터는 %d 입니다.\n", output);
            break;
        case 3:
            Print(&q);
        default:
            break;
        }
    }
}