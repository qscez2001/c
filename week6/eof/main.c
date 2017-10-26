#include <stdio.h>

int main(void)
{
    freopen("testcase.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int x;

    while (scanf("%d", &x) != EOF) 
    { 
      /*Ctrl Z + Enter */
      printf("x=%d\n", x);
    }
    return 0;
}