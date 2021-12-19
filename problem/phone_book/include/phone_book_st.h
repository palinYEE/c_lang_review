#ifndef PHONE_BOOK_ST_H
#define PHONE_BOOK_ST_H

#define OK 1
#define NO 0

#define MAX_PHONE_BOOK_NUM 100  // 전화번호 최대 저장 갯수
#define MAX_NAME_LEN 10         // 입력 이름 최대 길이
#define MAX_PHONE_NUMBER_LEN 20 // 입력 전화번호 최대 길이

typedef struct phone_book
{
    char *name;                  // 이름
    char *phone_number;          // 전화번호 
    struct phone_book *next;     // 링크드 리스트
} PHONE_BOOK_ST;

#else
#endif