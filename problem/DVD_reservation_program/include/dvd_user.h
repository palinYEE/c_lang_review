#ifndef DVD_USER_H
#define DVD_USER_H

#include "dvd_init.h"
#include "dvd_server.h"

#define NOT_FOUND -1

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
 * @brief 데이터를 삭제하는 함수. 이때 삭제할 데이터와 맨 뒤에 있는 데이터를 스왑한 후. 맨 뒤에있는 데이터를 삭제하는 로직으로 설계되어있다. 
 * 
 * @param dvd_user_table 유저 데이터 구조체
 * @param count 유저 데이터 개수
 * @param delete_index 삭제할 데이터 인덱스
 */
void delete_user_data(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE], int *count, int delete_index);

/**
 * @brief 유저 이름으로 테이블에 검색하는 함수
 * 
 * @param dvd_user_table 유저 데이터 구조체 
 * @param count 유저 데이터 개수
 * @param find_name 찾을 유저 이름
 * @return int 찾을 유저 데이터가 있는 인덱스 (만약 데이터가 없으면 NOT_FOUND가 반환)
 */
int find_user_data_from_name(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE],int *count ,char *find_name);


/**
 * @brief 전화번호를 기준으로 테이블에 검색하는 함수
 * 
 * @param dvd_user_table 유저 데이터 구조체
 * @param count 유저 데이터 캐수
 * @param find_phone_number 찾을 유저 이름
 * @return int 찾을 유저 데이터가 있는 인덱스 (만약 데이터가 없으면 NOT_FOUND 가 반환)
 */
int find_user_data_from_phone_number(YJ_ST_MANAGE_TABLE *dvd_user_table[MAX_TABLE_SIZE],int *count ,char *find_phone_number);


/**
 * @brief dvd 빌리는 함수
 * 
 * @param in 빌릴 사람에 대한 구조체
 * @param dvd_root_table dvd 구조체 테이블
 */
void input_rent_info(YJ_ST_MANAGE_TABLE *in, YJ_DVD_INFO_ST *dvd_root_table[MAX_DVD_NUM]);

#else
#endif