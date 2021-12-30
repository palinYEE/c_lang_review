#include "dvd_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input_dvd_data(YJ_DVD_INFO_ST *in)
{
    srand(time(NULL));
    printf(" - 새로운 dvd 이름을 입력하세요 : ");
    scanf("%s", in->title);
    in->ISBN = (int)rand()%100000;
    printf(" - 셋팅된 ISBN 값은 %d 입니다. \n", in->ISBN);
    printf(" - 장르를 입력해 주세요 : ");
    scanf("%s", in->genre);
    printf(" - 출시 년도를 입력해주세요. (years/month/day)");
    scanf("%s", in->release_year);
}

void print_dvd_list(YJ_DVD_INFO_ST *in)
{
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n\n\t\t\t title : %s\n", in->title);
    printf("\t\t\t ISBM : %d\n", in->ISBN);
    printf("\t\t\t genre : %s\n", in->genre);
    printf("\t\t\t rental date : %s\n\n", in->release_year);
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

void check_lotus_user(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE], int *count)
{
    int i;
    YJ_RENTAL_INFO_ST *rental_temp;
    YJ_DVD_USER_ST *user_temp;
    time_t now_date = time(NULL);

    for(i=0; i<*count; i++){
        rental_temp = dvd_user_table[i]->rental_info_st;
        user_temp = dvd_user_table[i]->user_st;
        if(rental_temp->rental_date == NULL){
            printf(" - %s 님은 DVD를 대여하지 않았습니다. \n", user_temp->user_name);
        }
        else{
            // 빌린 날짜 형식은 다음과 같다. 
            // year/month/day ~ year/month/day+10
            // 오늘 날짜가 해당 기간 사이에 있으면 연채 아님. 이 밖에 있으연 연채.
            if(rental_temp->rental_date_time_t <= now_date < rental_temp->return_date_time_t - 24*60*60){
                printf(" - %s 님은 아직 대여기간입니다. \n", user_temp->user_name);
            }
            else if(rental_temp->return_date_time_t - 24*60*60 <= now_date <= rental_temp->return_date_time_t){
                printf(" - %s 님은 24시간 내로 반납하셔야 합니다. \n", user_temp->user_name);
            }
            else{
                printf(" - %s 님은 연채되셨습니다. \n", user_temp->user_name);
                rental_temp->lotus_check = 'Y';
            }
        }
    }
}
