#include <stdio.h>

void f(int* ap, int* ap_end);
void g(int* * cp)

int main()
{
  int a[20];
  int b[4]  [5];
  int* c[4];

  f(&b[0], b+5);

  int i;
  for(i=0; i<20; i++) a[i] = i;
  //c store a's specific address
  for(i=0; i<4; i++) c[i] = &a[i+5];

  //turn to two-dimension-array
  for(i=0; i<4; i++){
    for(j=0; j<5; j++){
      printf("%d ", c[i][j]);
      //equals to
      printf("%d ", a[i*5+j]);
    }
  }
}