#include <stdio.h>
#include <math.h>

int count(int r);
int main()
{
   int t;
   scanf("%d", &t);

   for(int i=0;i<t;i++)
   {
      int l,r;
      scanf("%d %d", &l, &r);

      int new_counter = 0, max_counter = 0, result = 0;
      // printf("DEBUG sqrt(r) = %f \n", sqrt(r));

      for(int j = l; j<=r; j++)
      {
         new_counter = count(j);
         // printf("DEBUG %d %d\n", j, new_counter);

         if (new_counter > max_counter)
         {
            max_counter = new_counter;
            result = j;
         }
      }
      printf("%d\n", result);
   }


   return 0;
}

int count(int n)
{
    if (n == 1) return 1;

    int count = 2;

    for(int i=2; i*i<=n; i++) {
        if(n % i == 0) {
            if (n == i*i) {
                count +=1;
            }
            else {
             count +=2;
            }
        }
    }

   return count;
}