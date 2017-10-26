#include<stdio.h>

//Find smallest prime number greater than given nth
int t, x, nth;
int main()
{
    
    scanf("%d", &t);
    //check t times
    for(int i=0; i<t; i++)
    {
        scanf("%d %d", &x, &nth);
        printprime();
        
    }
    
    return 0;
    
}

//print needed prime number
int printprime()
{
    int pn = 0;
    for(int i=x; i<100000; i++)
    {
        if (is_prime(i) == 1)
        {
            pn++;
            if (pn == nth)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}

//check if is prime
int is_prime(int num)
{
    if (num <= 1) return 0;
    if (num % 2 == 0 && num > 2) return 0;
    for(int i = 3; i < num / 2; i+= 2)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
