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