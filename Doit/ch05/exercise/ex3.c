/*
1. 실습 5-9의 print 함수를 수정하여 전각 기호 □ ■ 를 사용해 퀸의 배치 상황을 출력하시오.
2. 8퀸 문제를 비재귀적으로 구현한 프로그램을 작성하세요
*/
#include<stdio.h>

int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];

void print(){
    int i;
    for(i=0; i<8; i++){
        printf("%d ", pos[i]);
    }
    printf("\n");
}

void print_pro(){
    int i, j;

    for(j=0; j<8; j++){
        for(i=0; i<8; i++){
            if(pos[i] == j){
                printf("■ ");
            }
            else{
                printf("□ ");
            }
        }
        printf("\n");
    }
    printf("========================\n");
}

void set(int i){
    int j;
    for(j=0; j<8; j++){
        if(!flag_a[j] && !flag_b[i + j] && !flag_c[i-j + 7]){
            pos[i] = j;
            if(i == 7)
                print_pro();
            else{
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
                set(i + 1);
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
            }
        }
    }
}

int main(){
    int i;
    for(i=0; i<8; i++){
        flag_a[i] = 0;
    }
    for(i=0; i<15; i++){
        flag_b[i] = flag_c[i] = 0;
    }
    printf("1. 실습 5-9의 print 함수를 수정하여 전각 기호 □ ■ 를 사용해 퀸의 배치 상황을 출력하시오.\n");
    set(0);

    return 0;
}