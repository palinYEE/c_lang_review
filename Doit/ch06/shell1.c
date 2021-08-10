#include<stdio.h>
#include<stdlib.h>

void shell(int a[], int n){
    int i, j, h;
    for(h = n/2; h > 0; h /= 2){
        for(i = h; i < n; i++){
            int tmp = a[i];
            for(j = i - h; j >=0 && a[j] > tmp; j -= h){
                a[j + h] = a[j];
            }
            a[j + h] = tmp;
        }
    }
}

int main(){
    int i, nx;
    int *x;

    puts("셸 정렬");
    printf("요소 개수를 입력하세요. : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    printf("요소 리스트 : ");
    for(i = 0; i<nx; i++){
        scanf("%d", &x[i]);
    }

    shell(x, nx);

    printf("정렬을 완료하였습니다. \n");
    for(i=0; i<nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);
}