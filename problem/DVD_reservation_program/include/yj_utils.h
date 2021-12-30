#ifndef YJ_UTILS_H
#define YJ_UTILS_H

#include <time.h>
#include "dvd_init.h"

/**
 * @brief YJ_RENTAL_INFO_ST 구조체의 대여 기간을 셋팅해주는 함수
 * 
 * @param out 현재 시간을 담을 YJ_RENTAL_INFO_ST 구조체
 */
void yj_setting_rental_time(YJ_RENTAL_INFO_ST *out);

/**
 * @brief dvd 모든 정보를 파일로 저장하는 코드 
 * 
 * @param dvd_user_table 유저 정보를 가지고 있는 구조체
 * @param dvd_root_table dvd 정보를 가지고 있는 구조체
 * @param file_name      저장할 파일 이름
 */
void extraction_data_file(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE], YJ_DVD_INFO_ST *dvd_root_table[MAX_DVD_NUM], char *file_name)

#else
#endif