#include "yj_time.h"

void yj_time_print(){
    time_t yj_time_now_int;
    struct tm *yj_time_now_struct;

    yj_time_now_int = time(NULL);
    yj_time_now_struct = localtime(&yj_time_now_int);


    printf(" - Play time : %d년 %d월 %d일 %d시 %d분 %d초\n", yj_time_now_struct->tm_year + 1900, yj_time_now_struct->tm_mon + 1, yj_time_now_struct->tm_mday, yj_time_now_struct->tm_hour, yj_time_now_struct->tm_min, yj_time_now_struct->tm_sec);
}