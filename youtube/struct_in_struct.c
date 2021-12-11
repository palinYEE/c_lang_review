/*
 * 해당 예시는 구조체 안에 구조체를 선언해서 사용할 수 있음을 볼 수 있다. 
*/
#include<stdio.h>

#define ABS(a) ( (a) > 0 ? a : -a)  // 절대값 계산 메크로 함수

struct point
{
    int x;
    int y;
};

struct rect
{
    struct point p1;
    struct point p2;
};

int main(void){
    struct rect r;
    int w, h, area, peri;

    printf("왼쪽 상단의 좌표를 입력하시오: ");
    scanf("%d %d", &r.p1.x, &r.p1.y);

    printf("오른쪽 하단의 좌표를 입력하시오: ");
    scanf("%d %d", &r.p2.x, &r.p2.y);

    w = r.p2.x - r.p1.x;
    h = r.p2.y - r.p1.y;

    w = ABS(w);
    h = ABS(h);

    area = w * h;
    peri = 2*w + 2*h;

    printf("사각형의 면적은 %d이고 둘레는 %d입니다. \n", area, peri);
}
