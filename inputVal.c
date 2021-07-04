#include<stdio.h>

int main(){
    int num1, num2, sum;

    printf("1번째 숫자를 입력하세요 : ");
    scanf("%d", &num1);

    printf("2번째 숫자를 입력하세요 : ");
    scanf("%d", &num2);

    sum = num1 + num2;
    printf("합 : %d, 평균 : %lf\n", sum, sum/2.0);
}