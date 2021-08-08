/*
    버블 정렬(버전 2)의 아이디어는 배열이 정렬을 마쳤는지를 검사하는데 응용할 수 있다. 
    전달받은 배열 a가 오름차순으로 정렬을 마쳤는지 검사하는 함수를 작성하세요. 
    이때 오름차순으로 정렬을 마친 상태라면 1, 그렇지 않으면 0으로 반환하도록 작성하세요.
    `int is_sorted(const int a[], int n);`
*/
#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void bubble(int a[], int n){
    int i, j;
    int exchg;

    for(i=0; i<n-1; i++){
        for(j = n-1; j > i; j--){
            exchg = 0;
            if(a[j-1] > a[j]){
                swap(int, a[j-1], a[j]);
                exchg++;
            }
        }
        if(exchg == 0){
            break;
        }
    }
}

int is_sorted(const int a[], int n){
    int i;
    for(i=0; i<n-1; i++){
        if(a[i] > a[i + 1]){
            return 0;
        }
    }
    return 1;
}

void print(const int a[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int i, nx;
    int checkNum;
    int *x;

    printf("Q3. 버블 정렬(버전 2)의 아이디어는 배열이 정렬을 마쳤는지를 검사하는데 응용할 수 있다. 전달받은 배열 a가 오름차순으로 정렬을 마쳤는지 검사하는 함수를 작성하세요. 이때 오름차순으로 정렬을 마친 상태라면 1, 그렇지 않으면 0으로 반환하도록 작성하세요.\n");
    printf("[*] 요소 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    printf("[*] %d개 요소를 입력하세요 : ", nx);
    for(i=0; i<nx; i++){
        scanf("%d", x + i);
    }

    printf("[*] 입력 배열 : ");
    print(x, nx);

    bubble(x, nx);
    checkNum = is_sorted(x, nx);
    if(checkNum == 1){
        puts("오름차순으로 정렬을 완료하였습니다.");
    }
    else{
        puts("오름차순으로 정렬을 실패하였습니다.");
    }
    print(x, nx);

}