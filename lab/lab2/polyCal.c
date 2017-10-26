#include<stdio.h>

int main()
{
  int n, m;
  int a[2000];
  int mul[2000];
  scanf("%d %d", &n, &m);

  int answer = 0;

  //存下a的值
  for(int i=0;i<n+1;i++)
  {
    scanf("%d", &a[i]);
    //printf("%d ", a[i]);
  }
  //printf("\n");


  //存下x次方*m的值
  int i = 0;
  for(int j = n; j >=0 ; j--)
    {
      //printf("%d ", power(m,j));
      mul[i] = power(m,j);
      i++;
    }

  //印出x次方*m的值
  for(int i = 0; i<n+1; i++)
    {
      //printf("%d ", mul[i]);
    }
  //x*m*a
  int xma[2000];
  for(int i = 0; i<n+1; i++)
    {
      xma[i] = a[i]*mul[i];
      // printf("%d ", xma[i]);
      // printf("\n");
    }
  //sum
  int sum = 0;
  for(int i = 0; i<n+1; i++)
    {
      sum = sum + xma[i];
      //printf("%d\n", sum);
    }
  printf("%d\n", sum);
}


int power(int x, int n) {
  if (n == 0) {
    return 1;
  }
  else if (n == 1) {
    return x;
  }
  else {
    return x * power(x, n-1);
    //n=3
    //return x*power
    //n=2
    //return x*x*power
    //n=1
    //return x*x*x
  }
}