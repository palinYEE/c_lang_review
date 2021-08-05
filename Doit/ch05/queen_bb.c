// 각 행에 퀸을 1개만 배치한다.
#include<stdio.h>

int flag[8];
int pos[8];

void print(){
    int i;
    for(i=0; i<8; i++){
        printf("%2d ", pos[i]);
    }
    printf("\n");
}

void set(int i){
    int j;
    for(j=0; j<8; j++){
        if(!(flag[j])){     // 퀸이 해당 행에 배치되지 않았다면.
            pos[i] = j;
            if(i == 7)
                print();
            else{
                flag[j] = 1;    
                set(i + 1);
                flag[j] = 0;
            }
        }
    }
}

int main(){
    int i;
    for(i = 0; i<8; i++){
        flag[i] = 0;
    }
    set(0);
    return 0;
}