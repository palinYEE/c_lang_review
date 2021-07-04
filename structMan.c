#include<stdio.h>

struct Man
{
    char name[10];
    int age;
    double weight;
};

typedef struct score
{
    char hackbun[10];
    char name[10];
    int kor, eng, tot;
    double ave;
} SCORE;

int main(){
    struct Man gildong, yyj, sunhee[20];
    SCORE h = {
        "20152008",
        "영진",
        80,
        90
    };
    
    // 그냥 struct로 할 경우
    gildong.age=20;
    yyj.weight=67.5;

    sunhee[0].age=25;

    printf("%d %f %d\n",
                    gildong.age, yyj.weight, sunhee[0].age);

    // typedef 사용
    h.tot = h.kor + h.eng;
    printf("%s %s %d %d %d %f\n", h.hackbun, h.name, h.kor, h.eng, h.tot, h.ave);
    return 0;
}