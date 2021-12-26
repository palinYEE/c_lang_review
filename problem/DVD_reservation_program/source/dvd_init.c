#include "dvd_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yj_dvd_st_init(YJ_ST_MANAGE_TABLE *in)
{   
    YJ_DVD_USER_ST *temp;
    YJ_RENTAL_INFO_ST *temp2;

    /* 메모리 할당 */
    in->user_st = malloc(sizeof(YJ_DVD_USER_ST));
    in->rental_info_st = malloc(sizeof(YJ_RENTAL_INFO_ST));        

    temp = in->user_st;
    temp2 = in->rental_info_st;

    temp->user_name = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    temp->phone_number = malloc(sizeof(char) * MAX_CHAR_LENGTH);

    temp2->title = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    temp2->user_name = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    temp2->rental_date = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    temp2->return_date = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    temp2->lotus_check = malloc(sizeof(char) * MAX_CHAR_LENGTH);

    /* 변수의 쓰레기 값을 정리하기 위한 변수 셋팅 */
    memset(temp->user_name, '0', MAX_CHAR_LENGTH);
    memset(temp->phone_number, '0', MAX_CHAR_LENGTH);

    memset(temp2->title, '0', MAX_CHAR_LENGTH);
    memset(temp2->user_name, '0', MAX_CHAR_LENGTH);
    memset(temp2->rental_date, '0', MAX_CHAR_LENGTH);
    memset(temp2->return_date, '0', MAX_CHAR_LENGTH);
    memset(temp2->lotus_check, '0', MAX_CHAR_LENGTH);
}

void yj_dvd_server_init(YJ_DVD_INFO_ST *in)
{
    in->title = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    in->genre = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    in->release_year = malloc(sizeof(char) * MAX_CHAR_LENGTH);

    memset(in->title, '0', MAX_CHAR_LENGTH);
    memset(in->genre, '0', MAX_CHAR_LENGTH);
    memset(in->release_year, '0', MAX_CHAR_LENGTH);
    in->ISBN = 0;
}