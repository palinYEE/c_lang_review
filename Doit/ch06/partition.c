#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void partition(int a[], int n){
    int i;
    int pl = 0;         // 왼쪽 커서
    int pr = n-1;       // 오른쪽 커서
    int pivot = a[n/2]; // 피벗 값 (피벗 값을 중간으로 셋팅) 

    do{
        while(a[pl] < pivot) pl++;
        while(a[pr] > pivot) pr--;
        
        if(pl <= pr){
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    }while(pl <= pr);

    printf("pivot : %d\n", pivot);
    printf("pivot 값보다 작은 그룹\n");
    for(i = 0; i<=pl; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    if(pl > pr+1){
        printf("pivot 과 일치하는 그룹\n");
        for(i = pr + 1; i <= pl - 1; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    printf("pivot 이상의 그룹\n");
    for(i = pr + 1; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int i, nx;
    int *x;

    printf("배열을 나눕니다.\n");
    printf("요소의 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for(i = 0; i<nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    partition(x, nx);

    free(x);
    return 0;
}