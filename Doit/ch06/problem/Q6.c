/*
    다음의 배열을 정렬한다고 가정하자.
            9 1 3 4 5 6 7 8
    이 배열은 두 번째 요소부터는 정렬은 되어 있지만 버전 3의 버블 정렬 알고리즘을 사용해도 빠른 시간안에 정렬 작업을 마칠 수는 없습니다.
    왜냐하면 맨 앞에 있는 요소의 값(9)은 1회의 패스를 거쳐도 한 칸만 뒤로 옮겨지기 떄문입니다. 
    그래서 홀수 번째의 패스는 가장 작은 요소를 맨 앞으로 옮기고 짝수 번째 패스는 가장 큰 요소를 맨 뒤로 옮기는 방식을 사용하면 (패스 스캔 방향을 교대로 바꾸면) 이런 정렬을 더 적은 횟수로 비교를 수행할 수 있다. 
    버전 3의 프로그램을 개선하여 양방향 버블 정렬을 수행하는 프로그램을 작성하세요.
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
        if(i % 2 == 1){
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
        }else{
            for(j = i; j < n-1; j++){
                if(a[j] > a[j + 1]){
                    for(k = 0; k<n; k++){
                        printf("%2d", a[k]);
                        if(k == j){
                            printf(" +");
                        }
                    }
                    swap(int, a[j], a[j + 1]);
                    last = j + 1;
                }else{
                    for(k = 0; k<n; k++){
                        printf("%2d", a[k]);
                        if(k == j){
                            printf(" -");
                        }
                    }
                }
                printf("\n");
            }
           
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