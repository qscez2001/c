
//what if only 1 character
//ex. a=1 1111 1212

#include<stdio.h>
#include<string.h>

int main()
{
  int max = 0;
  char A[5];
  int n;
  scanf("%s", &A);
  scanf("%d", &n);
  char str[100];
  int count[100] = {0};int c = 0;
  //掃n行
  for(int i=1;i<=n;i++)
  {
    scanf("%s", &str);
    //檢查每個string 1~10 裡有沒有A
    //如果有 count+1
    //如果A的每一個字元=string
    //A的長度
      switch(strlen(A))
      {
        case(1):
          for(int k=0;k<=strlen(str)-1;k++)
          {
            if(str[k] == A[0])
            {
              count[c]+=1;
            }
          }
          break;
        case(2):
          for(int k=0;k<=strlen(str)-2;k++)
          {
            
            if (str[k] == A[0] && str[k+1] == A[1])
            {
              count[c]+=1;
              //printf("c=%d counc[c]=%d\n", c, count[c]);
            }      
          }
          break;
        case(3):
          for(int k=0;k<=strlen(str)-3;k++)
          {
            if (str[k] == A[0] && str[k+1] == A[1] && str[k+2] == A[2])
            {
              count[c]+=1;
            }      
          }
          break;
        case(4):
          for(int k=0;k<=strlen(str)-4;k++)
          {
            if (str[k] == A[0] && str[k+1] == A[1] && str[k+2] == A[2] && str[k+3] == A[3])
            {
              count[c]+=1;
            }      
          }
          break;
      } 
    
    if (count[c] > max) {
      max = count[c];
    }
    //跑完之後紀錄下一個string的count
    c+=1;  


  }

  //c代表了有幾個string..
  //printf("c=%d\n", c);

  //找出max
/*
  int max;
  //只有1個string的case
  //[3]
  if (c==1)
   {
     max = count[0];
   }
  //至少有2個string的case
  else
  {
    max = count[0];
    //[1,2] c=2
    //[2,1] c=2
    //[3,4,1,2] c=4

    for(int i=1;i<c;i++)
    {
      //printf("i=%d\n", i);
      if(count[i]>max)
      {
        max = count[i];
      }
    }
  }
  */
  printf("%d", max);
  return 0;
}