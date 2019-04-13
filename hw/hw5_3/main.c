/*

Given a string S consisting of lowercase English letters, 
you can choose any two indices i and j such that 1 ≤ i ≤ j ≤ | S | and reverse substring S[i..j].

If you can perform this operation at most once, how many different strings can you obtain?

For example, if S = 'aatt':

You can obtain 'aatt' (don't do anything), 'atat' (reverse S[2..3]), 'atta' (reverse S[2..4]), 
'ttaa' (reverse S[1..4]) and 'taat' (reverse S[1..3]).

Input
The input contains only one string S.

It is guaranteed that :

1 ≤ | S | ≤ 2×10^5
S consists of lowercase letters.
Output
Please output the number of different strings you can obtain by reversing any substring
 in S at most once.

*/
#include <stdio.h>
#include <string.h>
char a[200000];
char b[200000];
/*
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
*/

int main(){

  scanf("%s", &a);
  
  // case: aatt

  int count = 1;
  
  int len = strlen(a);
  for(int i=0; i<len; i++){
    for(int j=i+1; j<len; j++){
      if (a[i] == a[j]) {
        // printf("a[%d]=%c, a[%d]=%c", i,a[i], j, a[j]); 
        continue;
      }
      else count++;
    }
  }
  
  
  printf("%d\n", count);
  
  return 0;
}

