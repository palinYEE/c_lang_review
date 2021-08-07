/*
    버블 정렬의 각 패스에서 비교, 교환은 처음(왼쪽)부터 수행해도 됩니다. (각 패스에서 가장 큰 값의 요소가 끝으로 옮겨집니다.)
    그렇게 수정한 프로그램을 작성하시오.
*/
#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do{ type t = x; x = y; y = t;} while(0)

void print(int a[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble(int a[], int n){
    int i, j;

    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){     // 맨 마지막을 고정해야되기 때문에 n-1-i로 설정
            if(a[j] > a[j + 1]){
                swap(int, a[j], a[j + 1]);
            }
            print(a, n);
        }
    }

}

int main(){
    int i, nx;
    int *x;

    puts("Q1. 버블 정렬의 각 패스에서 비교, 교환은 처음(왼쪽)부터 수행해도 됩니다. (각 패스에서 가장 큰 값의 요소가 끝으로 옮겨집니다.) 그렇게 수정한 프로그램을 작성하시오.");
    printf("요소 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for(i=0; i<nx; i++){
        scanf("%d", x + i);
    }

    bubble(x, nx);

    puts("오름차순으로 정렬했습니다.");
    print(x, nx);

    free(x);
    return 0;
}