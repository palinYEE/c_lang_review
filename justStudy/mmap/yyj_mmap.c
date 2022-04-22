#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<fcntl.h>

int main(int argc, char **argv){
    int fd;
    char *file = NULL;
    
    if(argc < 2){
        fprintf(stderr, "Usage: input\n");
        return 0;
    }

    if((fd = open(argv[1], O_RDWR|O_CREAT)) < 0){
        perror("File Open Error");
        return 0;
    }

    file = (char *)malloc(40);

    if((file = (char *)mmap(0, 40, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0)) == -1){
        perror("mmap error");
        return 0;
    }

    printf("%s\n", file);
    memset(file, 0, 40);
    munmap(file, 40);
    close(fd);
    return 1;


}