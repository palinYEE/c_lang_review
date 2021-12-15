/* ------------- */
// local header
#include "problem.h"
#include "yj_time.h"

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

void sol(){
    /* value setting */
    int baseball_answer[3] = {0, };        // baseball answer
    int user_answer[3] = {0, };            // user answer
    int ball_count, strike_count;          // ball and strike count value
    int i;                                 // loop value
    int temp = 0;                          // temp value

    /* check time to start playing */
    yj_time_print();

    /* setting random baseball number */
    srand(time(NULL));
    for(i=0; i<3; i++){
        baseball_answer[i] = rand() % 10;
    }

    /* game start */
    while(1){
        ball_count = 0; strike_count = 0;

        for(i=0; i<3; i++){
            printf("[%d] Input user answer : ", i);
            scanf("%d", *(user_answer + i));
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
            break;
        }
    }
}