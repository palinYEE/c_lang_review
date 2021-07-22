// 선형 검색
#include<stdio.h>
#include<stdlib.h>

int searchWhile(const int a[], int n, int key){
    int i=0; 

    while(1){
        if(n == i)      // 검색 값이 존재하지 않을 경우
            return -1;
        
        if(a[i] == key) // 검색 값을 찾은 경우
            return i;
        i++;
    }
}

int searchFor(const int a[], int n, int key){
    int i;
    for(i=0; i<n; i++){
        if(a[i] == key) // 검색 값을 찾은 경우
            return i;
    }
    return -1;          // 검색 값이 존재하지 않은 경우
}

int main(void){
    int i, nx, ky;
    int idxWhile, idxFor;
    int *x;

    puts("Linear Search");
    printf("요소 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int)); // 메모리 할당

    for(i=0; i<nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", x+i);
    }
    printf("검색값 : ");
    scanf("%d",&ky);

    idxWhile = searchWhile(x, nx, ky);
    idxFor   = searchFor(x, nx, ky);

    printf("while 문 적용\n");
    if(idxWhile == -1)
        printf("검색에 실패하였습니다.\n");
    else
        printf("%d(은)는 x[%d]에 있습니다.\n", ky, idxWhile);

    printf("for 문 적용\n");
    if(idxFor == -1)
        printf("검색에 실패하였습니다.\n");
    else
        printf("%d(은)는 x[%d]에 있습니다.\n", ky, idxFor);

    free(x);
    return 0;
}