#include "dvd_init.h"
#include "dvd_user.h"
#include "dvd_server.h"
#include <stdio.h>
#include <stdlib.h>

void yj_user_mode()
{
    YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE];

    int select = 0;
    int table_count = 0;
    int i;

    for(i=0; i<MAX_TABLE_SIZE; i++){
        dvd_user_table[i] = malloc(sizeof(YJ_ST_MANAGE_TABLE));
        yj_dvd_st_init(dvd_user_table[i]);
    }
    while(1)
    {
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@                                                              @\n");
        printf("@                     DVD MANAGEMENT PROGRAM                   @\n");
        printf("@                                                              @\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        
        printf("\n\n\t\t\t 1. Input User info\n");
        printf("\t\t\t 2. Print user info \n");
        printf("\t\t\t 0. Back\n");
        printf(" - Select: ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            input_user_data(dvd_user_table[table_count]->user_st);
            table_count += 1;
            break;
        case 2:
            for(i=0; i<table_count; i++){
                print_user_list(dvd_user_table[i]);
            }
            break;
        case 0:
            goto USER_FIN;
        default:
            goto USER_FIN;
            break;
        }
    }
USER_FIN:;
    for(i=0; i<MAX_TABLE_SIZE; i++){
        free(dvd_user_table[i]);
    }
}

void yj_root_mode()
{
    YJ_DVD_INFO_ST *dvd_root_table[MAX_DVD_NUM];

    int select = 0;
    int table_count = 0;
    int i;

    for(i=0; i<MAX_DVD_NUM; i++){
        dvd_root_table[i] = malloc(sizeof(YJ_DVD_INFO_ST));
        yj_dvd_server_init(dvd_root_table[i]);
    }
    while(1)
    {
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@                                                              @\n");
        printf("@                     DVD MANAGEMENT PROGRAM                   @\n");
        printf("@                                                              @\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        
        printf("\n\n\t\t\t 1. Input DVD info\n");
        printf("\t\t\t 2. Print DVD info \n");
        printf("\t\t\t 0. Back\n");
        printf(" - Select: ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            input_dvd_data(dvd_root_table[table_count]);
            table_count += 1;
            break;
        case 2:
            for(i=0; i<table_count; i++){
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
    for(i=0; i<MAX_TABLE_SIZE; i++){
        free(dvd_root_table[i]);
    }
}  

int main()
{
    int select_main_menu;
    while(1)
    {
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@                                                              @\n");
        printf("@                     DVD MANAGEMENT PROGRAM                   @\n");
        printf("@                                                              @\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        
        printf("\n\n\t\t\t 1. USER MODE\n");
        printf("\t\t\t 2. ROOD MODE \n");
        printf("\t\t\t 0. FINISH\n");
        printf(" - Select: ");
        scanf("%d", &select_main_menu);
        switch (select_main_menu)
        {
        case 1:
            yj_user_mode();
            break;
        case 2:
            yj_root_mode();
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
    return 0;

}