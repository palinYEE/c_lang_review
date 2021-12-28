#ifndef DVD_SERVER_H
#define DVD_SERVER_H

#include "dvd_init.h"
#include "dvd_user.h"

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

/**
 * @brief 유저 데이터 중에서 연채된 것들이 있는지 확인하는 함수
 * 
 * @param dvd_user_table 유저 데이터 테이블
 * @param count 유저 데이터 수 
 */
void check_lotus_user(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE], int *count);

#else
#endif