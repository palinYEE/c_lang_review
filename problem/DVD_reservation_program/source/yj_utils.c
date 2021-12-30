#include "yj_utils.h"
#include "dvd_init.h"
#include <stdio.h>
#include <string.h>

/* 날짜 계산 알고리즘을 고도화할 필요가 있음 */
void yj_setting_rental_time(YJ_RENTAL_INFO_ST *out)
{
    int days_max[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31}; // 달의 마지막 날짜
    
    /* time value standard second */
    time_t yj_time_now_int;
    time_t yj_time_fin_int;
        
    /* time struct */
    struct tm *yj_time_now_struct;
    struct tm *yj_time_fin_struct;
    char temp[100];

    /* 현재 시간 셋팅 */
    yj_time_now_int = time(NULL);
    yj_time_fin_int = yj_time_now_int + 10*24*60*60     // days * hours * minutes * second
    yj_time_now_struct = localtime(&yj_time_now_int);
    yj_time_fin_struct = localtime(&yj_time_fin_struct);

    out->rental_date = yj_time_now_struct;
    out->return_date = yj_time_fin_struct;
    out->rental_date_time_t = yj_time_now_int;
    out->return_date_time_t = yj_time_fin_int;
}