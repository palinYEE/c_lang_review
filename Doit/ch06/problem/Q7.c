/*
    요소의 교환 과정을 자세하게 출력할 수 있도록 단순 선택 정렬 프로그램을 수정하세요.
    ex.
        *       +
        6 4 8 3 1 9 7
          *   +
        1 4 8 3 6 9 7
            * +
        1 3 8 4 6 9 7 
        -- 이하 생략 --
    위 예시처럼 정렬하지 않은 부분의 첫 번째 요소 위에는 * 기호를, 
    정렬하지 않는 부분의 가장 작은 값의 요소 위에는 기호 +를 출력하세요.
*/
#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void selection(int a[], int n){
    int i, j, k;

    for(i=0; i<n; i++){
        int min = i;
        for(k = 0; k<i; k++){
            printf("  ");
        }
        if(i != n-1){
            printf("* ");
        }
        
        for(j = i + 1; j<n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        for(k = i + 1; k < min; k++){
            printf("  ");
        }
        
        if(i != n-1){
            printf("+ ");
        }
        printf("\n");
        for(k=0; k<n; k++){
            printf("%d ", a[k]);
        }
        printf("\n");
        swap(int, a[i], a[min]);
    }
}

int main(){
    int i, nx;
    int *x;

    printf("요소의 교환 과정을 자세하게 출력할 수 있도록 단순 선택 정렬 프로그램을 수정하세요.\n");

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

    selection(x, nx);

    printf("[*] 정렬 배열 : ");
    for(i=0; i<nx; i++){
        printf("%d ", x[i]);
    }

    free(x);
    return 0;

}