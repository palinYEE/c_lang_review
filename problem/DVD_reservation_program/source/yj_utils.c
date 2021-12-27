#include "yj_utils.h"
#include <stdio.h>
#include <string.h>

void yj_now_time_str(char *out)
{
    time_t yj_time_now_int;
    struct tm *yj_time_now_struct;
    char temp[100];

    yj_time_now_int = time(NULL);
    yj_time_now_struct = localtime(&yj_time_now_int);

    sprintf(temp, "%d", yj_time_now_struct->tm_year + 1900);
    strcat(out, temp);    
    strcat(out, "/");    

    sprintf(temp, "%d", yj_time_now_struct->tm_mon);
    strcat(out, temp);    
    strcat(out, "/");

    sprintf(temp, "%d", yj_time_now_struct->tm_mday);
    strcat(out, temp);    

    strcat(out, " ~ ");

    sprintf(temp, "%d", yj_time_now_struct->tm_year + 1900);
    strcat(out, temp);    
    strcat(out, "/");    

    sprintf(temp, "%d", yj_time_now_struct->tm_mon);
    strcat(out, temp);    
    strcat(out, "/");
    
    sprintf(temp, "%d", yj_time_now_struct->tm_mday + 10);
    strcat(out, temp);    
}