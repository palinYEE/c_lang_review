/*
    오른쪽처럼 비교, 교환 과정을 자세히 츨력하며넛 버블 정렬하는 브로그램을 작성하세요. 
    비교하는 두 요소 시이에 교환을 수행하면 '+'
    수행하지 않으면 '-'를 출력하고 정렬을 마치면 비교 횟수와 교횐 횟수를 출력하세요.
*/
#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do{ type t = x; x = y; y = t; }while(0)

void bubbble(int a[], int n, int *compareNum, int *swapNum);

int main(){
    int i, nx;
    int compareNum, swapNum;
    int *x;

    printf("요소 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for(i=0; i<nx; i++){
        scanf("%d", x + i);
    }

    bubbble(x, nx, &compareNum, &swapNum);

    printf("===============\n");
    printf("[*] 비교 횟수 : %d\n", compareNum);
    printf("[*] 교환 횟수 : %d", swapNum);
}

void bubbble(int a[], int n, int *compareNum, int *swapNum){
    int i, j, k;
    
    *compareNum = 0;
    *swapNum = 0;

    for(i=0; i<n-1; i++){
        for(j=n-1; j>i; j--){
            *compareNum += 1;
            if(a[j] < a[j-1]){
                for(k=0; k<n; k++){
                    printf("%2d", a[k]);
                    if(k == j-1)
                        printf(" +");
                }
                swap(int, a[j-1], a[j]);
                *swapNum += 1;
            }
            else{
                for(k=0; k<n; k++){
                    printf("%2d", a[k]);
                    if(k == j-1)
                        printf(" -");
                }
            }
            printf("\n");
        }
        
    }    
}