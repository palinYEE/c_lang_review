#ifndef DVD_USER_H
#define DVD_USER_H

#include "dvd_init.h"

/**
 * @brief 고객 정보를 print 하는 함수
 * 
 * @param in 입력 YJ_ST_MANAGE_TABLE 구조체
 */
void print_user_list(YJ_ST_MANAGE_TABLE *in);

/**
 * @brief 유저 정보를 입력하는 함수
 * 
 * @param in 입력될 YJ_DVD_USER_ST 구조체
 */
void input_user_data(YJ_DVD_USER_ST *in);

/**
 * @brief 유저 정보 삭제 함수
 * 
 * @param in 삭제할 유저 구조체
 * @param count 전체 유저 개수
 */
void delete_user_data(YJ_DVD_USER_ST *in, int *count);
#else
#endif