#ifndef PROBLEM_H   // basic header call
#define PROBLEM_H   // basic header call

// definition value setting
#define SOLV_DATE ""    // Date to solve problem
#define PROB_content "" // Problem Content
#define EX_input ""     // Example input
#define EX_output ""    // Example output

// definition mecro function setting
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) > (b) ? (b) : (a))

// Header
#include<stdio.h>
#include<stdlib.h>

// Function
/**
 * @brief Print problem info
 * @param None
 * @return SOLV_DATE(문제를 푼 날짜), PROB_content(문제 정보)
 */
void print_prob_info();

/**
 * @brief Function of problem to solve
 * @param in_arr 입력 배열 포인터
 * @param in_arr_size 배열 크기
 * @return out_arr 결과 배열 포인터 (out_arr[0] : MAX, out_arr[1] : MIN)
 */
void sol(int *in_arr, int in_arr_size, int *out_arr);


#else
#endif
