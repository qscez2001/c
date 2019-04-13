#include <stdio.h>
#include <stdbool.h>

void update_A(int a[8][8], int n, int i, int A[8][8]) {
    for (int x=0; x<n-1; x++) {
        for (int y=0; y<n-1; y++) {
            if (y < i) {
                A[x][y] = a[x+1][y];
            }
            else {
                A[x][y] = a[x+1][y+1];
            }
        }
    }
}

long long int cal_determinant(int a[8][8], int n) {
    long long int ans = 0;

    if (n == 2) {
        ans = a[0][0]*a[1][1] - a[0][1]*a[1][0];
    }
    else {
        int sign = -1;
        for (int i=0; i<n; i++) {
            int A[8][8] = { 0 };
            update_A(a, n, i, A);
            ans += a[0][i]*(sign)*(-1)*cal_determinant(A, n-1);
            sign *= -1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[8][8] = { 0 };
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    long long int ans = cal_determinant(a, n);
    printf("%lld\n", ans);
}