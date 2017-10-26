/*
輸入一個正整數
程式必須列出除了 1 和該正整數本身以外的全部因數
因數必須從小到大排列
如果無法因數分解
則成是必須顯示這個正整數是質數
*/

#include <stdio.h>
int main()
{
   int num, div;
   int isPrime;

   printf("Please enter an integer (q to quit): \n");

   scanf("%d", &num);
   
   //36: 檢查 2.3.4.5.6
   //檢查到開庚號的數字就好
   for(div=2, isPrime = 1;div*div <= num; div++)
   {
      if(num % div == 0) {
         isPrime = 0;
         printf("%d\n", div);
      }
   }


   if (isPrime)
      printf("%d is prime.\n", num);

   else
      //\b: 游標倒退
      printf("\b\b are divisors of %d\n", num);

   return 0;
}