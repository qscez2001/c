
// You are given an ordered sequence of integers, (1,2,3,...,n). 
// Then, a number of requests will be given. 
// Each request specifes an integer in the sequence. 
// You need to move the specied integer to the head of the sequence, 
// leaving the order of the rest untouched. 
// Your task is to find the order of the elements in the sequence 
// after following all the requests successively.

// Sample Output Explanation : In Sample Input 1, the initial sequence is (1; 2; 3; 4; 5).
// The first request is to move the integer 4 to the head, that is, 
// to change the sequence to (4; 1; 2; 3; 5). 
// The next request to move the integer 2 to the head makes the sequence (2; 4; 1; 3; 5). 
// Finally, 5 is moved to the head, resulting in (5; 2; 4; 1; 3).

// The integer n is the length of the sequence ( 1 <= n <= 200000 ). 
// The integer m is the number of requests ( 1 <= m <= 100000 ).


#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
  int n;
  int m;
  int a[200000];
  scanf("%d %d", &n, &m);
  //store the sequence
  for(int i=1;i<=n;i++)
  {
    a[i] = i;
    printf("%d", a[i]);
  }
  int r;
  //scan the requests m-times
  //swap the content
  for(int i=0;i<n;i++)
  {
    //scan for the array , fine the r position
    scan("%d", &r);
    if(r == a[j])
    {

    }
    swap()
  }
  return 0;
}