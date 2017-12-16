/*
輸入不同面值的銅板
然後輸入一個金額
將全部可能的找零方式列出
譬如有 1 元、5元、10元銅板
要湊出 17 元
如果將可能的組合表示成 "(1元個數,5元個數,10元個數)"
總共會有下列幾種方法

我們可以用 遞迴 方式來看待這個問題:
首先依序考慮使用 1元、5元、10元的情況
假設現在我們手邊有 M 元需要換成銅板
從 1 元開始考慮
我們可以把問題區分成兩種可能
1. 使用 1 元，因此狀態變成手邊有 M-1 元，然後試著繼續用 1 元、5元、10元來湊
2. 完全不使用 1，因此狀態變成手邊還是有 M 元，但是只考慮用 5元 和 10元來湊
以上兩種可能都可以讓問題簡化
第一種是讓錢變少，另一種則是讓需要考慮的銅板面值變少
用這樣的方式繼續簡化下去
只會需要可慮幾種結束方式
1. 手邊剩下 0 元，表示成功湊出組合
2. 手邊剩下 m 元，m<0，表示這樣的組合不可能湊出需要的金額
3. 沒有任何可用的銅板面額可供組合
其餘情況就繼續遞迴
*/

//input
// 3
// 1 5 10
// 17

//output
// (2,1,1)
// (2,3,0)
// (7,0,1)
// (7,2,0)
// (12,1,0)
// (17,0,0)
#include <stdio.h>
//最多五種幣值
#define MAXNV 20
int values[MAXNV]; // = {1, 5, 10}
int numbers[MAXNV]; // = {2, 1, 1}

void checkiftheset(int nv);
//smallest: 最小幣值的 index
void change(int amount, int smallest, int nv);
int ans = 0;


int main(void)
{
  int nv, i;
  int money;

  scanf("%d", &nv);
  if (nv>MAXNV || nv<1) return 0;

  for (i=0; i<nv; i++) {
    scanf("%d", &values[i]);
  }

  scanf("%d", &money);
  change(money, 0, nv);
  printf("%d\n", ans);
  return 0;
}

void checkiftheset(int nv)
{
  int i;
  for (i=0; i<nv; i++) {
    if(numbers[i] != 1 && numbers[i] != 0) return;
    //printf(",%d", numbers[i]);
  }
  ans++;
}
//17, 0, 3
void change(int amount, int smallest, int nv)
{
  //考慮各種換法
  //       [0][1][2]
  //values  1 5 10
  //numbers 2 1 1
  if (smallest<nv) {
    if (amount == 0) {
      checkiftheset(nv);
    } else if (amount > 0) {
      change(amount, smallest+1, nv);
      //還原成還沒做的解法, 用來試下一個解法
      numbers[smallest]++;
      change(amount-values[smallest], smallest, nv);
      numbers[smallest]--;
    }
  }
}