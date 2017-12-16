// https://acm.cs.nthu.edu.tw/problem/11717/
#include <stdio.h>
int arr[2][2];
// int sum[70000];
int s = 0;
int k = 0;
int max;
//6 -> 9
//6/2 = 3
//3*3 = 9
//250*250 = 

int main(){
    int A[500][500];
    int ans = 0;

    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }
    int i, j;
    /*  Your Code:  */
    for( i = 0; i < n; i+=2){
        
        for( j = 0; j < n; j+=2){
            // printf("i=%d,j=%d\n", i, j);
            // 0, 0
            arr[0][0] = A[i][j];
            // printf("i=%d,j=%d\n", i, j);
            // 0, 1
            arr[0][1] = A[i][j+1];

            // printf("i=%d,j=%d\n", i, j);
            // 1, 0
            arr[1][0] = A[i+1][j];
            // printf("i=%d,j=%d\n", i, j);
            // 1, 1
            arr[1][1] = A[i+1][j+1];
            s = 0;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    s = s + arr[i][j];
                    // printf("%d ", arr[i][j]);

                }
                // printf("\n");
            }
            // printf("%d\n", s);
            if (s >= max) {
                max = s;
            }
            // sum[k] = s;
            // k++;
        }
    }

    // for(int i = 0; i < k; i++) printf("%d ", sum[i]);
    
    // int swap;
    // for (int c = 0 ; c < ( k - 1 ); c++)
    //       {
    //         for (int d = 0 ; d < k - c - 1; d++)
    //         {
    //           if (sum[d] > sum[d+1])  For decreasing order use < 
    //           {
    //             swap       = sum[d];
    //             sum[d]   = sum[d+1];
    //             sum[d+1] = swap;
    //           }
    //         }
    //      }
    
    // for(int i = 0; i < k; i++) printf("%d ", sum[i]);
    // ans = sum[k-1];
    ans = max;
    printf("%d\n", ans);
    return 0;
}