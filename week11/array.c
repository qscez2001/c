#include<stdio.h>

//*z = z[]
void g(int* z, int n)
{
  for(int i=0; i<n; i++){
    z[i] = 777;
  }
}

int main()
{
  int a[100];
  g(a, 100);
}