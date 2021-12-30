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
    yj_time_fin_struct = localtime(&yj_time_fin_int);

    out->rental_date = yj_time_now_struct;
    out->return_date = yj_time_fin_struct;
    out->rental_date_time_t = yj_time_now_int;
    out->return_date_time_t = yj_time_fin_int;
}

void extraction_data_file(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE], YJ_DVD_INFO_ST *dvd_root_table[MAX_DVD_NUM], int *user_table_count, int *root_table_count,char *file_name){

    /* file value setting */
    FILE *fp;
    fp = fopen(file_name, "a");
    /* loop value */
    int i;
    /* temp value */
    YJ_DVD_USER_ST *user_temp;
    YJ_RENTAL_INFO_ST *rental_temp;
    /* time value setting */
    time_t now_time_int;
    struct tm *now_time_st;
    now_time_int = time(NULL);
    now_time_st = localtime(&now_time_int);

    
    fprintf(fp, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    fprintf(fp, "@                                                              @\n");
    fprintf(fp, "@                     DVD MANAGEMENT PROGRAM                   @\n");
    fprintf(fp, "@                                                              @\n");
    fprintf(fp, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    fprintf(fp, "\n - extract date : %d-%d-%d", now_time_st->tm_year+1900, now_time_st->tm_mon ,now_time_st->tm_mday)
    fprintf(fp, " - File name : %s", file_name);
    fprintf(fp, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    fprintf(fp, " -- USER DATA \n");
    for(i=0; i<*user_table_count; i++){
        // user data extraction
        user_temp = dvd_user_table[i]->user_st;
        rental_temp = dvd_user_table[i]->rental_info_st;
        fprintf(fp, " - Name : %s\n", user_temp->user_name);
        fprintf(fp, " - Phone Number : %s\n", user_temp->phone_number);
        if(rental_temp->lotus_check != ""){
            fprintf(fp, " - DVD Title : %s\n", rental_temp->title);
            fprintf(fp, " - DVD Rental Date : %d-%d-%d:%d-%d\n", rental_temp->rental_date->tm_year+1900, rental_temp->rental_date->tm_mon, rental_temp->rental_date->tm_mday, rental_temp->rental_date->tm_hour, rental_temp->rental_date->tm_min);
            fprintf(fp, " - DVD Return Date : %d-%d-%d\n", return_date->rental_date->tm_year+1900, return_date->rental_date->tm_mon, return_date->rental_date->tm_mday);
            fprintf(fp, " - DVD Lotus Check : %s", rental_temp->lotus_check);
        }
        fprintf(fp, "=======================\n");
    }    
    fprintf(fp, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    fprintf(fp, " -- DVD DATA \n");
    for(i=0; i<*root_table_count; i++){
        // dvd data extraction
        fprintf(fp, " - DVD Title : %s\n", dvd_root_table[i]->title);
        fprintf(fp, " - DVD ISBN : %d\n", dvd_root_table[i]->ISBN)l
        fprintf(fp, " - DVD Genre : %s\n", dvd_root_table[i]->genre);
        fprintf(fp, " - release_year : %s\n", dvd_root_table[i]->release_year);
        fprintf(fp, "=======================\n");
    }

    // all data terminate logic add.
    *user_table_count = 0;
    *root_table_count = 0;
    fclose(fp);
}