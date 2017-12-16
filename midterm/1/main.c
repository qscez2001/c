#include <stdio.h>
int n;
int arr[200000];
int count=1;

/*由未排序中的第一筆開始，與第二筆資料比對
若第一筆 > 第二筆 ⇒ 交換位置(Swap)
若還有未排序的資料，則用第二筆和第三筆資料比對
依此類推
若未排序的資料中，比對時都沒有進行交換位置 ⇒ flag = false
代表資料已排序好 ⇒ 提早結束排序
執行時，未排序資料中的最大值會如同氣泡般往右跑*/

void swap(int *xp, int *yp)
  {
      int temp = *xp;
      *xp = *yp;
      *yp = temp;
  }

int main()
{
  scanf("%d", &n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }

  int flag = 1;
  for (int i = 0; i < n-1 && flag == 1; i++){

    flag = 0;
   // Last i elements are already in place   
    for (int j = 0; j < n-i-1; j++) 
       if (arr[j] > arr[j+1]){
          swap(&arr[j], &arr[j+1]);
       }else {
          flag = 1;
       }
     }


  for(int i=0;i<n-1;i++)
  {
    if(arr[i] !=arr[i+1])
      count+=1;
    //printf("%d",arr[i]);
  }

  printf("%d\n",count);
}