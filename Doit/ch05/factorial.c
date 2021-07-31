#include<stdio.h>

int factorial(int x){
    if(x > 0){
        return x * factorial(x-1);
    }else{
        return 1;
    }
}

int main(){
    int x;
    printf("자연수를 입력해주세요 : ");
    scanf("%d", &x);
    printf("%d의 순차곱셉 값은 %d입니다. \n", x, factorial(x));
    return 0;
}