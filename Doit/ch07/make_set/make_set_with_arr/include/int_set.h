#ifndef INT_SET_H
#define INT_SET_H

#include "set_cont.h"

// Finction
/**
 * @brief 집합을 초기화 하는 함수
 * @param s 집합을 관리하는 구조체의 포인터
 * @param max 집합의 최대 크기
 * @return 초기화된 구조체 SET_CONT
*/
int Initialize(SET_CONT *s, int max);

/**
 * @brief 집합 s에 n이 들어있는지 확인
 * @param s 집합을 관리하는 구조체의 포인터
 * @param n 집합에 들어가있는지 확인할 원소
 * @return n 값이 집합에 들어있는지 여부 
*/
int IsMember(const SET_CONT *s , int n);

/**
 * @brief 집합 s에 n을 추가하는 함수
 * @param s 집합을 관리하는 구조체의 포인터
 * @param n 집합에 추가할 원소
 * @return n값이 추가된 집합 s
*/
void Add(SET_CONT *s, int n);

/**
 * @brief 집합 s에 n을 제거하는 함수
 * @param s 집합을 관리하는 구조체의 포인터
 * @param n 집합에 제거할 원소
 * @return n값이 제거된 집합 s
*/
void Remove(SET_CONT *s, int n);

/**
 * @brief 집합 s에 넣을 수 잇는 최대의 원소 개수를 반환하는 함수
 * @param s 집합을 관리하는 구조체의 포인터
 * @return 최대 원소 개수
*/
int Capacity(const SET_CONT *s);

/**
 * @brief 집합 s의 원소 개수 반환
 * @param s 집합을 관리하는 구조체의 포인터
 * @return 집합 s의 원소 개수 반환
*/
int Size(const SET_CONT *s);

/**
 * @brief 집합 s2를 s1에 대입
 * @param s1 대입될 집합 구조체 포인터
 * @param s2 대입할 집합 구조체 포인터
 * @return s2가 대입된 s1 
*/
void Assign(SET_CONT *s1, const SET_CONT *s2);

/**
 * @brief 집합 s1과 s2가 같은지 확인하는 함수 
 * @param s1 집합 포인터
 * @param s2 집합 포인터
 * @return 같은지 여부 
*/
int Equal(const SET_CONT *s1, const SET_CONT *s2);

/** 
 * @brief 집합 s2와 s3의 합집합을 s1에 대입하는 함수 
 * @param s1 s2와 s3의 합집합
 * @param s2 집합 구조체
 * @param s3 집합 구조체
 * @return s2와 s3의 합집합
*/
SET_CONT *Union(SET_CONT *s1, const SET_CONT *s2, const SET_CONT *s3);

/**
 * @brief 집합 s2와 s3의 교집합을 s1에 대입
 * @param s1 s2와 s3의 교집합
 * @param s2 집합 구조체
 * @param s3 집합 구조체
 * @return s2와 s3의 교집합
*/
SET_CONT *Intersection(SET_CONT *s1, const SET_CONT *s2, const SET_CONT *s3);

/**
 * @brief 집합 s2에서 s3을 뺀 차집합을 s1에 대입 
 * @param s1 s2 - s3
 * @param s2 집합 구조체
 * @param s3 집합 구조체
 * @return s2 - s3
 */
SET_CONT *Difference(SET_CONT *s1, const SET_CONT *s2, const SET_CONT *s3);

/**
 * @brief 집합 s의 모든 원소를 출력
 * @param s 출력할 집합 구조체
 */
void Print(const SET_CONT *s);

/**
 * @brief 집합 s의 모든 원소를 출력 (줄 바꿈 문자 포함)
 * @param s 출력할 집합 구조체
 */
void PrintLn(const SET_CONT *s);

/**
 * @brief 집합 종료
 * @param s 종료할 집합 구조체
 */
void Terminate(SET_CONT *s);

#else
#endif