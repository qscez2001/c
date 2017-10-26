#include<stdio.h>

int main(void)
{
    int n, x, y, z, b, x_butnot_y;
    scanf("%d %d %d %d", &n, &x, &y, &z);
    if(0<n<1000 && 0<x<1000&& 0<y<1000 && 0<z<1000)
    {
      b = z+x+y-n;
      x_butnot_y = x-b;
      printf("%d %d", b, x_butnot_y);
    }
}
