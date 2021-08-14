/*
    단순 삽입 정렬에서 배열의 첫 번째(a[0])부터 데이터를 저장하지 않고 a[1]부터 데이터를 저장하면
    a[0]을 보초로 하여 삽입을 마치는 조건을 줄일 수 있습니다. 이 아이디어를 적용한 단순 삽입 정렬 함수를 수정하세요.
*/
#include<stdio.h>
#include<stdlib.h>

void originalInsertion(int a[], int n){
    int i, j;
    for(i = 1; i<n; i++){
        int tmp = a[i];
        for(j = i; j > 0 && a[j-1] > tmp; j--){
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}

void insertion(int a[], int n){
    int i, j;
    
    for(i=1; i<n; i++){
        int tmp = a[0] = a[i];
        for(j = i; a[j-1] > tmp; j--){
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }

}

int main(){
    int i, nx;
    int *x;

    printf("단순 삽입 정렬에서 배열의 첫 번째(a[0])부터 데이터를 저장하지 않고 a[1]부터 데이터를 저장하면 a[0]을 보초로 하여 삽입을 마치는 조건을 줄일 수 있습니다. 이 아이디어를 적용한 단순 삽입 정렬 함수를 수정하세요.\n");

    printf("[*] 요소의 개수를 입력하세요. : ");
    scanf("%d", &nx);

    x = calloc(nx + 1, sizeof(int));

    for(i=1; i<nx + 1; i++){
        printf("[-] x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("[*] 입력 요소 : ");
    for(i=1; i<nx + 1; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    insertion(x, nx + 1);

    printf("[*] 정렬 요소 : ");
    for(i=1; i<nx + 1; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}