#include <stdio.h>
#include "function.h"

void hanoi(int N, char start, char end, char buf)
{
  if(N>0)
  {
    // 搬上面2個盤子 放到buf(暫存)
    // move the top n-1 disks from start to buf
    hanoi(N-1, start, buf, end);
    // 把底盤從A放到到C
    //printf("%c -> %c\n", start, end);
    //printf("Move the #%d disk from Tower %c to Tower %c\n", N, start, buf);
    printf("%d\n", N);
    // 把上面2個盤子 放到C
    // move the top n-1 disks from buf to end
    hanoi(N-1, buf, end, start);
  }
}