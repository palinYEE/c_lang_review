#include<stdio.h>

int main(){
    int *myPointer;
    int myVar = 10;

    printf("myVar = %d\n", myVar);
    myPointer = &myVar;

    *myPointer = 20;
    printf("\n*myPointer = 20으로 변경 \n");
    printf("myVar = %d\n", myVar);

    return 0;
}