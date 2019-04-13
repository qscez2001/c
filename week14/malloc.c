// 在程式執行期間取得記憶體
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
   double *ptd;
   int array_size, i;

   printf("How many doubles do you want? ");
   scanf("%d", &array_size);
   ptd = (double *) malloc(array_size * sizeof (double));
   if (ptd == NULL) {
      printf("Memory allocation failed.\n");
      exit(EXIT_FAILURE);
   }

   for (i = 0; i < array_size; i++) {
      ptd[i] = (double) rand() / RAND_MAX;
   }
   for (i = 0; i < array_size; i++) {
      if (*(ptd+i) > 0.5)
         printf("%d: %f\n", i, ptd[i]);
   }

   free(ptd);

   return 0;
}
*/

#include <stdio.h>
int main(void)
{
   int *a, **b, i, j, rows, cols;
   
   scanf("%d %d", &rows, &cols);
   a = (int *) malloc(rows * cols * sizeof(int));
   for (i = 0; i < rows*cols; i++) a[i] = i;
   b = (int* *) malloc(rows * sizeof(int *));

   for (i = 0 ; i < rows; i++) b[i] = &a[i*cols];


   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         printf("%3d ", b[i][j]); 
      }
      printf("\n");
   }
   
   free(b);
   free(a);

   return 0;
}
