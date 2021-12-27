#include "dvd_user.h"
#include "yj_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_user_list(YJ_ST_MANAGE_TABLE *in)
{
    YJ_DVD_USER_ST *usr_temp = in->user_st;
    YJ_RENTAL_INFO_ST *rental_temp = in->rental_info_st;

    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n\n\t\t\t user name : %s\n", usr_temp->user_name);
    printf("\t\t\t phone number : %s\n", usr_temp->phone_number);
    printf("\t\t\t rental DVD name : %s\n", rental_temp->title);
    printf("\t\t\t rental date : %s\n", rental_temp->rental_date);
    printf("\t\t\t return date : %s\n", rental_temp->return_date);
    printf("\t\t\t lotus check : %s\n", rental_temp->lotus_check);
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

void input_user_data(YJ_DVD_USER_ST *in)
{
    printf(" - 유저 이름을 입력하세요 : ");
    scanf("%s", in->user_name);
    if(in->user_name == NULL){
        printf("ERROR! 유저 이름이 제대로 입력되지 않았습니다. \n");
        goto FAIL;
    }
    printf(" - 핸드폰 번호를 입력하세요 : ");
    scanf("%s", in->phone_number);
    if(in->phone_number == NULL){
        printf("ERROR! 핸드폰 번호가 제대로 입력되지 않았습니다. \n");
        goto FAIL;
    }
FAIL:;
}

void delete_user_data(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE], int *count, int delete_index)
{
    YJ_ST_MANAGE_TABLE *swap_temp;
    if(delete_index != *count){
        swap_temp = dvd_user_table[*count];
        dvd_user_table[*count] = dvd_user_table[delete_index];
        dvd_user_table[delete_index] = swap_temp;
    }

    YJ_DVD_USER_ST *temp;
    YJ_RENTAL_INFO_ST *temp2;

    temp = dvd_user_table[*count]->user_st;
    temp2 = dvd_user_table[*count]->rental_info_st;

    /* 제로화 */
    memset(temp->user_name, '0', MAX_CHAR_LENGTH);
    memset(temp->phone_number, '0', MAX_CHAR_LENGTH);

    memset(temp2->title, '0', MAX_CHAR_LENGTH);
    memset(temp2->rental_date, '0', MAX_CHAR_LENGTH);
    memset(temp2->return_date, '0', MAX_CHAR_LENGTH);
    memset(temp2->lotus_check, '0', MAX_CHAR_LENGTH);

    *count--;
}

int find_user_data_from_name(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE], int *count ,char *find_name)
{
    int i;
    YJ_DVD_USER_ST *temp; 
    for(i=0; i<*count; i++){
        temp = dvd_user_table[i]->user_st;
        if(strcmp(temp->user_name, find_name) == 0){
            return i;
        }
    }
    return NOT_FOUND;
}

int find_user_data_from_phone_number(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE],int *count ,char *find_phone_number)
{
    int i;
    YJ_DVD_USER_ST *temp;
    for(i=0; i<*count; i++){
        temp = dvd_user_table[i]->user_st;
        if(strcmp(temp->phone_number, find_phone_number) == 0){
            return i;
        }
    }
    return NOT_FOUND;
}

void input_rent_info(YJ_ST_MANAGE_TABLE *in, YJ_DVD_INFO_ST *dvd_root_table[MAX_DVD_NUM])
{
    int i;

    YJ_RENTAL_INFO_ST *temp = in->rental_info_st;

    printf(" - 빌릴 책 이름을 입력하세요 : ");
    scanf("%s", temp->title);

    for(i=0; i<MAX_DVD_NUM; i++){
        if(strcmp(temp->title, dvd_root_table[i]->title) == 0){
            yj_now_time_str(temp->rental_date);
            temp->lotus_check = "N";
            break;
        }
    }
    if(i >= MAX_DVD_NUM){
        printf(" - 해당 책이 존재하지 않습니다. \n");
    }
}

