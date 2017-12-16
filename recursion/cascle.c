/*
有玩過西洋棋嗎？在西洋棋的規則當中，城堡是可以不限距離橫向或直向移動的。
如果想要在一個 n 乘 n 的棋盤上擺放最多的城堡，使每一個城堡都沒辦法一步就吃到對方。
那這樣最多會有哪多少擺放方式呢？

我們可以這樣想

先在第一列第一個位置擺上一個城堡，在到第二列看哪些位置可以再擺上另一個城堡使新擺上的城堡不和之前的城堡互相衝突。
第一列第一個位置的組合全部試過了之後，將這個城堡移到第一列的第二個位置，再看下一列之後可以放在哪裡。以此類推。
在每一步中往前看有沒有和之前的城堡衝突，若沒有，先擺上去在檢查下一列。
當之後的列都檢查完組合了，則將這列的城堡往下移到下一行，繼續檢查之後的列。
停止條件為到最後一列結束。

我們可以看到這個問題非常適合用遞迴，因為這一列的問題不會影響到前面的列。
若我們用遞迴呼叫 function ，那這個問題就變得簡單得多，因為 function 就只需要判斷他那一列的工作就可以了。
讓我們來看看下面的程式碼
*/



// A piece of C code
#include <stdio.h>
#define n 3//棋盤大小

int board[n+2][n+2];
void place(int row);
void show_board(void)
{
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(void)
{

    place(1);
    return 0;
}
int valid(int row, int col)
{
    int i;
    for (i=1; i<row; i++) {
        if (board[i][col]) return 0;
    }
    return 1;
}
void place(int row)
{
    int i;
    if (row>n) {
        show_board();
    } else {
        for (i=1; i<=n; i++) {
            if (valid(row, i)) {//判斷這個位置會不會跟前面已經擺放的起衝突
                board[row][i] = 1;
                place(row+1);
                board[row][i] = 0;
            }
        }
    }
}