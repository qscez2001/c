#include <stdio.h>
#include <string.h>



void query_my_score (char *name)
{
  name[0] = 'j';  
  name[1] = 'j'; 
  name[2] = 'j'; 
  name[3] = 'j'; 
  name[4] = 'j'; 

  int *i = name;
  *(i+5) = 300;
}
/*
char myname[] = "jjjj";
  int score = 300;
  // printf("%d\n", name);
  // int pt = name + 20;

  // printf("%d\n", pt);
  // 128  256  512
  // *(name + 20) = 250;

  memcpy ( name, myname, strlen(myname)+1);

  memcpy ( name + 20, score, 2);
*/