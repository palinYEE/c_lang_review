/* ------------- */
// local header
#include "problem.h"
#include "yj_time.h"

/* ------------- */
// global header
#include <stdlib.h>

void print_prob_info(){
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@                        @\n");
    printf("@ YYJ C Langage Practice @\n");
    printf("@                        @\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("[*] SOLVE DATE : %s\n", SOLV_DATE);
    printf("[*] PROBLEM CONTENT\n");
    printf("    - %s\n", PROB_content);
    printf("[*] EXAMPLE\n");
    printf("    - INPUT : %s\n", EX_input);
    printf("    - OUTPUT : %s\n", EX_output);
}

int search_baseball(int *arr, int num, int num_index){
    int ret = 0;
    int arr_index;

    for(arr_index = 0; arr_index < 3; arr_index++){
        if(*(arr + arr_index) == num){
            ret = BALL;
            if(arr_index == num){
                ret = STRIKE;
            }
        }
    }
    return ret;
}

void baseball_game(){
    /* value setting */
    int baseball_answer[3] = {0, };        // baseball answer
    int user_answer[3] = {0, };            // user answer
    int ball_count, strike_count, try_count=0;          // ball and strike count value and try count value
    int i;                                 // loop value
    int temp = 0;                          // temp value
    char user_check = '\0';                       // user yes or no

    /* check time to start playing */
    yj_time_print();

    /* setting random baseball number */
    srand(time(NULL));
    for(i=0; i<3; i++){
        baseball_answer[i] = rand() % 10;
    }

    /* game start */
    while(1){
        /* hint */
        if(try_count == 6){
            printf("hint! : first value is %d\n", baseball_answer[0]);
        }else if(try_count == 10){
            printf("hint : secont value is %d\n", baseball_answer[1]);
        }else if(try_count > 15){
LOSE:
            printf("you lose... answer is ");
            for(i=0; i<3; i++){
                printf("%d ", baseball_answer[i]);
            }
            printf("\n");
            break;
        }

        /* count value setting */
        try_count += 1;
        ball_count = 0; strike_count = 0;

        printf("===============================\n");
        for(i=0; i<3; i++){
            printf("[%d] Input user answer : ", i);
            scanf("%d", user_answer + i);
        }

        for(i=0; i<3; i++){
            temp = search_baseball(baseball_answer, *(user_answer + i), i);
            if(temp == STRIKE){
                strike_count += 1;
            }else if (temp == BALL)
            {
                ball_count += 1;
            }
            
        }
        printf(" -- result : %d strike %d ball\n ", strike_count, ball_count);
        if(strike_count == 3){
            printf("you win!!!\n");
            break;
        }
        printf("Do you want to show answer? (y/n): ");
        fflush(stdin);
        scanf("%c", &user_check);

        if(user_check == 'y'){
            goto LOSE;
        }

    }
}