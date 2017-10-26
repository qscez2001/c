// Description
// The input contains three numbers, which are the 2nd, 
// the 3rd and the 4th number of  an arithmetic progression (等差數列) or 
// a geometric progression (等比數列). Your task is to distinguish which progression 
// it is from this numbers and print out the first number and the 5th number.

// For example, if the input is  3 5 7, then you know this is an arithmetic progression 
// and the common difference is 2. So the 1st and 5th number is 1 and 9 respectively.



#include<stdio.h>


int main()
{
  int nd, rd, th;
  scanf("%d %d %d", &nd, &rd, &th);

  if(th-rd == rd-nd)
  {
    //it's a arithmetic progression (等差數列)
    printf("%d ", nd-(th-rd)); //1st
    printf("%d",th+(th-rd)); //5th
  }
  else if(th/rd == rd/nd)
  {
    //it's a geometric progression (等比數列). 
    printf("%d ", nd/(th/rd)); //1st
    printf("%d",th*(th/rd)); //5th
  }
  return 0;
}