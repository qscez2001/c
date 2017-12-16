/*
在西洋棋盤上面，騎士的走法是日字形，就像象棋中馬的走法一樣。 
Knight's Tour 的問題是，我們要如何找出一條路徑，可以讓騎士把棋盤上所有的格子都走遍。

這個問題看似比八皇后的問題複雜，其實概念上是差不多的。因為騎士的走法，在一個位置的騎士有八個可能的方向可以走。
在計算時每走完一個方向後必須退回到目前的位置，再往另一個方向接著計算。
藉由遞迴的特性，我們可以在一個函式中呼叫下一個函式做接下去的運算，同時卻不會忘記目前的狀態。
*/

// A piece of C code
#include <stdio.h>
#define n 5//棋盤大小
#define start_row 3
#define start_col 3

int board[n+2][n+2];

void place(int row, int col, int num);

void show_board(void)
{
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            if(board[i][j]<10){                   //為了讓輸出的棋盤更好看
                printf(" %d ", board[i][j]);
            }else{
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    place(start_row, start_col, 1);
    return 0;
}

int valid(int row, int col)
{
    if(board[row][col]==0 && row>=1 && row<=n && col>=1 && col<=n){
        return 1;
    }
    return 0;
}

void place(int row, int col, int num)
{
    if (num==n*n+1) {
        show_board();
    } else {
        if(valid(row, col)){
            board[row][col]=num;
            place(row-2, col+1, num+1);
            place(row-1, col+2, num+1);
            place(row+1, col+2, num+1);
            place(row+2, col+1, num+1);
            place(row+2, col-1, num+1);
            place(row+1, col-2, num+1);
            place(row-1, col-2, num+1);
            place(row-2, col-1, num+1);
            board[row][col]=0;
        }
    }
}