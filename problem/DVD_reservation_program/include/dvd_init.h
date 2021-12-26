#ifndef DVD_INIT_H
#define DVD_INIT_H

#define MAX_CHAR_LENGTH 100
#define MAX_TABLE_SIZE 100


typedef struct yj_dvd_user_st
{
    char *user_name;        // 이름
    char *phone_number;     // 핸드폰 번호
}YJ_DVD_USER_ST;

typedef struct yj_dvd_info_st
{
    char *ISBN;             // isbn 코드
    char *title;            // 제목
    char *genre;            // 장르
    char *release_year      // 출시 년도

    YJ_DVD_INFO_ST *next;   // DVD 링크드 리스트
}YJ_DVD_INFO_ST;

typedef struct yj_rental_info_st
{
    char *title;            // DVD 제목
    char *user_name;        // 대여자 이름
    char *rental_date;      // 대여 날짜
    char *return_date;      // 반납 날짜
    char *lotus_check;      // 연채 여부
}YJ_RENTAL_INFO_ST;

typedef struct yj_st_manage_table
{
    YJ_DVD_USER_ST *user_st;            // 유저 정보 구조체 
    // YJ_DVD_INFO_ST *dvd_info_st;        // dvd 정보 관리 구조체
    YJ_RENTAL_INFO_ST *rental_info_st;  // 대여 정보 관리 구조체
    YJ_ST_MANAGE_TABLE *next;           // 다음 MANAGE_TABLE 링크드 리스트 
}YJ_ST_MANAGE_TABLE;


void yj_dvd_st_init(YJ_ST_MANAGE_TABLE *in);

#else
#endif