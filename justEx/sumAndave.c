#include<stdio.h>

int main(){
    int num1, num2, sum;
    double avg;

    num1 = 100;
    num2 = 95;
    sum = num1 + num2;
    avg = sum/2.0;
    printf("합 : %d, 평균 : %lf\n", sum, avg);

    return 0;
}