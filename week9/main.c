#include <stdio.h>

void hanoi(int N, char start, char end, char buf)
{
  if(N>0)
  {
    //搬上面2個盤子 放到buf(暫存)
    hanoi(N-1, start, buf, end);
    //把底盤從A放到到C
    printf("%c -> %c\n", start, end);
    //把上面2個盤子 放到C
    hanoi(N-1, buf, end, start);
  }
}

int main()
{
  hanoi(3, 'L', 'R', 'M');
}