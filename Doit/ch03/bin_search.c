#include<stdio.h>
#include<stdlib.h>

int search(const int a[], int n, int key){
    int pl = 0;             // 배열의 맨 처음 값
    int pr = n-1;           // 배열의 맨 마지막 값
    int pc;                 // 배열의 중간 값

    do
    {
        pc = (pl + pr) / 2;
        if(a[pc] == key)
            return pc;
        else if(a[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while (pl <= pr);
    
    return -1;
}

int main(){
    int nx, ky, idx;
    int *x;

    puts("Bineary Search");
    printf("요소 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));
    
    printf("x[0] : ");
    scanf("%d", x);
    for(int i=1; i<nx; i++){
        do{
            printf("x[%d] : ", i);
            scanf("%d", x+i);
        } while (x[i] < x[i-1]);
    }
    
    printf("검색 원소 : ");
    scanf("%d", &ky);

    idx = search(x, nx, ky);

    if(idx == -1)
        printf("검색 실패하였습니다. \n");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, idx);
    free(x);
    return 0;
}