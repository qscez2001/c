//Compute C = A × B, 
//where A, B and C are matrices of size n × m, m × p, and n × p, respectivily.

// There are multiple (≤50) test cases in each data set.

// Each case begins with a line of three integers n, m and p, 
//which denote the dimensions of the matrices defined in the problem description. 
//Each of the following n lines contains m integers aij, 
//representing the elements in matrix A, and then m lines of p integers bij, 
//representing the elements in matrix B.

// There is a blank line between two successive test cases, 
//and the input is terminated by end-of-file.


// Output
// For each test case, output n lines of p integers representing the elements of matrix C.

// Please use single space to seperate two successive elements in the same line, 
//and do not output any leading or trailing space characters.

// Also, please output a blank line after each matrix.



#include <stdio.h>

long int first[10000][10000], second[10000][10000], multiply[10000][10000];

int main()
{
  int m, p, q, c, d, k, sum = 0;
  //n=p
  //printf("Enter the number of rows and columns of first matrix\n");
while(scanf("%d%d%d", &m, &p, &q)!=EOF)
{
  //scanf("%d%d%d", &m, &p, &q);
   
  //printf("Enter the number of columns of second matrix\n");
  //printf("Enter the elements of first matrix\n");
 
  for (c = 0; c < m; c++)
    for (d = 0; d < p; d++)
      scanf("%ld", &first[c][d]);


  //printf("Enter the elements of second matrix\n");

  for (c = 0; c < p; c++)
    for (d = 0; d < q; d++)
      scanf("%ld", &second[c][d]);

  //multiple
  for (c = 0; c < m; c++) 
  {
    for (d = 0; d < q; d++) 
    {
      for (k = 0; k < p; k++) 
      {
        sum = sum + first[c][k]*second[k][d];
      }

      multiply[c][d] = sum;
      //歸零
      sum = 0;
    }
  }

  //printf("Product of entered matrices:-\n");

  for (c = 0; c < m; c++) 
  {
    for (d = 0; d < q-1; d++)
    {
      //printf("c=%d d=%d\n", c, d);
      printf("%ld ", multiply[c][d]);
    }
    printf("%ld\n", multiply[c][d]);
  }
  //printf("%d\n", multiply[m-1][q-2]);
  printf("\n");
}
 
  return 0;
}