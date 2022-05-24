#include<sys/time.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

// https://www.joinc.co.kr/w/man/2/gettimeofday

int main()
{
    struct timeval tmpTime;

    gettimeofday(&tmpTime, NULL);
    printf("%ld:%ld\n", tmpTime, tmpTime.tv_usec);

    tmpTime.tv_sec -= 3600;
    settimeofday(&tmpTime, NULL);
    return 0;
}
