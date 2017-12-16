// A piece of C code
/*
    1       1
   1 1      1
  1 2 1     2
 1 3 3 1    3

F(5) = F(4) + F(3)
     = [ F(3) + F(2) ] + [ F(2) + F(1) ]
     = [ F(2) + F(1) + F(2) ] + [ F(2) + F(1) ]
*/

/*
#include <stdio.h> // 遞迴版
int fib(int i){
    if( i == 1 || i == 2 )
        return 1;
    else
        return fib(i-1) + fib(i-2);
}
int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}
*/

// A piece of C code
#include <stdio.h> // 遞迴版(有紀錄)
int table[100];
int fib(int i){
    if( table[i] != 0 ) return table[i]; // if table[i] == 0, 代表這格沒有被填過 要算!
    if( i == 1 || i == 2 )
        return 1;
    else{
      table[i] = fib(i-1) + fib(i-2); // 算完了當然要記起來啊
        return table[i];
    }
}
int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}