#include "phone_book.h"
#include "yj_time.h"
#include "yj_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    PHONE_BOOK_ST *book_list[MAX_PHONE_BOOK_NUM];
    char delete_name[MAX_NAME_LEN] = {0, };
    char delete_phone[MAX_PHONE_NUMBER_LEN] = {0, };
    int choice = 0;
    int count = 0;      // 전화번호부 카운트
    int del_result;     // 삭제 여부 확인

    for(int i=0; i<MAX_PHONE_BOOK_NUM; i++){
        book_list[i] = malloc(sizeof(PHONE_BOOK_ST));
    }
    
    while(1){
        print_info();
        printf("1. 새로운 전화번호 입력\n");
        printf("2. 기존 전화번호 삭제\n");
        printf("3. 전화번호 전체 목록 출력\n");
        printf("0. 종료\n");
        printf("-- 입력된 전화번호 개수 : %d\n", count);
        printf("-- 항목을 선택하세요 : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0: 
            break;
        case 1:
            new_phone_number(book_list[count], book_list[count + 1]);
            count += 1;
            break;
        case 2:
            printf("        - 삭제할 전화번호 이름 : ");
            scanf("%s", delete_name);
            printf("        - 삭제할 전화번호 : ");
            scanf("%s", delete_phone);
            del_result = delete_phone_number(book_list[0], delete_name, delete_phone);
            if(del_result == OK){
                printf(" -- 삭제 성공\n");
                count -= 1;
            }else if (del_result == NO){
                printf(" -- 삭제 실패\n");
            }else{
                printf("ERROR!!!\n");
            }
            break;
        case 3:
            print_all_phone_number(book_list[0], count);
            break;
        default:
            printf("ERROR!! 인자 값을 잘못 입력하였습니다. \n");
            break;
        }
    }
    
    for(int i=0; i<MAX_PHONE_BOOK_NUM; i++){
        free(book_list[i]);
    }
    return 0;   

}