#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int last_bit(int *num) {
    int one_or_zero = *num - (*num >> 1)*2;
    *num = *num >> 1;

    //printf("DEBUG: %d\n", one_or_zero);
    return one_or_zero;
}

void update_bits(int *bits, int num) {
    for (int pos=19; pos>-1; pos--) {
        if (last_bit(&num) == 1) bits[pos]++;
        else bits[pos]--;
    } 
}

int cal_k(int bits[20]) {
    int k = 0;

    for (int pos=19; pos>-1; pos--) {
        if (bits[pos] > 0) k += pow(2, (19-pos));
    } 

    //printf("DEBUG: %d\n", k);
    return k;
}

unsigned long long cal_sum(int n, int a[100000], int k) {
    unsigned long long sum = 0;

    for (int i=0; i<n; i++) {
        sum += a[i] ^ k;
    }

    //printf("DEBUG: %llu\n", sum);
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int bits[20] = { 0 };
    int a[100000] = { 0 };
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        update_bits(bits, a[i]);
    }

    // DEBUG: dump bits
    //for (int pos=0; pos<20; pos++) printf("%d ", bits[pos]);

    int k = cal_k(bits);

    unsigned long long sum = cal_sum(n, a, k);
    printf("%llu\n", sum);    
}