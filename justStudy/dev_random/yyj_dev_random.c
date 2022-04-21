#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

#define DEV_RANDOM_PATH "/dev/random" 
#define KEY_SIZE 16


int main()
{
    int i;
    int fd;

    char key[KEY_SIZE];

    if((fd = open(DEV_RANDOM_PATH, O_RDONLY)) == -1 ){
        perror("open error");
        return 0;
    }

    if((read(fd, key, KEY_SIZE)) == -1){
        perror("read error");
        return 0;
    }
    
    for ( i = 0; i < KEY_SIZE; i++)
    {
        printf("%c", key[i]);
    }
    
}