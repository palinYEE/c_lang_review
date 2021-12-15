#ifndef PROBLEM_H
#define PROBLEM_H

#define SOLV_DATE ""
#define PROB_content ""
#define EX_input ""
#define EX_output ""

#define STRIKE -100
#define BALL -200

/**
 * @brief  Print problem info
 * @param None
 * @return SOLV_DATE(문제를 푼 날짜), PROB_content(문제 정보)
 */
void print_prob_info();

/**
 * @brief check strike or ball 
 * 
 * @param arr 정답 배열
 * @param num 사용자가 입력한 수 
 * @param num_index     사용자가 입력한 수의 인덱스
 * @return int STRIKE or BALL or 0 (아에 틀림)
 */
int search_baseball(int *arr, int num, int num_index);

/**
 * @brief baseball game function
 * 
 * @return 결과 종료 할 때 까지 게임 진행
 */
void baseball_game();

#else
#endif