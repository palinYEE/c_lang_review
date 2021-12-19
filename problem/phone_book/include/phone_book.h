#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include "phone_book_st.h"

/**
 * @brief PHONE_BOOK_ST에 있는 변수 값들을 출력해주는 함수
 * 
 * @param in 입력 PHONE_BOOK_ST 구조체
 */
void print_phone_st(PHONE_BOOK_ST *in);

/**
 * @brief 다음 연결된 구조체의 변수 값을 출력해주는 함수
 * 
 * @param in 입력 PHONE_BOOK_ST 구조체
 */
void print_next_phone_st(PHONE_BOOK_ST *in);

/**
 * @brief 새로운 구조체를 셋팅하고 org->next 값을 넣는다.
 *  
 * @param new 새로운 전화번호 구조체
 */
void new_phone_number(PHONE_BOOK_ST *org, PHONE_BOOK_ST *new);

/**
 * @brief 기존 전화번호 삭제하는 함수
 * 
 * @param start 시작 구조체 
 * @param name  삭제할 전화번호의 이름
 * @param phone_number 삭제할 전화번호 
 * @return int 
 */
int delete_phone_number(PHONE_BOOK_ST *start, char *name, char * phone_number);

/**
 * @brief 전화번호 전체 목록 출력 함수
 * 
 * @param start 시작 구조체
 * @param count 전화번호부에 입력되어있는 데이터 개수
 */
void print_all_phone_number(PHONE_BOOK_ST *start, int count);


#else
#endif