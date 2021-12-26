#include "dvd_user.h"
#include <stdio.h>
#include <stdlib.h>

void print_user_list(YJ_ST_MANAGE_TABLE *in)
{
    YJ_DVD_USER_ST *usr_temp = in->user_st;
    YJ_RENTAL_INFO_ST *rental_temp = in->rental_info_st;

    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n\n\t\t\t\t\t\t user name : %s\n", usr_temp->user_name);
    printf("\t\t\t\t\t\t phone number : %s\n", usr_temp->phone_number);
    printf("\t\t\t\t\t\t rental DVD name : %s\n", rental_temp->title);
    printf("\t\t\t\t\t\t rental date : %s\n", rental_temp->rental_date);
    printf("\t\t\t\t\t\t return date : %s\n", rental_temp->return_date);
    printf("\t\t\t\t\t\t lotus check : %s\n", rental_temp->lotus_check);
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
