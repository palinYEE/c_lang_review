#include<stdio.h>

typedef struct grade
{
    int num, kor, eng, mat, total;
    double avg;
} GRADE;

int main(){
    int i, j;
    GRADE man[5], temp;
    double avgKor = 0.0, avgEng=0.0, avgMat = 0.0;

    for(i=0; i<5; i++){
        printf("%d번째 학생의 학번 : ", i+1);
        scanf("%d", &(man+i)->num);
        printf("국어 점수 : "); scanf("%d", &(man+i)->kor);
        printf("영어 점수 : "); scanf("%d", &(man+i)->eng);
        printf("수학 점수 : "); scanf("%d", &(man+i)->mat);

        (man+i)->total = (man+i)->kor + (man+i)->eng + (man+i)->mat;
        (man+i)->avg = ((man+i)->total)/3.0;

        avgKor += (man+i)->kor;
        avgEng += (man+i)->eng;
        avgMat += (man+i)->mat;
    }

    for(i=0; i<4; i++){
        for(j=i; j<5; j++){
            if((man+i)->total < (man+j)->total){
                temp = *(man+i);
                *(man+i) = *(man+j);
                *(man+j) = temp;
            }
        }
    }
    printf("\n================================================\n");
    printf("    학번    국어    영어    수학    총점    평균\n");

    for(i=0; i<5; i++){
        printf("%8d %6d %6d %6d %6d %7.2f\n", (man+i)->num,(man+i)->kor, (man+i)->eng, (man+i)->mat, (man+i)->total, (man+i)->avg);
    }
    printf("    국어 평균 : %7.2f\n", avgKor/5.0);
    printf("    영어 평균 : %7.2f\n", avgEng/5.0);
    printf("    수학 평균 : %7.2f\n", avgMat/5.0);
}
