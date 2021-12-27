#include "dvd_init.h"
#include "dvd_user.h"
#include "dvd_server.h"
#include <stdio.h>
#include <stdlib.h>

void print_logo()
{
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@                                                              @\n");
    printf("@                     DVD MANAGEMENT PROGRAM                   @\n");
    printf("@                                                              @\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

void yj_user_mode(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE], int *table_count)
{
    int select = 0;
    /* 찾을 데이터를 저장하는 변수 */
    int find_name[MAX_CHAR_LENGTH] = {0,};
    int index_find_name;
    int find_phone_number[MAX_CHAR_LENGTH] = {0, };
    int index_find_phone_number;
    /* loop value */
    int i;

    while(1)
    {
        print_logo();
        
        printf("\n\n\t\t\t 1. Input User info\n");
        printf("\t\t\t 2. Print user info \n");
        printf("\t\t\t 3. Find user data from name\n");
        printf("\t\t\t 4. Find user data from phone number\n");
        printf("\t\t\t 5. Delete user data\n");
        printf("\t\t\t 0. Back\n");
        printf(" - Select: ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            input_user_data(dvd_user_table[*table_count]->user_st);
            *table_count += 1;
            break;
        case 2:
            for(i=0; i<*table_count; i++){
                print_user_list(dvd_user_table[i]);
            }
            break;
        case 3:
            printf(" - 이름을 입력하세요 : ");
            scanf("%s", find_name);
            index_find_name = find_user_data_from_name(dvd_user_table, table_count, find_name);
            if(index_find_name == NOT_FOUND){
                printf("       - 찾는 데이터가 존재하지 않습니다. \n");
            }else{
                print_user_list(dvd_user_table[index_find_name]);
            }
            break;
        case 4:
            printf(" - 전화번호를 입력하세요 : ");
            scanf("%s", find_phone_number);
            index_find_phone_number = find_user_data_from_phone_number(dvd_user_table, table_count, find_phone_number);
            if(index_find_phone_number == NOT_FOUND){
                printf("       - 찾는 데이터가 존재하지 않습니다. \n");
            }else{
                print_user_list(dvd_user_table[index_find_phone_number]);
            }
            break;
        case 5:
            printf(" - 이름을 입력하세요 : ");
            scanf("%s", find_name);
            index_find_name = find_user_data_from_name(dvd_user_table, table_count, find_name);
            delete_user_data(dvd_user_table, table_count, index_find_name);
            break;
        case 0:
            goto USER_FIN;
        default:
            goto USER_FIN;
            break;
        }
    }
USER_FIN:;
}

void yj_root_mode(YJ_DVD_INFO_ST *dvd_root_table[MAX_DVD_NUM], int *table_count)
{
    int select = 0;
    int i;

    while(1)
    {
        print_logo();
        
        printf("\n\n\t\t\t 1. Input DVD info\n");
        printf("\t\t\t 2. Print DVD info \n");
        printf("\t\t\t 0. Back\n");
        printf(" - Select: ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            input_dvd_data(dvd_root_table[*table_count]);
            *table_count += 1;
            break;
        case 2:
            for(i=0; i<*table_count; i++){
                print_dvd_list(dvd_root_table[i]);
            }
            break;
        case 0:
            goto ROOT_FIN;
        default:
            goto ROOT_FIN;
            break;
        }
    }
ROOT_FIN:;
}  

int main()
{
    int select_main_menu;
    int user_table_count = 0;
    int root_table_count = 0;
    int i;

    YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE];
    YJ_DVD_INFO_ST *dvd_root_table[MAX_DVD_NUM];

    for(i=0; i<MAX_DVD_NUM; i++){
        dvd_root_table[i] = malloc(sizeof(YJ_DVD_INFO_ST));
        yj_dvd_server_init(dvd_root_table[i]);
    }
    for(i=0; i<MAX_TABLE_SIZE; i++){
        dvd_user_table[i] = malloc(sizeof(YJ_ST_MANAGE_TABLE));
        yj_dvd_st_init(dvd_user_table[i]);
    }

    while(1)
    {
        print_logo();
        
        printf("\n\n\t\t\t 1. USER MODE\n");
        printf("\t\t\t 2. ROOD MODE \n");
        printf("\t\t\t 0. FINISH\n");
        printf(" - Select: ");
        scanf("%d", &select_main_menu);
        switch (select_main_menu)
        {
        case 1:
            yj_user_mode(dvd_user_table, &user_table_count);
            break;
        case 2:
            yj_root_mode(dvd_root_table, &root_table_count);
            break;
        case 0:
            goto MAIN_FIN;
            break;
        default:
            goto MAIN_FIN;
            break;
        }
    }
MAIN_FIN:;
    for(i=0; i<MAX_TABLE_SIZE; i++){
        free(dvd_user_table[i]);
    }
    for(i=0; i<MAX_DVD_NUM; i++){
        free(dvd_root_table[i]);
    }
    return 0;

}