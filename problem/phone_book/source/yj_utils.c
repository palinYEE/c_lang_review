#include "yj_utils.h"
#include "yj_time.h"
#include <stdio.h>
#include <string.h>

int yj_cmp_str(char *a, char *b){
    int ret;
    ret = strcmp(a, b);
    return ret;
}

/* TODO: 전역 변수로 관리하기 */ 
void print_info(){
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf(" - Title : 전화 번호 관리 프로그램 \n");
    printf(" - Author : YYJ\n");
    yj_time_print();
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}