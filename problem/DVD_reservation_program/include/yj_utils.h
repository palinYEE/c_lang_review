#ifndef YJ_UTILS_H
#define YJ_UTILS_H

#include <time.h>

/**
 * @brief YJ_RENTAL_INFO_ST 구조체의 대여 기간을 셋팅해주는 함수
 * 
 * @param out 현재 시간을 담을 YJ_RENTAL_INFO_ST 구조체
 */
void yj_setting_rental_time(YJ_RENTAL_INFO_ST *out);

#else
#endif