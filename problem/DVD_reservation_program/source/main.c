#include "dvd_init.h"
#include "dvd_user.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    YJ_ST_MANAGE_TABLE *dvd_table;
    int select = 0;
    int table_count = 0;

    dvd_table = malloc(sizeof(YJ_ST_MANAGE_TABLE) * MAX_TABLE_SIZE);
    while(1)
    {
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@                                                              @\n");
        printf("@                     DVD MANAGEMENT PROGRAM                   @\n");
        printf("@                                                              @\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        
        printf("\n\n\t\t\t 1. Input User info\n");
        printf("\t\t\t 2. Print user info \n");
        printf(" - Select: ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            input_user_data((dvd_table + table_count)->user_st);
            table_count += 1;
            break;
        case 2:
            print_user_list(dvd_table);
            break;
        default:
            goto FIN;
            break;
        }
    }
FIN:;
    return 0;

}