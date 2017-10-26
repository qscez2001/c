#include<stdio.h>

int drink, buy = 0;

int main()
{
    
    scanf("%d", &drink);
    for(int i=0;i<drink;i++)
    {
        if(i == 0)
        {
            buy = buy + 1;
        }
        else if ((i-3)%3 == 0)
        {
            buy = buy;
        }
        else
        {
            buy = buy + 1;
        }
    }
    printf("%d\n", buy);
}

