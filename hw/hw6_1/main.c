#include <stdio.h>
#include "function.h"
#include <stdlib.h>

struct student{
	char name[20];
	int score;
};

/*
  0
  1
  2
  3
  4
  5
  6
  7
  8
  9
  10
  11
  12
  13
  14
  15
  16
  17
  18
  19
  20
  21
  22
  23
*/

int main(){

	struct student j;
	j.score = 59; // so naughty
  // printf("%d\n", &j.name);
  // printf("%d\n", j.score);
  // printf("%d\n", &j.score);
	query_my_score (j.name);

  // printf("%d\n", j.score);
  // printf("%s\n", j.name);
	if( j.score == 300)
		printf("%s pass the course\n", j.name);
	else
		printf("%s failed QAQQ\n", j.name); 
}
