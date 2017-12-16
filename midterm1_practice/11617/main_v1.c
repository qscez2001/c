

//When taking the assigned number to the first place, others
// after it will forward one place.
// – The last input will be the first output number

#include<stdio.h>
int n;
int m;
int a[200000];
int r[100000];
int A[200000];


int main()
{
  scanf("%d %d", &n, &m);
  
  for(int i=0;i<=n-1;i++)
  {
    a[i] = i+1;
    //printf("%d", A[i]);
  }
  //scan the requests m-times
  //if m=3 the first number r[0] will be a[2]
  //the second num r[1] will be a[1]
  //the last num r[2] will be a[0]
  for(int i=0;i<=m-1;i++)
  {
    scanf("%d", &r[i]);
    //printf("%d", r[i]);
    //others after it will forward one place.
  }

  // – The last input will be the first output number
  int s = m-1;
  for(int j=0;j<=m-1;j++)
  {
    //A[j+1] = a[j];
    a[j] = r[s];
    s--;
  }

  //print to check the result
  for(int k=0;k<=n-1;k++)
  {
    printf("%d\n", a[k]);
  }

  return 0;
}