// You are given sets of N points in two-dimensional space. 
// It is guaranteed that no two points coincide in each set.

// For each set, please calculate the number of lines which pass through 
// at least three points in the set.
// 座標系統

// The first line contains an integer T, representing the number of testcases (sets).

// For each testcase (set) :
// The first line contains an integer N, representing the number of points in this set.

// The next N line contain two integer xi, yi, representing the coordinates of the i-th point. 
// All poin// For each set, please calculate the number of lines which pass through // For each set, please calculate the number of lines which pass through ts in the set are distinct.

// Output
// For each testcase (set), please output a line contains an integer representing your answer.

// (i.e. Please print '\n' after each answer.)



#include<stdio.h>

int T;
int N; 
int dots[101][3] = {0};
int count = 0;

int main()
{
  scanf("%d", &T);
  //scan T testcases (sets)
  for(int i=0;i<T;i++)
  {
    scanf("%d", &N);
    //scan N lines
    for(int j=0;j<N;j++)
    {
      //scan xi,yi
      scanf("%d %d", &dots[j][0], &dots[j][1]);
      //printf("%d %d", dots[j][0], dots[j][1]);
    }
  

    //please output a line contains an integer representing your answer.
    // For each set, please calculate the number of lines which pass through 
    // at least three points in the set.
    //y=ax+b
    //3 points
    //if a b is the same

    //3 finite loops to compare any 2 points with the rest points
    for(int i=0;i<N;i++)
    {
      for(int j=i+1;j<N;j++)
      {
        //find dots on the same vector between dots[i] and dots[j]
        for(int k=0;k<N;k++)
        {
          if(k == i || k == j) continue;
          // (a.x - b.x) * (a.y - b.y) == (c.x - b.x) * (c.y - b.y)
          else if((dots[i][0] - dots[j][0])*(dots[i][1]-dots[j][1]) == (dots[k][0]-dots[j][0]) * (dots[k][1]-dots[j][1]))
          {
            count += 1;
          }
        }
      }
    }
    printf("%d\n", count);
  }


  return 0;
}