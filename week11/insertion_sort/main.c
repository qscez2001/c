#include <stdio.h>
int data[100000];

void sort(int *a, int n)
{
  int x;
  for(int i=0; i<n; i++){
    int j=i;
    x = data[i];
    while(j > 0 && data[j-1] > x)
    {
      data[j] = data[j-1];
      j--;
    }
    data[j] = x;
  }
}

int main()
{
  int num_data;

  freopen("data_50000.txt", "r", stdin);
  scanf("%d", &num_data);

  for(int i=0; i<num_data; i++)
  {
    scanf("%d", &data[i]);
  }
  

  freopen("data_50000_sorted.txt", "w", stdout);
  for(int i=0; i<num_data; i++)
  {
    printf("%d ", data[i]);
  }

  return 0;
}