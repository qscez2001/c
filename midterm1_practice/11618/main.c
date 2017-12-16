// Input
// First line contains one integer ​T, representing the number of testcases 
// (or the parties Pinkie will throw, who doesn't like parties?)

// The next T lines contains four integers n, x1, x2, x3, 
// representing the number of ponies who are invited to the party, 
// and the three random number Pinkie chooses in the party.

// ​1 ≤ T ≤ 10

// Testcase #1 ~ #4 : 1 ≤ x1, x2, x3 ≤ n ≤ 105

// Testcase #5 Bonus : 1 ≤ x1, x2, x3 ≤ n ≤ 1018


// Output
// For each testcase (party), please output a line contains one integer 
// representing the number of ponies who get three balloons.

// (i.e. Please print '\n' after each answer.)

// Sample Input 
// 2
// 6 2 3 5
// 10 2 3 7

// Sample Output 
// 1
// 5

//https://docs.google.com/spreadsheets/d/1p7BzSBvMB9P-zNPSm6MVq010_aCCM08vooKYhiW1W3Y/edit#gid=0



#include<stdio.h>

int T;
long long int num, red, blue, yellow;

long long int GCD(long long int n1, long long int n2)
{
  long long int gcd;
  for(int i=1; i <= n1 && i <= n2; ++i)
  {
      // Checks if i is factor of both integers
      if(n1%i==0 && n2%i==0)
          gcd = i;
  }

  //printf("G.C.D of %d and %d is %d", n1, n2, gcd);

  return gcd;
}

long long int LCM(long long int a, long long int b)
{
  //printf("DEBUG: LCM of %lld, %lld = %lld\n", a, b, a / GCD(a, b) * b);
  return a / GCD(a, b) * b;
}

long long int LCM_4_3(long long int a, long long int b, long long int c)
{
  return LCM(LCM(a, b), c);
}


int main()
{
  scanf("%d", &T);
  //scan T lines
  for(int i=0;i<T;i++)
  {
    scanf("%lld%lld%lld%lld", &num, &red, &blue, &yellow);

    
    //printf("DEBUG: GCD of %lld, %lld = %lld\n", red, num, GCD(red, num));
    //printf("DEBUG: GCD of %lld, %lld = %lld\n", blue, num, GCD(blue, num));
    //printf("DEBUG: GCD of %lld, %lld = %lld\n", yellow, num, GCD(yellow, num));


    //printf("DEBUG: LCM_4_3 %lld\n", LCM_4_3(GCD(red, num), GCD(blue, num), GCD(yellow, num)));
    printf("%lld\n", num / LCM_4_3(GCD(red, num), GCD(blue, num), GCD(yellow, num)));
  }

  return 0;
}