#include<stdio.h>

int gcd(int x, int y){
    if(y == 0)
        return x;
    else
        return gcd(y, x%y);
}

int main(){
    int x,y;
    puts("최대공약수 프로그램입니다.");
    printf("두 정수를 입력하세요 : ");
    scanf("%d %d", &x, &y);
    printf("최대공약수는 %d 입니다.", gcd(x,y));
    return 0;
}