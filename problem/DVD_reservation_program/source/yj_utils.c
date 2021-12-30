#include "yj_utils.h"
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

void extraction_data_file(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE], YJ_DVD_INFO_ST *dvd_root_table[MAX_DVD_NUM], int *user_table_count, int *root_table_count,char *file_name){

    FILE *fp;
    fp = fopen(file_name, "a");

    /* loop value */
    int i;

    for(i=0; i<*user_table_count; i++){
        // user data extraction
    }    

    for(i=0; i<*root_table_count; i++){
        // dvd data extraction
    }


    // all data terminate logic add.


}