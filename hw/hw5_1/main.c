// https://acm.cs.nthu.edu.tw/problem/11729/

/*
There are multiple lines in each test case.

Each line contains a sentence with several words, or there may be no word within it.

Each word will be separated by one or several whitespace.

Also, whitespaces may appear in the front or in the back of the sentence.

It is guaranteed that:

At most 10 lines in each test case.
Each line contains at most 100 characters.
Contains only lowercase letter in each word.

Output
For each sentence, please output the modified sentence with the reverse sequence of words.

Attention: 

(1) After modification, each word is separated by only one whitespace.

(2) If there is no word in the sentence, you still need to output '\n'.
*/



#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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


void dump(char *a) {
    // method 1
    /*
    for(int i=0; i<strlen(a); i++){
        printf("%c", a[i]);
    }
    printf("\n");*/

    // method 2
    /*
    for(int i=0; i<strlen(a); i++){
        printf("%d ", a[i]);
    }
    printf("\n");*/

    // method 3
    bool first_word = true;
    bool wording = false;
    int sentence_length = strlen(a);
    for (int j=0; j<sentence_length; j++) {
      if (a[j] == ' ') {
        wording = false;
      }
      else {
        // i.e. a[i] != ' '

        if (!wording) {
          if (first_word) {
            first_word = false;
          }
          else {
            printf(" ");
          }
        }

        printf("%c", a[j]);
        wording = true;
      }
    }
    printf("\n");
}

int main(void)
{  
  char a[111];
  for(int i=0; i<10; i++){
    
    if(fgets(a, 99, stdin) != NULL) {
      if(strlen(a) > 1){
        // update aa
        //
        // e.g.,
        //
        // if a = ' xx y zz '
        // then aa = 'xx y zz'
        //
        // if a = 'xx y  zz'
        // then aa = 'xx y zz'
        //
        // if a = 'xx  y  zz'
        // then aa = 'xx y zz'
        //

        a[strlen(a)-1] = 32;
        a[strlen(a)] = 0;
        sentence_reversal(a);
        dump(a);
      }
      else {
        // i.e. a == '\n'
        printf("\n");
      }
    }
    

    
    /*
    if(fgets(a, 99, stdin) != NULL) {
      // Also, whitespaces may appear in the front or in the back of the sentence.
      // After modification, each word is separated by only one whitespace.  
      if(strlen(a) > 1){
        // _this is => is this__
        if(a[0] == ' '){
          for(int i=0; i<strlen(a); i++){
            a[i] = a[i+1];
          }
        }
        
        a[strlen(a)-1] = ' ';

        sentence_reversal(a);
  

        // this is_ => _is this_
        int count = 0;
        int not_blank_index = 0;
        for(int i=0; a[i] != ' '; i++){
          count++;
          not_blank_index = i;
        }
        not_blank_index++;
        printf("c=%d\n", count);
        printf("n=%d\n", not_blank_index);
        //   for(int i=0; i<strlen(a); i++){
        //     a[i] = a[i+1];
        //   }
        for(int i=0; i<count; i++){
          a[i] = a[not_blank_index];
          not_blank_index++;
        }
        
          when a[i] != ' ';
          a[i] = a[0]; 
          a[i+1] = a[1];
          a[i+2] = a[2];
          ...
          to a[i] == '\n'
        

        // for(int i=0; i<strlen(a)-1; i++){
        //   printf("%c", a[i]);
        // }
        // printf("\n");
        
        // check_if_two_blank(a, 0);

        for(int i=0; i<strlen(a)-1; i++){
          printf("%c", a[i]);
        }
        printf("\n");

      }
      //if word == '\n'
      else {
        printf("\n");
      }     
    }
    //if no word
    else {
      printf("\n");
    }*/

  }

  return 0;
}