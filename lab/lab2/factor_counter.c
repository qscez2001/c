

#include <stdio.h>

int count(int r);
int main()
{
   int t;
   int l,r;

   scanf("%d", &t);
   int new_counter, old_counter = 0;
   int max,max_counter;

   for(int i=0;i<t;i++)
   {
      scanf("%d %d", &l, &r);
      //暫存檔：供下次使用 存這次的counter
      old_counter = new_counter;
      //counter = 2 4 2 4 6
      //最新的input r 的counter
      new_counter = count(r);

      //printf("new:%d old:%d\n", new_counter,old_counter);

      //算最大的counter
      //從L到R跑每次算出比之前的大就刷新
      
      if (old_counter == 0)
      {
         max = l;
      }
      else if (new_counter > max_counter)
      {
         max_counter = new_counter;
         max = r;
      }
      else
      {
         max = max;
      }
      //If there are multiple answers, print the smallest of them.
      printf("%d\n", max);
   }


   return 0;
}

//數出每個數字的因數
//要小心完全平方數會少算
int count(int r)
{
   int count = 0;
   for(int i=1; i<=r;i++)
   {
      if(r % i == 0)
      {
         
         count++;
         // if(perfect_square_check(i) == 1)
         // {
         //    count--;
         // }
         //printf("%d ", i);
      }
   }

   //printf("%d\n", count);

   return count;
}

int perfect_square_check(int temp)
{
      int count = 1;
      while(temp > 0 && temp != 1)
      {
            temp = temp - count;
            count = count + 2;
      }
      if(temp == 0)
      {
            return 1;
      }
      return 0;
}