/*
    * date: 2022.01.26 수요일
    * 내용 : 포인터에 대한 개념 이해와 예제 코드 작성
*/
#include<stdio.h>

void valuePointer(){
    /*
        변수의 주소를 알고 싶으면 &을 넣어야 한다. 
    */
    printf("=============================================\n");
    printf("변수 포인터 \n");
    int num1 = 3;
    int num2 = 6;
    /* 주소를 받을 변수 */
    int* num1Pointer; 
    int* num2Pointer;

    /* num1, num2의 주소를 넣어준다. */
    num1Pointer = &num1;
    num2Pointer = &num2;

    printf("num1: %d, num1Pointer: %d\n", num1, *num1Pointer);
    printf("num2: %d, num2Pointer: %d\n", num2, *num2Pointer);
}

void arrayPointer(){

    printf("=============================================\n");
    printf("배열 포인터 \n");
    char* arr[3];
    int i =0;

    arr[0] = "hello ";
    arr[1] = "my name is ";
    arr[2] = "Yoon Yeoung Jin";

    // for(i=0; i<sizeof(arr); i++){
    for(i=0; i<sizeof(arr)/sizeof(*arr); i++){
        // printf("arr[%d] --> %s\n", i, *(arr+i)); /* 이때는 에러 안나는데 */
        printf("arr[%d] --> %s : address=%d\n", i, *(arr+i), &arr+i); /* 이떄는 에러가 난다 왤까? */
    }
}

int main(){
    valuePointer();
    arrayPointer();
    return 0;
}