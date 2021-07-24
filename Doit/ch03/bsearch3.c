#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//setting struct
typedef struct
{
    char name[10];   // 이름
    int height;      // 키
    int weight;       // 몸무게
}Person;

// 비교 함수
int npcmp(const Person *a, const Person *b){
    return strcmp(a->name, b->name);
}

int main(){
    Person x[] = {
        {"김영준", 179, 79},
        {"박현규", 172, 63},
        {"이수진", 176, 52},
        {"최윤미", 165, 51},
        {"함진아", 181, 73},
        {"홍연의", 172, 84}
    };
    int nx = sizeof(x) / sizeof(x[0]);
    int retry;
    puts("이름으로 검색합니다.");
    do
    {
        Person temp, *p;
        printf("이름 : ");
        scanf("%s", temp.name);

        p = bsearch(&temp, 
                    x,
                    nx,
                    sizeof(Person),
                    (int(*)(const void *, const void *))npcmp
                    );
        if(p == NULL)
            puts("검색에 실패하였습니다.");
        else{
            puts("검색에 성공하였습니다. 세부 내용은 다음과 같습니다.");
            printf("x[%d] : %s %dcm %dkg \n ",
                    (int)(x-p), p->name, p->height, p->weight);
        }
        printf("다시 검색하시겠습니까? (1) 예 , (0) 아니오 : ");
        scanf("%d", &retry);
        
    } while (retry == 1);

    return 0;
    
}
