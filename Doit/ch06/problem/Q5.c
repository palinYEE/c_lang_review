/*
    연습문제 Q2와 마찬가지로 비교, 교환 과정을 자세히 출력하는 프로그램으로 수정하시오
*/
#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void bubble(int a[], int n){
    int i = 0;
    int k;

    while(i < n-1){
        int j; 
        int last = n-1; 
        for(j = n-1; j>i; j--){
            if(a[j-1] > a[j]){
                for(k = 0; k<n; k++){
                    printf("%2d", a[k]);
                    if(k == j-1){
                        printf(" +");
                    }
                }
                swap(int, a[j-1], a[j]);
                last = j;
            }else{
                for(k = 0; k<n; k++){
                    printf("%2d", a[k]);
                    if(k == j-1){
                        printf(" -");
                    }
                }
            }
            printf("\n");
        }
        i = last;
    }
}

int main(){
    int i, nx;
    int *x;

    puts("버블 정렬");
    printf("원소 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for(i=0; i<nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);

    puts("오름차순으로 정렬했습니다.");
    for(i=0; i<nx; i++){
        printf("x[%d] : %d\n", i, x[i]);
    }
    free(x);
    return 0;
}