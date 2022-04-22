#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define CASE 2          /* 1: not use mutex, 2: use mutex */
#define TEST_COUNT 10

#if CASE == 1
#define VERSION "MUTEX-NOT-USING"
#elif CASE == 2
pthread_mutex_t mutex_lock;
#define VERSION "MUTEX-USING"
#endif

int yyj_count = 0;      /* 공유 자원 */

void *yyj_function(void *data){
    int i;
    char *thread_name = (char*)data;
#if CASE == 2
    pthread_mutex_lock(&mutex_lock);
#endif
    yyj_count = 0;
    for(i=1; i<=TEST_COUNT; i++){
        printf("[%s][YYJ-%s] i = %d\n",VERSION ,thread_name, yyj_count);
        sleep(1);
        yyj_count++;
    }
#if CASE == 2
    pthread_mutex_unlock(&mutex_lock);
#endif
}

int main() {
    pthread_t pthread_1, pthread_2;
    int status;

#if CASE == 2
    pthread_mutex_init(&mutex_lock, NULL);
#endif
    pthread_create(&pthread_1, NULL, yyj_function, (void *)"Thread 1");
    pthread_create(&pthread_2, NULL, yyj_function, (void *)"Thread 2");

    pthread_join(pthread_1, (void *)&status);
    pthread_join(pthread_2, (void *)&status);

    return 0;
}
