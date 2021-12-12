#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "int_set.h"
#include "yyj.h"

enum { ADD, RMV, SCH };

int scan_data(int sw)
{
    int data;
    switch (sw)
    {
    case ADD: printf("추가할 데이터 : "); break;
    case RMV: printf("삭제할 데이터 : "); break;
    case SCH: printf("검색할 데이터 : "); break;
    default: printf("인자를 잘못 입력하였습니다. \n"); return NO;
    }
    scanf("%d", &data);

    return data;
}

int main(){
    yyj_example_info_printf();
    if(MODE == 1){
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

        printf("집합 s1에 15가 들어있%s.\n", IsMember(&s1, 15) != NO ? "습니다." : "지 않습니다.");
        printf("집합 s2에 25가 들어있%s.\n", IsMember(&s2, 25) != NO ? "습니다." : "지 않습니다.");
        printf("집합 s1과 s2는 서로 같%s.\n", Equal(&s1, &s2) == OK ? "습니다." : "지 않습니다.");
        printf("집합 s2과 s3는 서로 같%s.\n", Equal(&s2, &s3) == OK ? "습니다." : "지 않습니다.");

        Terminate(&s1);
        Terminate(&s2);
        Terminate(&s3);
    }
    else if(MODE == 2){
        SET_CONT s1, s2, temp;
        Initialize(&s1, 512); 
        Initialize(&s2, 512); 
        Initialize(&temp, 512); 

        while(1){
            int m, x, idx; 

            printf("s1 = "); PrintLn(&s1);
            printf("s2 = "); PrintLn(&s2);
            printf("==========================\n");
            printf("(1) s1에 추가\n");
            printf("(2) s1에서 삭제\n");
            printf("(3) s1에서 검색\n");
            printf("(4) s1 + s2\n");
            printf("(5) 여러 연산 \n");
            printf("(6) s2에 추가\n");
            printf("(7) s2에서 삭제\n");
            printf("(8) s2에서 검색\n");
            printf("(9) s2 + s1\n");
            printf("(0) 종료\n");

            printf("선택 : ");
            scanf("%d", &m);
            if(m == 0){
                system("clear");
                printf("프로그램을 종료합니다. \n");
                break;
            }
            switch (m)
            {
            case 1: 
                x = scan_data(ADD); 
                Add(&s1, x); 
                system("clear");
                break;
            case 2: 
                x = scan_data(RMV); 
                Remove(&s1, x); 
                system("clear");
                break;
            case 3: 
                system("clear");
                x = scan_data(SCH); 
                idx = IsMember(&s1, x); 
                if(idx >=0){
                    printf("%d 값은 s1의 %d에 있습니다. \n", x, idx);
                }else{
                    printf("%d 값은 s1에 존재하지 않습니다. \n", x);
                }
                break;
            case 4:
                Assign(&s1, &s2);
                system("clear");
                break;
            case 5:
                system("clear");
                printf("s1 == s2 = %s \n", Equal(&s1, &s2) ? "true" : "false" );
                printf("s1 & s2 = ");
                Intersection(&temp, &s1, &s2);
                PrintLn(&temp);
                printf("s1 | s2 = ");
                Union(&temp, &s1, &s2);
                PrintLn(&temp);
                printf("s1 - s2 = ");
                Difference(&temp, &s1, &s2);
                PrintLn(&temp);
                break;
            case 6: 
                x = scan_data(ADD);
                Add(&s2, x);
                system("clear");
                break;
            case 7:
                x = scan_data(RMV);
                Remove(&s1, x);
                system("clear");
                break;
            case 8:
                system("clear");
                x = scan_data(SCH);
                idx = IsMember(&s2, x); 
                if(idx >=0){
                    printf("%d 값은 s2의 %d에 있습니다. \n", x, idx);
                }else{
                    printf("%d 값은 s2에 존재하지 않습니다. \n",x);
                }
                break;
            case 9:
                Assign(&s2, &s1);
                system("clear");
                break;
            default:
                printf("다시 선택하세요.\n");
                system("clear");
                break;
            }
        }
        Terminate(&s1);
        Terminate(&s2);
        Terminate(&temp);
    }
    else{
        printf("인자 값이 잘못되었습니다. (%d)\n", MODE);
        system("clear");
    }
    
    return 0;
}