//Given some integers, please list them in increasing order.

// Input
// First line is an integer T (T <= 20) followed by T test cases.

// Each test case consists of two lines. 
// First line is an integer n (n <= 104), 
// and second line contains n integers V1, V2, ..., Vn. 
// (-231< Vi < 231-1 for 1 <= i <= n )

// Output
// For each test case, list a line of numbers from the smallest one 
// to the largest one ending with '\n'. 
// Two adjacent numbers in one line should be separated by a whitespace.

#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
  //scan T test cases
  int T;
  scanf("%d", &T);
  int n;
  int a[105] = {0};
  for(int i=0;i<T;i++)
  {
    //scan two lines
    // First line is an integer n (n <= 104), 
    // and second line contains n integers V1, V2, ..., Vn. 
    scanf("%d", &n);
    for(int j=0;j<n;j++)
    {
      //printf("j=%d\n", j);
      scanf("%d", &a[j]);
    }

    //sort the array from the smallest one to the largest one ending with '\n'. 
    //use bubble sort..
    int flag = 0;
    for(int k=0;k<(n-1);k++)
    {
      for(int l=0;l<n-k-1;l++)
        {
        if(a[l]>a[l+1])
        {
          swap(&a[l], &a[l+1]);
        }
        else
        {
          flag = 1;
        }
      }
    }

    for(int p=0;p<n;p++)
    {
      printf("%d ", a[p]);
    }
    printf("\n");
  }

  return 0;
}