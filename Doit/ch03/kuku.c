#include<stdio.h>

int sum(int a, int b){
    return a + b;
}

int mul(int a, int b){
    return a * b;
}

void kuku(int(*calc)(int, int)){
    int i, j;
    for(i=1; i<=9; i++){
        for(j=1; j<=9; j++)
            printf("%3d", (*calc)(i, j));
        putchar('\n');
    }
}

int main(){
    puts("덧셈 테이불");
    kuku(sum);
    puts("\n곱셈 테이블");
    kuku(mul);

    return 0;
}