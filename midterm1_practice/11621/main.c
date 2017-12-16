
// Input
// There are multiple lines in each testcase. Each line contains a string si 
//that HT wrote on the paper.

// The input file is ended by 'EOF'.

// It is guaranteed that :

// At most 10 lines in each testcase.
// testcase #1 ~ #4 : 1 ≤ | s | ≤ 200
// testcase #5 Bonus: 1 ≤ | s | ≤ 2000

// For each string si, please output a line contains one integer representing 
//the number of "exquisite substrings" in si.

// (i.e. Please print '\n' after each answer.)

// abcd
// abab
// aaaaa

// 0
// 2
// 10

#include<stdio.h>
#include<stdlib.h>

char s[500];

int isPalindrome(int l, int r)
{
  Decide whether s[l,r] is palindrome
}

int main()
{
  int i=0;
  scanf("%c", &s[i]);

  for(int i=0;i<strlen(s[i]);i++)
  {
    for(int j=i+1;j<strlen{s[i];j++})
    {
      if (String(i, j) is Palindrome)
      {
        number of exquisite substrings ++;
      }
    }
  }
  return 0;
}