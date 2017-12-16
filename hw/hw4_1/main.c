//11678 - Firework Show  
// 3
// 3 5
// 1 2 3
// 6 3
// 1 1 1 1 1 1
// 6 6
// 1 2 3 1 2 3

// 1
// 1
// 3

#include <stdio.h>

int tc, fireworks, totalgrade;
int f[2500];

void read()
{
  scanf("%d %d", &fireworks, &totalgrade);
  for(int i=0 ; i<fireworks; i++)
  {
    scanf("%d", &f[i]);
  }
}

int factorial(int n)
{
  int factorial_result;
  //n! = n * n-1 * n-2 * ... * 2 * 1
  
  //n! / (n-1)! = n
  //n! = n * (n-1)!
  if(n > 0){
    factorial_result = n * factorial(n-1);
  }
  else {
    factorial_result = 1;
  }

  return factorial_result;
}

int cnr(int n, int r)
{
  int cnr_result;
  //C(n, r) = n! / ((n − r)! * r!)
  cnr_result = factorial(n) / (factorial(n-r) * factorial(r));
  return cnr_result;
}

int calculate()
{
  int num;
  for(int i=0; i<fireworks; i++)
  {
    //if the sum of any n numbers = totalgrade
    if (cnr_result)
    //try all cobinations of Cn 取 r, r = 1,2,3,4...n
    //if sum of them == totalgrade
    //count++ 
    //n=arraylen = fireworks

  }
  return num;
}

int main()
{
  scanf("%d", &tc);

  //read 3 times
  for(int i=0 ; i<tc ; i++)
  {
    read();
    //calculate the number of different kinds of shows
    int result = calculate();
  }
  
  // int cnr_result = cnr(5,2);
  // printf("%d\n", cnr_result);// output = 10
  // int factorial_result = factorial(0);
  // printf("%d\n", factorial_result);// output = 1
  // int factorial_result = factorial(1);
  // printf("%d\n", factorial_result);// output = 1
  // int factorial_result = factorial(2);
  // printf("%d\n", factorial_result);// output = 2
  // int factorial_result = factorial(5);
  //printf("%d\n", factorial_result);// output = 120
}