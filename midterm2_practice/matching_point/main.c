/*

https://acm.cs.nthu.edu.tw/contest/1342/
Input
There are multiple lines in each testcase.

Each line contains two strings si, ti, representing the string HT wrote and the string YJC wrote.

At most 10 lines in each testcase.
1 ≤ | si |, | ti | ≤ 20
The input will end with EOF

Output
For each si and ti, please output a line contains one integer representing the matching point 
of si and ti (HT and YJ). 

Sample Input
htisanaughtyboy ht
abcabc abc

Sample Output
3
4

*/
#include <stdio.h>
#include <string.h>

char string[30];
char sub[30];
int count;

void match(int now, int pos){
  //once the 'pos' count to Len_sub
  if (pos == strlen(sub)) {
    //printf("%d\n", pos);
    //a substring is found
    count++;
  }
  else {
    for (int i=now; i<strlen(string); i++) {
      //for the whole string
      //if find element of 'sub' in 'string'
      if (string[i] == sub[pos]) {
        // printf("i=%d, pos=%d\n", i, pos);
        // printf("string[i]=%c, sub[pos]=%c\n", string[i], sub[pos]);
        //keep matching
        match(i+1, pos+1);
      } //skip if not matching, iteration next.
    }
  }
}
int len_sub, len_string;

int main(){

  while(scanf("%s", &string) != EOF) {
    scanf("%s", &sub);
    count = 0;
    // len_string = strlen(string);
    // len_sub = strlen(sub);
    // printf("%d %d\n", len_string, len_sub);

    // if the length of t is N, then we may need N times for-loop instinctively
    // the length of t isn't fixed! => use recursion to solve
    // in main function, we call match(0, 0)
    match(0, 0);
    printf("%d\n", count);
  }
  
  return 0;
}