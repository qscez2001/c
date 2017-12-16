//https://acm.cs.nthu.edu.tw/contest/1342/
/*
Given an m ✕ n matrix A, please calculate the transpose of A.

Note: The is a partial judge problem. 
We have already handled the input and output for you. 
All you have to do is to implement the function "Transpose".

The first line contains two integer m, n, representing the dimension of A.
The next m lines contain n integers aij, representing the indices of A.

1 ≤ m, n ≤ 500

2 3
1(0,0) 2(0,1) 3(0,2)
2(1,0) 3(1,1) 4(1,2)

1(0,0) 2(0,1)
2(1,0) 3(1,1)
3(2,0) 4(2,1)
*/


#include <stdio.h>
#include <stdint.h>
#include "function.h"

void Print(int m, int n, int matrix[][500] ) {
    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            printf("%d%c", matrix[i][j], " \n"[j==n-1] );
        }
    }
}

void Transpose( int* row, int* col, int matrix[][500] )
{
    /*
    int tmp = *row;
    *row = *col;
    *col = tmp;
    //printf("row = %d col = %d\n", *row, *col);
    for( int i = 0; i < *col; i++) {
        for( int j = 0; j < *row; j++) {
            matrix[j][i] = matrix[i][j];
        }
    }
    */

    int tmp, i, j;
    int t[501][501];
    for( i = 0 ; i < *col; i++){
        for( j = 0; j < *row; j++){
            t[i][j] = matrix[j][i];
        }
    }

    for(i=0 ;i < *col; i++){
        for(j=0; j < *row; j++){
            matrix[i][j] = t[i][j];
        }
    }

    tmp = *row;
    *row = *col;
    *col = tmp;
}

int32_t main(){
    int matrix[500][500];
    int row, col;
    scanf("%d %d", &row, &col);
    for ( int i = 0; i < row; i++ ) {
        for ( int j = 0; j < col; j++ ) {
            scanf("%d", &matrix[i][j]);
        }
    }
    Transpose( &row, &col, matrix);
    Print( row, col, matrix );
    return 0;
}
