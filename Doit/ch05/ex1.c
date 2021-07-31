/*
    1. 재귀 함수 호출을 사용하지 않고 factorial 함수를 작성하세요.
    2. 재귀 함수 호출을 사용하지 않고 gcd 함수를 작성하세요.
    3. 배열 a의 모든 요소의 최대공약수를 구하는 다음 함수를 작성하세요.
            int gcd_array(const int a[], int n);
*/
#include<stdio.h>

int factorialEx(int n){
    int i;
    int r = 1;
    for(i=1; i<=n; i++){
        r *= i;
    }
    return r;
}

int gcdEx(int x, int y){
    int temp;
    while(1){
        if(y==0)
            return x;
        else{
            temp = x%y;
            x = y;
            y = temp;
        }
    }
}
int gcd_array(const int a[], int n){
    int temp;
    temp = gcdEx(a[0], a[1]);
    for(int i=1; i<n-1; i++){
        temp = gcdEx(temp, a[i+1]);        
    }
    return temp;
}
int main(){
    int p1, p2_x, p2_y;
    int p3_a[1000], cnt=0;

    printf("1. 재귀 함수 호출을 사용하지 않고 factorial 함수를 작성하세요.\n");
    printf("    자연수 p1 값을 입력하세요 : ");
    scanf("%d", &p1);
    printf("    factorial[%d] = %d\n", p1, factorialEx(p1));

    printf("2. 재귀 함수 호출을 사용하지 않고 gcd 함수를 작성하세요.\n");
    printf("    두 자연수를 입력하세요 : ");
    scanf("%d %d", &p2_x, &p2_y);
    printf("    gcd(%d, %d) = %d\n", p2_x, p2_y, gcdEx(p2_x, p2_y));

    printf("3. 배열 a의 모든 요소의 최대공약수를 구하는 다음 함수를 작성하세요.\n");
    printf("    최대공약수를 구할 수들을 입력하세요 (stop - -1): ");
    while(1){
        scanf("%d", &p3_a[cnt]);
        if(p3_a[cnt]<0){
            break;
        }
        cnt++;
    }
    for(int i=0; i<cnt; i++){
        printf("    %d", p3_a[i]);
    }
    printf("\n    배열의 최대공약수는 %d 입니다.", gcd_array(p3_a, cnt--));
    return 1;
}