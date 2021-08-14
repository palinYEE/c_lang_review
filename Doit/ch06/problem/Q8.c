/*
    요소의 삽입 과정을 자세하게 출력할 수 있도록 단순 삽입 정렬 프로그램을 수정하세요. 
    ex.
        6 4 8 5 2 9 7
       ^--+
        4 6 8 5 2 9 7
            +
        4 6 8 5 2 9 7
         ^----+
        4 5 6 8 2 9 7
       ^--------+
        --- 이하 생략 ---
    위 처럼 현재 선택한 요소 아래에 기호 +, 
    삽입하는 위치의 요소 아래에 기호 ^,
    그 사이에 기호 -를 출력하세요. 삽입하지 않는(요소의 이동이 필요 없는) 경우에는 선택한 요소 아래에 +만 출력하면 됩니다.
*/
#include<stdio.h>
#include<stdlib.h>

void insertion(int a[], int n){
    int i, j, k;
    for(i=1; i<n; i++){
        int tmp = a[i];

        for(k = 0; k<n; k++){
            printf(" %d", a[k]);
        }
        printf("\n");

        for(j = i; j>0 && a[j-1] > tmp; j--){
            a[j] = a[j-1];
        }
        a[j] = tmp;

        if(a[i] == a[j]){
            for(k =0; k<j-1; k++){
                printf("  ");
            }
            printf(" +\n");
        }
        else{
            for(k = 0; k<j; k++){
                printf("  ");
            }
            printf("^-");
            for(k=j+1; k<i; k++){
                printf("--");
            }
            printf("-+\n");
        }


    }
}

int main(){
    int i, nx;
    int *x; 

    printf("요소의 삽입 과정을 자세하게 출력할 수 있도록 단순 삽입 정렬 프로그램을 수정하세요. \n");
    printf("[*] 요소의 개수를 입력하세요. : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    printf("[*] 요소들을 입력하세요. \n");
    for(i=0; i<nx; i++){
        printf("[-] x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("[*] 입력 배열 : ");
    for(i=0; i<nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    insertion(x, nx);

    printf("[*] 정렬 배열 : ");
    for(i=0; i<nx; i++){
        printf("%d ", x[i]);
    }

    free(x);
    return 0;
}