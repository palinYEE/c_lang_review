#include<stdio.h>
#include<stdlib.h>
#include"int_set.h"

int Initialize(SET_CONT *s, int max){
    s->num = 0;
    /* MALLOC FAIL */
    if((s->set = malloc(sizeof(int)*max)) == NULL){
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int IsMember(const SET_CONT *s , int n){
    int i;
    for(i = 0; i < s->max; i++){
        if(n == s->set[i]){
            return OK;
        }
    }
    return NO;
}

void Add(SET_CONT *s, int n){
    /* set의 길이가 최대치가 넘지 않고 n 값이 집합에 없어야 한다. */
    if( (s->num < s->max) && (IsMember(s, n) == NO)){
        s->set[s->num++] = n;
    }
}

void Remove(SET_CONT *s, int n){
    int idx;
    if((idx = IsMember(s, n)) != NO){
        s->set[idx] = s->set[--s->num];
    }
}

int Capacity(const SET_CONT *s){
    return s->max;
}

int Size(const SET_CONT *s){
    return s->num;
}

void Assign(SET_CONT *s1, const SET_CONT *s2){
    int i;
    int n = (s1->max < s2->num) ? s1->max : s2->num;
    for(i = 0; i < n; i++){
        s1->set[i] = s2->set[i];
    }
    s1->num = n;
}

int Equal(const SET_CONT *s1, const SET_CONT *s2){
    int i, j;
    if(Size(s1) != Size(s2)){
        return NO;
    }
    for(i=0; i<s1->num; i++){
        for(j=0; j < s2->num; j++){
            if(s1->set[i] == s2->set[j]){
                break;
            }
        }
        if(j == s2->num){
            return NO;
        }
    }
    return OK;
}

SET_CONT *Union(SET_CONT *s1, const SET_CONT *s2, const SET_CONT *s3){
    int i;
    Assign(s1, s2);     /* s1 <-- s2 */
    for(i=0; i<s3->num; i++){
        Add(s1, s3->set[i]);
    }
    return s1;
}

SET_CONT *Intersection(SET_CONT *s1, const SET_CONT *s2, const SET_CONT *s3){
    int i, j;
    s1->num = 0;
    for(i=0; i< s2->num; i++){
        for(j=0; j<s3->num; j++){
            if(s2->set[i] == s3->set[j]){
                Add(s1, s2->set[i]);
            }
        }
    }
    return s1;
}

SET_CONT *Difference(SET_CONT *s1, const SET_CONT *s2, const SET_CONT *s3){
    int i, j;
    s1->num = 0;
    for(i=0; i< s2->num; i++){
        for(j = 0; j<s3->num; j++){
            if(s2->set[i] == s3->set[j]){
                break;
            }
        }
        if(j == s3->num){
            Add(s1, s2->set[i]);
        }
    }
    return s1;
}

void Print(const SET_CONT *s){
    int i; 

    printf("{ ");
    for(i=0; i<s->num; i++){
        printf("%d ", s->set[i]);
    }
    printf("}");
}

void PrintLn(const SET_CONT *s){
    Print(s);
    printf("\n");
}

void Terminate(SET_CONT *s){
    if(s->set != NULL){
        free(s->set);
        s->max = s->num = 0;
    }
}
