// A piece of C code
#include <stdio.h>
int power(int a, int n){
    if( n == 1 ) return a;
    int sqrt = power(a,n/2); // 這裡有使用到整數除法無條件捨去的特性。
    if( n % 2 == 0 )
        return sqrt * sqrt;
    else 
        return a * sqrt * sqrt;
}
int main(void){
    int a, n;
    scanf("%d%d", &a, &n);
    printf("%d\n", power(a,n));
    return 0;
}