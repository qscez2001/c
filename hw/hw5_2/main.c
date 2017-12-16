/*
Input
The first line contains an integer T, representing the number of inputs Niflheimr gives to you.

The next T line contains two strings si, ti, representing the correct string and the string 
Niflheimr types.

It is guaranteed that:

1 ≤ T ≤ 100
1 ≤ | si |, | ti | ≤ 2×105
Output
For each input, if t meets one of the four types of typo, please output "Yes", 
otherwise please output "No".

Sample Input

8
typo typo
potato potatoe
government goverment
separate seperate
society soceity
nthu nctu
ntu nthu
ntu nctu

Sample Output

No
Yes
Yes
Yes
Yes
No
Yes
Yes

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// char a[100];
// char b[100];
// char c[100];

void dump(char *arr) {
    printf("DEBUG start dumping\n");
    for (int i=0; i<strlen(arr); i++) printf("%d ", arr[i]);
    printf("\n");
}
// (1) Niflheimr accidentally types one more character.
// ex. abc abvc
int rule_one_more(char *b, char *c) {
  bool result = true;

  if (strlen(b) == strlen(c)-1) {
    // case 1: xyz xyza --> true
    // case 2: xyz axyz --> true
    // case 3: xyz xayz --> true
    // case 4: xyz abca --> false
    // case 5: xyz xyab --> false

    bool flag = true;
    for(int i=0; i<strlen(c); i++){
      if (flag) {
        if (c[i] == b[i]) continue;
        else flag = false;
      }
      else {
        if (c[i] == b[i-1]) continue;
        else {result = false; break;}
      }
    }

  }
  else result = false;

  return result;
}
// (2) Niflheimr accidentally forgets to type one character.
int rule_one_less(char *b, char *c) {
  bool result = true;

  if(strlen(b) == strlen(c)+1) {
    // case 1: xyz xy --> true
    // case 2: xyz yz --> true
    // case 3: xyz xz --> true
    // case 4: xyz xa --> false
    // case 5: xyz ab --> false

    bool flag = true;
    for(int i=0; i<strlen(b); i++){
      if(flag) {
        if (b[i] == c[i]) continue;
        else flag = false;
      }
      else {
        if(b[i] == c[i-1]) continue;
        else {result = false; break;}
      }
    }
  }
  else result = false;

  return result;
}
// (3) Niflheimr accidentally types one wrong character.
int rule_one_wrong(char *b, char *c) {
  int count = 0;
  if(strlen(b) == strlen(c)){
    for(int j=0; j<strlen(b); j++){
        if(b[j] != c[j]) count++;
    }
    if (count == 1) {
      return 1;
    }
    else return 0; 
  }
  else return 0;
}
// (4) Niflheimr accidentally switches two different adjacent characters.
int rule_switch_two(char *b, char *c) {
  // (4) Niflheimr accidentally switches two different adjacent characters.
  for(int j=0; j<strlen(b); j++){
    if(b[j] == c[j+1] && b[j+1] == c[j]) {
      return 1;
    }
  }

  for(int j=0; j<strlen(c); j++){
    if(b[j] == c[j+1] && b[j+1] == c[j]) {
      return 1;
    }
  }
  return 0;
}

void compare(char *b, char *c) {
    // one_more + 
    int rule_one = rule_one_more(b, c);
    int rule_two = rule_one_less(b, c);
    int rule_three = rule_one_wrong(b, c);
    int rule_four = rule_switch_two(b, c);
    // printf("%d\n", rule_one);
    // printf("%d\n", rule_two);
    // printf("%d\n", rule_three);
    // printf("%d\n", rule_four);
    if ( rule_one + rule_two + rule_three + rule_four == 1) printf("Yes\n");    
    else printf("No\n");
  
    /*
    int same_lenth = 0;
    // (1) Niflheimr accidentally types one more character.
    // (2) Niflheimr accidentally forgets to type one character.
    if(strlen(b) != strlen(c)) {
      printf("Yes\n");
      same_lenth = 1;
    }
    // if lenth is the same
    // (3) Niflheimr accidentally types one wrong character.
    if(same_lenth == 0) {
      int count = 0;
      
      for(int j=0; j<strlen(b); j++){
        if(b[j] != c[j]) count++;
      }

      // printf("%d\n", count);
      if (count == 1) {
        printf("Yes\n");
      } else if(count == 2){
        int flag = 0;
        // (4) Niflheimr accidentally switches two different adjacent characters.
        for(int j=0; j<strlen(b); j++){
          if(b[j] == c[j+1] && b[j+1] == c[j]) {
            // printf("Yes\n");
            flag = 1;
          }
        }

        if(flag == 1 ) {
          printf("Yes\n");
        } else {
          printf("No\n");
        }

      } else if (count == 0){
        printf("No\n");
      } else printf("No\n");
    }*/
}

void analysis(char *a) {
    //dump(a);

    char b[200001];
    int index_a = 0;
    for(int j=0; a[j] != 32; j++){
        b[j] = a[j];
        index_a = j;
    }
    b[index_a+1] = 0;
    //dump(b);
    
    char c[200001];
    index_a +=2;
    int k = 0;
    for(int j=index_a; j<strlen(a)-1; j++){
        c[k++] = a[j];
    }
    c[k] = 0;
    //dump(c);

    compare(b, c);   
}

int main(){
// case: nthu nhtuu 
  int tcnum;
  scanf("%d\n", &tcnum);
  for(int i=0; i<tcnum; i++) {
    char a[400002];
    if(fgets(a, 99, stdin) != NULL){
      analysis(a);
    }
  }
  return 0;
}
