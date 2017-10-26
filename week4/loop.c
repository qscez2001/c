#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   int word_len;
   char word[40];
   scanf("%s", &word);

   word_len = strlen(word);

   for (int i = 1; i <= word_len; i++) 
   {
      for( int k = 0; k<word_len-i;k++)
          {
            printf(" ");
          }
      for (int j = 0; j < i; j++)
      {
        printf("%c", word[j]);
      }
      printf("\n");
   }

   return 0;
}