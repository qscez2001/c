//11680 - Big Mod   
/*
Given integers a, n, p, please calculate the value of a^n mod p.

The first line contains an integer T, representing the number of testcases.
Each testcase contains a line with three integer a, n, p.

1 ≤ T ≤ 1000
1 ≤ a, n, p ≤ 109

Sample Input
3
2 10 20000
2 10 200
2 10 2
Sample Output  
1024
24
0
*/
/*
#include <stdio.h>
int T;
int a, n, p;
unsigned long int result;

unsigned long int multiply(unsigned long int result, int n)
{
  if(n>1)
  {
    result = result * multiply(result, n-1);
  }
  return result;
}

int main()
{
  scanf("%d", &T);
  for(int i=0; i<T; i++)
  {
    scanf("%d %d %d", &a, &n, &p);
    //result = a*a*a*a*a*a*a*a*a*a = a^n
    result = a;
    result = multiply(result, n);
    //printf("%d\n", result);
    result = result % p;
    printf("%lu\n", result);
  }
  return 0;
}
*/

//http://maplewing.blogspot.tw/2011/03/uva374big-mod.html
#include<stdio.h>

unsigned long long modpow( unsigned long long B, unsigned long long P, unsigned long long M )
{
    if( M == 1 )
        return 0; 
    if( P == 0 )
        return 1;
    else if( P == 1 ) 
        return B%M;
    else
    {
        unsigned long long result = modpow( B, P/2, M );
        if( P % 2 )
            return result * result * B % M; 
        else
            return result * result % M;
        
    }
}

// return ( power_mod(a, n/2, p) * power_mod(a, (n/2) +1 , p) ) % p

int main()
{

  int T;
  scanf("%d", &T);
  for(int i=0; i<T; i++)
  {
    unsigned long long B, P, M;
    scanf( "%llu%llu%llu", &B, &P, &M );

    unsigned long long R = modpow( B, P, M );
    printf( "%llu\n", R );
  }
  return 0;
}