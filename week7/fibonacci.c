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