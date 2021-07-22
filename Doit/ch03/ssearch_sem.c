#include<stdio.h>
#include<stdlib.h>  

int search(int a[], int n, int key){
    int i = 0;
    a[n] = key;

    while(1){
        if(a[i] == key)
            break;
        i++;        
    }

    return i == n ? -1 : i;         // i == n ? false : true;
}

int main(void){
    int nx, ky, idx;
    int *x;

    puts("보초법");
    printf("원소 개수 : ");
    scanf("%d", &nx);

    printf("찾을 원소 : ");
    scanf("%d", &ky);

    x = calloc(nx + 1, sizeof(int));

    for(int i=0; i<nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", x + i);
    }

    idx = search(x, nx, ky);

    if(idx == -1)
        printf("원소를 찾지 못하였습니다. \n");
    else
        printf("%d 값은 x[%d]에 있습니다. \n", ky, idx);

    free(x);
    return 0;

}