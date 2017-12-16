

//When taking the assigned number to the first place, others
// after it will forward one place.
// – The last input will be the first output number

#include<stdio.h>
int n;
int m;
int a[200000];
int b[200000];
int r;


int main()
{
  scanf("%d %d", &n, &m);
  //store the sequence
  for(int i=0;i<=n-1;i++)
  {
    a[i] = i+1;
    b[i] = -1;
    //printf("%d", a[i]);
  }
  
  //scan the requests m-times
  for(int i=0;i<=m-1;i++)
  {
    // – The last input will be the first output number
    scanf("%d", &r);

    b[i] = r; //save r in the 2nd array
    a[r-1] = -1; //make a mark for the 1st array

  }

  //check
  for(int i=0;i<=n-1;i++)
  {
    printf("%d ", a[i]);
  }

  //print to check the result
    for(int j=m-1;j>-1;j--)
    {
      if (a[b[j] - 1] == -1) {
        printf("%d\n", b[j]);
        a[b[j] - 1] = 0; // make a mark for the 1st array
      }
    }
    for(int j=0;j<=n-1;j++)
    {
      if (a[j] >0 ) {
        printf("%d\n", a[j]);
      }
    }

  return 0;
}