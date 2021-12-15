/* ------------------ */
// local header
#include "problem.h"

/* ------------------ */
// global header
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


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

void random_dice(){
    int i, temp;      // loop value and temp value setting 
    int arr[6] = {0, };

    srand(time(NULL));
    for(i=0; i<100; i++){
        temp = rand()%6;
        arr[temp] += 1;
    }
    printf("===============\n");
    printf("[*] Show dice result \n");
    for(i=0; i<6; i++){
        printf(" - %d번 : %d\n", i+1, arr[i]);
    }
}