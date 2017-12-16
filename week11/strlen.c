// 等價的寫法
// a[i]  <--->  *(a+i)
// &a[i] <--->  (a+i)

#include <stdio.h>
unsigned int mylen(char* s);
int main(void)
{
    char str[] = "Hello, world!";


    printf("%u, %s\n", mylen(str), str);

    return 0;
}

unsigned int mylen(char* s)
{
    unsigned int len = 0;

    while (*s!='\0') {
        len++;
        s++;
    }

    return len;
}