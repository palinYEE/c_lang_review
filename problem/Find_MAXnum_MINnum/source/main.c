#include "problem.h"

int main()
{
    int result[2] = {0, 0};
    int *in_arr;
    int in_arr_size;
    int i;

    print_prob_info();
    printf("\n===================\n");
    printf("[*] ARRAY SIZE : ");
    scanf("%d", &in_arr_size);
    in_arr = malloc(sizeof(int) * in_arr_size);
    printf("[*] TEST ARRAY INPUT : ");
    for(i = 0; i<in_arr_size; i++){
        scanf("%d", in_arr + i);
    }
    sol(in_arr, in_arr_size, result);
    printf("MAX : %d, MIN : %d\n", result[0], result[1]);
    

    return 0;
}