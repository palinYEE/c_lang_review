#include "problem.h"

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

void sol(int *in_arr, int in_arr_size, int *out_arr){
    int i;
    // initial value setting
    *out_arr = *in_arr; 
    *(out_arr+1) = *in_arr;

    for(i = 1; i < in_arr_size; i++){
        // max check
        *out_arr = MAX(*out_arr, *(in_arr + i));
        // min check
        *(out_arr + 1) = MIN(*(out_arr + 1), *(in_arr + i));
    }
}
