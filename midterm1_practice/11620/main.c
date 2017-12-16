

#include<stdio.h>

int T, N;
int board[5][5];
int sel[25];

int main()
{
  //init
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      scanf("%d", &board[i][j]);
    }
  }

  //draw
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  scanf("%d", &T);
  //T test cases
  for(int i=0;i<T;i++)
  {
    scanf("%d", &N);
    //each contains N distinct selected numbers
    for(int j=0;j<N;j++)
    {
      scanf("%d", &sel[j]);
      //printf("%d", sel[j]);
    }
  }

  //check if won or is goint to win
  

  return 0;
}