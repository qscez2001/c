// A piece of C code
#include <stdio.h> // GCD 遞迴版
int GCD(int a, int b){
    if( b == 0 )
        return a;
    else
        return GCD( b, a%b );
}
int main(void){
    int a, b; // a,b > 0 
    scanf("%d%d", &a, &b);
    printf("%d\n", GCD(a,b));
    return 0;
}