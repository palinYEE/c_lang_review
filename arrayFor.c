#include<stdio.h>

int main(){
    int i, j, num[5], kor[5], eng[5], mat[5], total[5], temp;
    double avgKor=0.0, avgEng = 0.0, avgMat=0.0, avgTemp;

    double avg[5];

    for(i=0; i<5; i++){
        printf("%d 번째 학생의 학번 : ", i+1); scanf("%d", num+i);
        printf("국어 점수 : "); scanf("%d", kor+i);
        printf("영어 점수 : "); scanf("%d", eng+i);
        printf("수학 점수 : "); scanf("%d", mat+i);

        total[i] = kor[i] + eng[i] + mat[i];
        avg[i] = total[i]/3.0;
        
        avgKor += kor[i];
        avgEng += eng[i];
        avgMat += mat[i];
    }

    for(i=0; i<4; i++){
        for(j=i+1; j<5; j++){
            if(*(total + i) < *(total + j)){
                temp = *(num + i);
                *(num + i) = *(num + j);
                *(num + j) = temp;

                temp = *(kor + i); *(kor + i) = *(kor + j); *(kor + j) = temp;
                temp = *(eng + i); *(eng + i) = *(eng + j); *(eng + j) = temp;
                temp = *(kor + i); *(mat + i) = *(mat + j); *(mat + j) = temp;

                temp = *(total + i); *(total + i) = *(total + j); *(total + j) = temp;

                avgTemp = *(avg + i); *(avg + i) = *(avg + j); *(avg + j) = avgTemp;
            }
        }
    }
    printf("\n================================================\n");
    printf("    학번    국어    영어    수학    총점    평균\n");

    for(i=0; i<5; i++){
        printf("%8d %6d %6d %6d %6d %7.2f\n", *(num+i),*(kor+i), *(eng+i), *(mat+i), *(total+i), *(avg + i));
    }
    printf("    국어 평균 : %7.2f\n", avgKor/5.0);
    printf("    영어 평균 : %7.2f\n", avgEng/5.0);
    printf("    수학 평균 : %7.2f\n", avgMat/5.0);
}