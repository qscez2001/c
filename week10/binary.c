//列舉所有的二進位位元

#include <stdio.h>
void show_bits(int );
char bits[64];
int N;
int main(void)
{
    printf("Please enter the number of bits: ");
    scanf("%d", &N);

    bits[N] = '\0';
    show_bits(0);

    return 0;
}

void show_bits(int x)
{
    if (x==N) {
        printf("%s\n", bits);
    } else {
        bits[x] = '0';
        //窮舉 第一個字是0的所有組合
        show_bits(x+1);
        bits[x] = '1';
        //窮舉 第一個字是1的所有組合
        show_bits(x+1);
    }
}