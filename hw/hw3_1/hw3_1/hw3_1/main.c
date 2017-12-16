#include <stdio.h>
#include <stdlib.h>

#define for RF
#define while RF
#define goto RF

#include "code.c"

int main(){
	int n;
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
