/*
八皇后的問題和城堡問題很像，只是皇后的走法不太一樣。
皇后除了可以像城堡那樣走之外，還可以不限距離45度鞋向走。

雖然皇后的走法不一樣，但是解決問題的基本概念和城堡問題一樣，都是一步一步看這個位置有沒有辦法放皇后，
可以的話再移到下一列檢查之後的可能。
*/

// A piece of C code
#include <stdio.h>
#define NQ 8//棋盤大小

int q[NQ] = {0};

void place(int row);
int valid(int row, int col);
void display(void);

int main(void)
{

  place(0);
  return 0;
}


int valid(int row, int col)
{
  int i;
  for (i=0; i<row; i++) {
    if ( q[i] == col || row-i == col-q[i] || row-i == q[i]-col )
    return 0;
  }
  return 1;
}

void display(void)
{
    int i, j;
    for (i=0; i<NQ; i++) {
      for (j=0; j<NQ; j++) {
          if (q[i]==j) printf("@");
          else printf(".");
      }
      printf("\n");
  }
  printf("\n");
}

void place(int row)
{
  int j;
  if (row == NQ) {
    display();
  } else {
    for (j=0; j<NQ; j++) {
      if (valid(row, j)) {//判斷這個位置會不會跟前面已經擺放的起衝突
        q[row] = j;
        place(row+1);
      }
    }
  }
}