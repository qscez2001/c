#include<stdio.h>
#include "function.h"

void print(int level, int n)
{
    if (n == 1) {
        printf("%d\n", level);
    }
    else {
        printf("%d ", level);
    }

    if(level<n)
    {
        print(level+1, n);

        if(level==1) {
            printf("%d\n", level);
        }
        else {
            printf("%d ", level);
        }
    }
}