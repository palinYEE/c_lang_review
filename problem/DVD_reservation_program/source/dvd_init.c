#include "dvd_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yj_dvd_st_init(YJ_ST_MANAGE_TABLE *in)
{   
    YJ_DVD_USER_ST *temp;
    YJ_DVD_INFO_ST *temp2;

    /* 메모리 할당 */
    in->user_st = malloc(sizeof(YJ_DVD_USER_ST));
    in->rental_info_st = malloc(sizeof(YJ_ST_MANAGE_TABLE));        

    temp = in->user_st;
    temp2 = in->rental_info_st;

    temp->user_name = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    temp->phone_number = malloc(sizeof(char) * MAX_CHAR_LENGTH);

    temp2->genre = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    temp2->ISBN = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    temp2->release_year = malloc(sizeof(char) * MAX_CHAR_LENGTH);
    temp2->title = malloc(sizeof(char) * MAX_CHAR_LENGTH);

    /* 변수의 쓰레기 값을 정리하기 위한 변수 셋팅 */
    memset(temp->user_name, '/0', MAX_CHAR_LENGTH);
    memset(temp->phone_number, '/0', MAX_CHAR_LENGTH);

    memset(temp2->genre, '/0', MAX_CHAR_LENGTH);
    memset(temp2->ISBN, '/0', MAX_CHAR_LENGTH);
    memset(temp2->release_year, '/0', MAX_CHAR_LENGTH);
    memset(temp2->title, '/0', MAX_CHAR_LENGTH);
}