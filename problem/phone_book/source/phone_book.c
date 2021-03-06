#include "phone_book.h"
#include "yj_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void print_phone_st(PHONE_BOOK_ST *in){
    printf(" | 이름 : %2s | 전화번호 : %2s |\n", in->name, in->phone_number);
}

void print_next_phone_st(PHONE_BOOK_ST *in){
    PHONE_BOOK_ST *temp = in->next;
    print_phone_st(temp);
}

void new_phone_number(PHONE_BOOK_ST *org, PHONE_BOOK_ST *new){
    char choice = '\0';
INPUT_ERROR:;
    printf("=========================================\n");
    printf("[-] 새로운 전화번호를 생성합니다. 다음 정보들을 입력하세요.\n");
    new->name = malloc(sizeof(char) * MAX_NAME_LEN);
    new->phone_number = malloc(sizeof(char) * MAX_PHONE_NUMBER_LEN);
    printf("        - 이름 : ");
    scanf("%s", new->name);
    printf("        - 전화번호 : ");
    scanf("%s", new->phone_number);
    printf("[-] 다음 정보를 확인하세요 \n");
    print_phone_st(new);
    printf(" -- 입력한 정보가 맞습니까? (y/n) : ");
    fflush(stdin);
    scanf("%c", &choice);
    fflush(stdin);
    if(choice != 'y'){
        goto INPUT_ERROR;
    }
    else{
        org->next = new;
    }
}

int delete_phone_number(PHONE_BOOK_ST *start, char *name, char * phone_number){
    if(name == NULL || phone_number == NULL){
        printf("ERROR : 이름 값 또는 핸드폰 번호가 입력되지 않았습니다. \n");
        return NO;
    }
    PHONE_BOOK_ST *temp;
    while(1){
        temp = start->next;
        if((yj_cmp_str(temp->name, name) + yj_cmp_str(temp->phone_number, phone_number)) == 0){
            /* terminate struct value */
            start->next = temp->next;
            free(temp->name);
            free(temp->phone_number);
            free(temp);
            return OK;
        }
    }
}

void print_all_phone_number(PHONE_BOOK_ST *start, int count){
    int i;      // loop value
    PHONE_BOOK_ST *temp = start;
    for(i=1; i<=count; i++){
        print_next_phone_st(temp);
        temp = temp->next;
    }
}

void find_data_from_name(PHONE_BOOK_ST *start, char *name, int count){
    PHONE_BOOK_ST *temp = start->next;
    int flag = 0;
    for(int i=1; i<=count; i++){
        if(yj_cmp_str(temp->name, name) == 0){
            flag = 1;
            print_phone_st(temp);
        }
        temp = temp->next;
    }
    if(flag == 0){
        printf("데이터가 존재하지 않습니다. \n");
    }
}

void find_data_from_phone_number(PHONE_BOOK_ST *start, char *phone_number, int count){
    PHONE_BOOK_ST *temp = start->next;
    int flag = 0;
    for(int i=1; i<=count; i++){
        if(yj_cmp_str(temp->phone_number, phone_number) == 0){
            flag = 1;
            print_phone_st(temp);
        }
        temp = temp->next;
    }
    if(flag == 0){
        printf("데이터가 존재하지 않습니다. \n");
    }
}

void save_phone_book(PHONE_BOOK_ST *start, char *filename, int *count){
    FILE *fp;
    PHONE_BOOK_ST *temp = start->next;
    int i;
    fp = fopen(filename, "a");

    for(i=1; i<=*count; i++){
        fprintf(fp, "%s\n", temp->name);
        fprintf(fp, "%s\n", temp->phone_number);
        fprintf(fp, "==\n");
        temp->name = NULL;
        temp->phone_number = NULL;
        temp = temp->next;
    }
    *count = 0;
    fclose(fp);
}

void load_phone_book(PHONE_BOOK_ST *start, char *filename,int *count){
    FILE *fp; 
    char data[100];
    int flag = 0;
    PHONE_BOOK_ST *temp = start;
    PHONE_BOOK_ST *temp2 = start->next;

    fp = fopen(filename, "r");
    while(fgets(data, sizeof(data), fp) != NULL){
        data[strlen(data) - 1] = NULL;
        printf("org : %s\n", data);
        if(strcmp(data, "==")){
            if(flag == 0 ){
                temp2->name = data;
                printf("temp2->name : %s\n", temp2->name
                );
                flag++;
                *count = *count + 1;
            }
            else if(flag == 1){
                temp2->phone_number = data;
                printf("temp->phone_number : %s\n", temp2->phone_number);
                flag = 0;
                *count = *count + 1;

                temp = temp2;
                temp2 = temp2 + sizeof(PHONE_BOOK_ST);
                temp->next = temp2; 
            }
        }
    }
    fclose(fp);
}