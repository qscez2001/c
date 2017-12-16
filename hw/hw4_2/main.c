// The first line contains one integer n, representing the number of nodes in the tree.

// The second line contains n integer ai, representing the level order of the tree.

// n = 2^k - 1
// 1 ≤ k ≤ 10
// n<= 1023
// a1 ~ an is a permutation of 1 ~ n

// Please output the sequence of number after the tree is flattened. 
// Each number is separated by a whitespace.

// Sample Input
// 7
// 4 2 6 1 3 5 7

// Sample Output
// 1 2 3 4 5 6 7

//       4(1)
//     2(2) 6(3)
// 1(4) 3(5) 5(6) 7(7)

#include <stdio.h>
#include <string.h>
int n;
int a[2000];
int b[2000];

void InorderTraversal(int index) {

  if (index <= n) {
    int leftNode = index*2;
    int rightNode = index*2+1;

    InorderTraversal(leftNode);
    if (index == n){
      printf("%d\n", a[index]);
    }
    else{
      printf("%d ", a[index]);
    }
    InorderTraversal(rightNode);
  }
}

int main()
{
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d", &a[i]);
  }
  int index = 1;
  InorderTraversal(index);

  // for(int i=0; i<n; i++)
  // {
  //   printf("%d ", a[i]);
  // }
}

