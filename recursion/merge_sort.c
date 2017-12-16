// A piece of C code
#include <stdio.h>
#define MAXN 1000000

int a[MAXN], buffer[MAXN];
void merge(int *A, int lena, int *B, int lenb){
    int i = 0, j = 0, k = 0; // index for A, B, and buffer
    while( i < lena && j < lenb ){
        if( A[ i ] < B[ j ] ) // use '<' to make merge sort stable
            buffer[ k++ ] = A[ i++ ];
        else
            buffer[ k++ ] = B[ j++ ];
    }
    while( i < lena )  buffer[ k++ ] = A[ i++ ];
    while( j < lenb )  buffer[ k++ ] = B[ j++ ];
}

void merge_sort(int l, int r){
    if( l >= r ) return; // bound condition
    int mid = (l+r)/2;   // recurtion
    merge_sort( l, mid );
    merge_sort( mid+1, r );
    merge( a+l, mid-l+1, a+mid+1, r-mid );
    int i;
    for(i=0; i<r-l+1; i++){
      a[l+i] = buffer[i];
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    merge_sort( 0, n-1 );
    for (i=0; i<n; ++i){
        printf("%d ", a[i]);
    }
    return 0;
}