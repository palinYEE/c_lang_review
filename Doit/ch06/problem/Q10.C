/*
    단순 삽입 정렬은 배열의 요소 개수가 많아지면 많아질수록 요소 삽입에 필요한 비교, 대입 비용이 무시할 수 없을 정도로 커집니다.
    이때 배열에서 이미 정렬된 부분은 이진 검색을 사용할 수 있기 때문에 삽입할 위치를 더 빨리 찾을 수 있습니다. 
    이진 검색을 사용하여 프로그램을 수정하세요.
*/
#include<stdio.h>
#include<stdlib.h>

void insertion(int a[], int n){
    int i;
    for(i = 1; i<n; i++){
        int tmp = a[i];

        if(a[i-1] > tmp){
            int pl = 0;
            int pr = i-1;
            int pc;

            do{
                pc = (pl + pr) / 2;
                if(a[pc] == tmp){
                    pl = pc;
                    break;
                }
                else if(a[pc] < tmp)
                    pl = pc + 1;
                else
                    pr = pc - 1;
            }while(pl <= pr);

            for(int z=i; z > pl; z--){
                a[z] = a[z-1];
            }
            a[pl] = tmp;
        }
    }
}

int main() {
    int i, nx;
    int *x;

    puts("이진 삽입 정렬");

    printf("요소 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    insertion(x, nx);

    puts("오름차순으로 정렬했습니다.");

    for(i = 0; i< nx; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}
