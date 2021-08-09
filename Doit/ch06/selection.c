#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void selection(int a[], int n){
    int i, j;

    for(i=0; i<n; i++){
        int min = i;
        for(j = i + 1; j<n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(int, a[i], a[min]);
    }
}

int main(){
    int i, nx;
    int *x;

    puts("단순 선택 정렬");
    printf("요소 개수를 입력하세요. : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    printf("요소 리스트 : ");
    for(i = 0; i<nx; i++){
        scanf("%d", &x[i]);
    }

    selection(x, nx);

    printf("정렬을 완료하였습니다. \n");
    for(i=0; i<nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);
}