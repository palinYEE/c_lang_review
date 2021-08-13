#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void quick(int a[], int left, int right){
    int i;
    int pl = left;
    int pr = right;
    int pivot = a[(pl + pr) / 2];

    do{
        while(a[pl] < pivot) pl++;
        while(a[pr] > pivot) pr--;
        if(pl <= pr){
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    }while(pl <= pr);
    if(left < pr) quick(a, left, pr);
    if(pl < right) quick(a, pl, right);
}

int main(){
    int i, nx;
    int *x;

    printf("Quick Sort\n");
    printf("요소의 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));
    printf("요소를 입력하세요 : ");
    for(i=0; i<nx; i++){
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx-1);

    printf("오름차순으로 정렬하였습니다. : ");
    for(i=0; i<nx; i++){
        printf("%d ", x[i]);
    }

    free(x);
    return 0;
}