#ifndef SET_CONT_H
#define SET_CONT_H

struct set_cont
{
    int max;    /* 집합의 최대 크기 */
    int num;    /* 집합의 원소 개수 */
    int *set;   /* 집합 */
};
typedef struct set_cont SET_CONT;


#define OK 1    /* 성공 */
#define NO -1    /* 실패 */

#else
#endif