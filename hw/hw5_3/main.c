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
char a[200000];

//ex. this is 

void flip(char *b, int k, int l)
{
    //a, 0, 3
    //a, 0, 6
    int tmp;
  for ( ; k<l ; k++, l--) {
    tmp = b[k];
    b[k] = b[l];
    b[l] = tmp;
    // printf("b[%d]=%c, b[%d]=%c\n", k, b[k], l, b[l]);
  }
}

void sentence_reversal(char *a)
{
  //"this is a book \0"
  int i, j;
  j = 0;
  for (i=0; a[i]!='\0'; i++) {
    if (a[i] == ' ') {
      //a, 0, 3
      flip(a, j, i-1);
      //j=1
      j = i+1;
    }

  }
  // printf("enter\n");
  //a, 0, 8
  flip(a, 0, strlen(a)-2);
  // printf("%d\n", strlen(a));

  // printf("%s\n", a);
}

int main(){

  scanf("%s", &a);
  printf("%s\n", a);
}

