// https://acm.cs.nthu.edu.tw/problem/11717/
#include <stdio.h>
int sum[1000];
int s = 0;
int i=0, j=0, k=0;

void calsum(int arr[][3], int A[][500], int n)
{
    s = 0;
    if(j<n){
        arr[0][0] = A[i][j];
        j++;
        arr[0][1] = A[i][j];
        i++;
        arr[1][1] = A[i][j];
        j--;
        arr[1][0] = A[i][j];
        i--;
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                s = s + arr[i][j];
            }
        }

        sum[k] = s;
        //printf("k=%d\n", k);
        //printf("%d ", sum[k]);
        k++;
        //printf("%d\n", s);
        j+=2;
        calsum(arr, A, n);
    }
    
    while(i<n){
        i += 2;
        j = 0;
        calsum(arr, A, n);
    }
    
}

int main(){
    int A[500][500];
    int arr[3][3];
    int ans = 0;

    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }
    int arr_num = (n/2) * (n/2);
    /*  Your Code:  */
    calsum(arr, A, n);
    int swap;
    //for(int i=0; i<n; i++) printf("%d ", sum[i]);
    for (int c = 0 ; c < ( n - 1 ); c++)
      {
        for (int d = 0 ; d < n - c - 1; d++)
        {
          if (sum[d] > sum[d+1]) /* For decreasing order use < */
          {
            swap       = sum[d];
            sum[d]   = sum[d+1];
            sum[d+1] = swap;
          }
        }
      }
    //for(int i=0; i<n; i++) printf("%d ", sum[i]);
    ans = sum[arr_num-1];
    printf("%d\n", ans);
    return 0;
}