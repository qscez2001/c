#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
int compare_double(const void*   a, const void*  b)
{
  double*  va  = (double *) a;
  double*  vb  = (double *) b; 
  if (*va > *vb) return 1;
  else if (*va < *vb) return -1;
  else return 0;
}


int compare_int(const void*   a, const void*  b)
{
  int*  va  = (int *) a;
  int*  vb  = (int *) b; 
  if (*va > *vb) return 1;
  else if (*va < *vb) return -1;
  else return 0;
}

void swap(char* a, char* b, size_t width)
{
  char tmp;
  while (width>0) {
    tmp = *a;
    *a = *b;
    *b = tmp;
    width--; a++; b++;
  }
}
void mysort(void* arr, size_t num, size_t width, int (*cmp) (const void *,const void*) )
{
  char* array = arr;
  int i, swapped; 
  do {
    swapped = 0;
    for (i=1; i<num; i++) {
      if (cmp(array+i*width, array+(i-1)*width)<0) {
        swap(array+i*width, array+(i-1)*width, width);
        swapped = 1;
      }
    }
  } while (swapped);  

}

typedef struct _myData {
  int idx;
  int x;
  double z;
  char str[100];
  struct _myData * next;
} MyData;

int compare_ps(const void* a, const void* b);

void randstr(char* s, size_t t)
{
  while (t>0) {
    *s = rand()%26 + 'A';
    s++;
    t--;
  }
  *s = '\0';
}

int main(void) {
  int data[SIZE]; 
  double data_d[SIZE];
  MyData* data_s;
  MyData* head;
  MyData*  ps[SIZE];

  int i; 
  for (i=0; i<SIZE; i++) {
    data[i] = rand()%SIZE;
    data_d[i] = (double)rand()/RAND_MAX;

    data_s = (MyData*) malloc(sizeof(MyData));
    data_s->idx = i;
    data_s->x = data[i];
    data_s->z = data_d[i];
    randstr(data_s->str, 10);
    ps[i] = data_s;
  }
  for (i=0; i<SIZE-1; i++) {
    ps[i]->next = ps[i+1];
  }
  ps[SIZE-1]->next = NULL;
  head = ps[0];

/*
  printf("Before sorting:\n");
  for (i=0; i<SIZE; i++) printf("%d ", data[i]);
  printf("\n");

  mysort(data, SIZE, sizeof(int), compare_int);

  printf("After sorting:\n");
  for (i=0; i<SIZE; i++) printf("%d ", data[i]);
  printf("\n");

  printf("Before sorting:\n");
  for (i=0; i<SIZE; i++) printf("%.2f ", data_d[i]);
  printf("\n");

  mysort(data_d, SIZE, sizeof(double), compare_double);

  printf("After sorting:\n");
  for (i=0; i<SIZE; i++) printf("%.2f ", data_d[i]);
  printf("\n");
*/

  printf("Before sorting:\n");  
  for (i=0; i<SIZE; i++) printf("[%2d] %d %.2f %s %p\n", 
      ps[i]->idx, ps[i]->x, ps[i]->z, ps[i]->str,
      ps[i]->next);
  printf("\n");

  mysort(ps, SIZE, sizeof(MyData*), compare_ps);

  printf("After sorting:\n"); 
  for (i=0; i<SIZE; i++) printf("[%2d] %d %.2f %s %p\n", 
      ps[i]->idx, ps[i]->x, ps[i]->z, ps[i]->str,
      ps[i]->next);
  printf("\n");
  
  MyData *pp = head;
  while (pp!=NULL) {
    printf("%d\n", pp->x);
    pp = pp->next;  
  }

  return 0;
}

int compare_ps(const void* a, const void* b)
{
  MyData** va = (MyData**) a;
  MyData** vb = (MyData**) b;
  if ((*va)->x > (*vb)->x) return 1;
  else if ((*va)->x < (*vb)->x) return -1;
  else return 0;// strcmp((*va)->str, (*vb)->str);
}