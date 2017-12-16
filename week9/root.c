//https://gist.github.com/htchen/e86a7d4293d6b33e2dce

/*三座城堡問題
在 3x3 的棋盤上擺三個城堡
城堡走直線
所以每個 row 只能擺一個城堡
修改底下的程式碼
使得最後只輸出滿足互不衝突的擺法*/

#include <stdio.h>

int board[5][5];
void place(int row);
void show_board(void)
{
  int i, j;
  for (i=1; i<=3; i++) {
    for (j=1; j<=3; j++) {
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
void place(int row)
{
  int i;
  if (row>3) {
    show_board();
  } else {
    for (i=1; i<=3; i++) {
      board[row][i] = 1;
      place(row+1);
      board[row][i] = 0;
    }
  }
}