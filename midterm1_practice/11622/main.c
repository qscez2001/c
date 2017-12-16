// The first line contains an integer T, 
//representing the number of sets Lightyear gives to you.

// The next T lines contain 5 cards in each given set, separated by whitespaces.

// The cards would range from : {A, 2, 3, 4, 5, 6, 7, 8 ,9 ,10, J, Q, K}.

// (In this problem, you don't need to consider the suit of each card.)

// 1 ≤ | T | ≤ 10000



#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int T;
char a[101][6];
int s[6];



int main()
{

  scanf("%d", &T);
  //read T lines
  int i,j;
  for(i=0;i<T;i++)
  {
    //read five numbers
    for(j=0;j<5;j++)
    {
      scanf("%s", &a[j]);
      //printf("a[j]=%s\n", a[j]);
    }

    //check if full house

    //scan the number of cards into array S;
    // for(j=0;j<5;j++)
    // {
    //   s[j] = atoi(a[j]);
    // }

    //convert alphabet into integer if needed
    for(j=0;j<5;j++)
    {
      char con = a[j][0];
      //printf("a[j]=%c\n", a[j][0]);
      switch(con)
      {
        case('A'):
          s[j] = 1;
          break;
        case('J'):
          s[j] = 11;
          break;
        case('Q'):
          s[j] = 12;
          break;
        case('K'):
          s[j] = 13;
          break;
        default:
          s[j] = atoi(a[j]);
          break;
      }
      //printf("s[j]=%d\n", s[j]);
    }
    //sort the array;
    int tmp;
    for(int k=0;k<4;k++)
    {
      for(int l=0;l<4-k;l++)
      {
        if(s[l] > s[l+1])
        {
          /* Swapping */ 
          tmp = s[l];
          s[l] = s[l+1];
          s[l+1] = tmp;
        }
      }
    }

    // for(j=0;j<5;j++)
    // {
    //   printf("s[j]=%d\n", s[j]);
    // }

    if (s[0] == s[1] && s[1] == s[2] && s[3] == s[4])
    {
      printf("YES\n");
    }
    else if (s[0] == s[1] && s[2] == s[3] && s[3] == s[4])
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }

  }


  return 0;
}