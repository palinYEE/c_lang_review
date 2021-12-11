#include <stdio.h>
#include <stdlib.h>
#include "int_set.h"

int main(){
    SET_CONT s1, s2, s3;
    Initialize(&s1, 24);
    Initialize(&s2, 24);
    Initialize(&s3, 24);

    Add(&s1, 10);
    Add(&s1, 15);
    Add(&s1, 20);
    Add(&s1, 15);

    Assign(&s2, &s1);
    Add(&s2, 12);
    Remove(&s2, 20);
    Assign(&s3, &s2);

    printf("s1 = "); PrintLn(&s1);
    printf("s2 = "); PrintLn(&s2);
    printf("s3 = "); PrintLn(&s3);

    printf("집합 s1에 15가 들어있%s.\n", IsMember(&s1, 15) == OK ? "습니다." : "지 않습니다.");
    printf("집합 s2에 25가 들어있%s.\n", IsMember(&s2, 25) == OK ? "습니다." : "지 않습니다.");
    printf("집합 s1과 s2는 서로 같%s.\n", Equal(&s1, &s2) == OK ? "습니다." : "지 않습니다.");
    printf("집합 s2과 s3는 서로 같%s.\n", Equal(&s2, &s3) == OK ? "습니다." : "지 않습니다.");

    Terminate(&s1);
    Terminate(&s2);
    Terminate(&s3);

    
    return 0;
}