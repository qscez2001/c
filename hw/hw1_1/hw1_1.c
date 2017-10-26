#include<stdio.h>

int main(void)
{
    int a;
    int n;
    int d;

    scanf("%d %d %d", &a, &n, &d);
    int nth = a+(n-1)*d;

    int sum;
    if(n>0 && n<1000 && -1000<a<1000 && -1000<d<1000)
    {
      if(n%2!=0)
      {
        sum=a*n + d*n*(n-1)/2;
      }
      else
      {
        sum=a*n + d*n*(n-2)/2 + n/2*d;
      }
      printf("%d %d", nth, sum);
    }
    else return 0;
}
