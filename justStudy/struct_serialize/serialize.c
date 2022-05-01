#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * output
   original values: 123 Hello, world!
   new values: 123 Hello, world!
*/

/* TEST Structure */
typedef struct A {
    int a;
    char *str;
} test_struct_t; 

/* |- A.str -|- sizeof(A.str) -|- A.a -| */
char *serialize(test_struct_t t) {
    int str_len = strlen(t.str);

    int size = 2 * sizeof(int) + str_len;
    char *buf = malloc(sizeof(char) * (size+1)); /*  Q. 여기서 malloc을 해줬는데 그럼 free는 언제 해주는건가. */

    memcpy(buf, &t.a, sizeof(int));
    memcpy(buf + sizeof(int), &str_len, sizeof(int));
    memcpy(buf + sizeof(int) * 2, t.str, str_len);
    buf[size] = '\0';

    return buf;
}

test_struct_t deserialize(char *buf) {
    test_struct_t t;

    memcpy(&t.a, buf, sizeof(int));

    int str_len;
    memcpy(&str_len, buf+sizeof(int), sizeof(int));

    t.str = malloc(sizeof(char) * (str_len+1));
    memcpy(t.str, buf+2*sizeof(int), str_len);
    t.str[str_len] = '\0';

    return t;
}

int main() {
    char str[15] = "Hello, world!";

    test_struct_t t;
    t.a = 123;
    t.str = malloc(strlen(str) + 1); /* 해당 메모리도 free 해주는 부분이 없음. */
    strcpy(t.str, str);
    printf("original values: %d %s\n", t.a, t.str);

    char *buf = serialize(t);
    test_struct_t new_t = deserialize(buf);
    printf("new values: %d %s\n", new_t.a, new_t.str);

    return 0;
}
