#include<stdio.h>

int pos[8];

void print(){
    int i;
    for(i=0; i<8; i++){
        printf("%d ", pos[i]);
    }
    printf("\n");
}

void set(int n){
    int j;
    for(j=0; j<8; j++){
        pos[n] = j;
        if(n == 7)
            print();
        else
            set(n + 1);
    }
}

int main(){
    set(0);
    return 0;
}