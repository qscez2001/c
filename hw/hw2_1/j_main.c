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
        if (isPrime(i) == 1)
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

// Source: http://edisonshih.pixnet.net/blog/post/27946379-%5B%E6%BC%94%E7%AE%97%E6%B3%95---%E6%95%B8%5D-%E6%B1%82%E8%B3%AA%E6%95%B8%E6%95%88%E7%8E%87%E5%88%86%E6%9E%90
// This is the faster version of prime checking function
int isPrime(int n)
{
    if (n == 1) return 0;

    if (n%2==0 && n!=2) return 0;

    int i=0;
    for (i=3; i*i<=n; i+=2) if (n%i==0) return 0;

    return 1;
}


// This is the slower version of prime checking function
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
