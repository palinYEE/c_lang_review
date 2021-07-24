#include<stdio.h>
#include<stdlib.h>

// 정수를 비교하는 함수 
int int_cmp(const int *a, const int *b){
    if(*a < *b)
        return -1; 
    else if(*a > *b)
        return 1;
    else
        return 0;
}

// 조건 연산자를 이용한 정수를 비교하는 함수
int int_cmp2(const int *a, const int *b){
    return *a < *b ? -1 : *a > *b ? 1 : 0;
}

// cast 없이 bsearch를 사용할 수 있게 해주는 비교 함수
int int_cmp3(const void *a, const void *b){
    if(*(int* )a < *(int*)b)
        return -1;
    else if(*(int*)a > *(int*)b)
        return 1;
    else
        return 0;
}
int main(){
    int i, nx, ky;
    int *x;
    int *p;

    puts("bsearch 함수를 이용하여 검색");
    printf("요소 갯수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    printf("x[0] : ");
    scanf("%d", x);

    for(i=1; i<nx; i++){
        do
        {
            printf("x[%d] : ", i);
            scanf("%d", x+i);
        } while (x[i] < x[i-1]);
    }

    printf("검색할 요소 : ");
    scanf("%d", &ky);

    p = bsearch(&ky,        // 검색 요소
                x,          // 검색 대상 배열
                nx,         // 배열 길이
                sizeof(int),
                (int(*)(const void *, const void *))int_cmp // 비교 함수
                // (int(*)(const void *, const void *))int_cmp2 // 비교 함수 2
                // int_cmp3
                );

    if(p == NULL)
        puts("요소 검색을 실패하였습니다.");
    else
        printf("%d은(는) x[%d]에 있습니다. \n", ky, (int)(p - x));
    
    free(x);
    return 0;

}