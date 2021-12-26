#ifndef DVD_SERVER_H
#define DVD_SERVER_H

#include "dvd_init.h"

#define MAX_DVD_NUM 100

/**
 * @brief DVD 데이터를 넣어주는 함수
 * 
 * @param in DVD 데이터가 넣어질 구조체
 */
void input_dvd_data(YJ_DVD_INFO_ST *in);

/**
 * @brief DVD 데이터 리스트를 출력하는 함수
 * 
 * @param in DVD 데이터 구조체
 */
void print_dvd_list(YJ_DVD_INFO_ST *in);

#else
#endif