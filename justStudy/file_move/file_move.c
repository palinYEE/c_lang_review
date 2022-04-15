/*
 * move_file.c
 * 해당 예시 소스코드는 open, read, write 함수를 사용하여 파일을 옮기는 예제이다. 
*/
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

#define TEST_PATH "/home/osboxes/YJYOON/c_lang_review/justStudy/fileMove/test.txt"
#define TEST2_PATH "/home/osboxes/YJYOON/c_lang_review/justStudy/fileMove/test2.txt"

int main(){
    int test_fd;
    int test2_fd;
    ssize_t fd_size;
    char temp_buf[4] = {0,};

    test_fd = open(TEST_PATH,  O_RDONLY );
    if(test_fd == -1) {
        printf("%d\n", errno);
        return 0;
    }
    test2_fd = open(TEST2_PATH,  O_CREAT | O_WRONLY , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH /* 0644 */);
    if(test2_fd == -1){
        close(test_fd);
        return 0;
    }

    while((fd_size = read(test_fd, (void *)temp_buf, sizeof(temp_buf))) > 0){
        printf("%s\n", temp_buf);
        write(test2_fd, temp_buf, sizeof(temp_buf) );
    }
	
	close(test2_fd);
    close(test_fd);
    return 0;

}

