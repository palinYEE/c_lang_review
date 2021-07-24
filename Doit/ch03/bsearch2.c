#include<stdio.h>
#include<stdlib.h>

int int_cmpr(const int *a, const int *b){
    return *a > *b ? -1 : *a < *b ? 1 : 0;
}

int main(){
    int i, nx, ky;
    int *x;
    int *p;

    puts("bsearch 내림차순 Ver.");
    printf("요소 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    printf("x[0] : ");
    scanf("%d", x);

    for(i=1; i<nx; i++){
        do{
            printf("x[%d] : ", i);
            scanf("%d", x + i);
        } while (x[i] > x[i-1]);
    }

    printf("검색할 요소 :");
    scanf("%d", &ky);

    p = bsearch(&ky,
                x,
                nx,
                sizeof(int),
                (int(*)(const void *, const void *))int_cmpr
                );

    if( p == NULL)
        puts("검색 요소가 없습니다. ");
    else
        printf("%d은(는) x[%d]에 존재합니다.", ky, (int)(p-x));
    free(x);
    return 0;
}