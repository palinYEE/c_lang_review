#ifndef DVD_INIT_H
#define DVD_INIT_H

#define MAX_CHAR_LENGTH 100
#define MAX_TABLE_SIZE 100

#include<time.h>

typedef struct yj_dvd_user_st
{
    char *user_name;        // 이름
    char *phone_number;     // 핸드폰 번호
}YJ_DVD_USER_ST;

typedef struct yj_dvd_info_st
{
    int ISBN;             // isbn 코드  <-- 이거는 6자리 숫자 랜덤 값으로 셋팅하자.
    char *title;            // 제목
    char *genre;            // 장르
    char *release_year;      // 출시 년도

    struct YJ_DVD_INFO_ST *next;   // DVD 링크드 리스트
}YJ_DVD_INFO_ST;

typedef struct yj_rental_info_st
{
    char *title;            // DVD 제목
    struct tm* rental_date;      // 대여 날짜
    struct tm* return_date;      // 반납 날짜
    time_t rental_date_time_t;   // 대여 날짜 time_t
    time_t return_date_time_t;   // 반납 날짜 time_t
    char *lotus_check;      // 연채 여부
}YJ_RENTAL_INFO_ST;

typedef struct yj_st_manage_table
{
    struct YJ_DVD_USER_ST *user_st;            // 유저 정보 구조체 
    // YJ_DVD_INFO_ST *dvd_info_st;        // dvd 정보 관리 구조체
    struct YJ_RENTAL_INFO_ST *rental_info_st;  // 대여 정보 관리 구조체
    struct YJ_ST_MANAGE_TABLE *next;           // 다음 MANAGE_TABLE 링크드 리스트 
}YJ_ST_MANAGE_TABLE;

/**
 * @brief 유저가 사용하는 구조체를 셋팅해주는 함수
 * 
 * @param in 유저 전용 구조체 (YJ_ST_MANAGE_TABLE)
 */
void yj_dvd_st_init(YJ_ST_MANAGE_TABLE *in);

/**
 * @brief dvd server 전용 구조체를 셋팅해주는 함수
 * 
 * @param in dvd 전용 구조체 (YJ_DVD_INFO_ST)
 */
void yj_dvd_server_init(YJ_DVD_INFO_ST *in);

#else
#endif