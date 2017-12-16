#include<stdio.h>
#include<string.h>

/*
Input
The first line contains an integer T, representing the number of testcases.

Each testcase contains two lines :

The first line contains an integer n, representing the number of sticks HT picks.

The second line contains n integer ai, representing the length of each sticks.

It is guaranteed that :

testcase #1 : Sample Input
testcase #2~4 : T = 1, n = 3, 1 ≤ ai ≤ 100
testcase #5~8 : 1 ≤ T ≤ 10, 1 ≤ n ≤ 100, 1 ≤ ai ≤ 100
testcase #9~10 : 1 ≤ T ≤ 10, 1 ≤ n ≤ 1000, 1 ≤ ai ≤ 100
If you can't pass testcase #9 & #10 immediately, try to solve another two problems first.  

Output
For each testcase, please output a line contains one integer represents the length of the triangle with the maximum possible perimeter. If the sticks can't form a triangle, please output -1.
*/

void dump_sticks(int *n, int *sticks) {
    for (int i=0; i<*n; i++) {
        printf("%d ", sticks[i]);
    }
    printf("\n");
}

void run_testcase(int *n, int *sticks) {
    //printf("DEBUG: n = %d\n", *n);

    int result = -1;

    // sort sticks
    for (int i=0; i<*n; i++) {
        for (int j=0; j<*n-1; j++) {
            if (sticks[j] < sticks[j+1]) {
                int temp = sticks[j];
                sticks[j] = sticks[j+1];
                sticks[j+1] = temp;
            }
        }
    }
    //dump_sticks(n, sticks);

    // start from picking the top 3 longest sticks
    // if n1 < n2 + n3 set result
    // else check n2, n3, n4
    for (int i=0; i<*n-2; i++) {
        int n1 = sticks[i];
        int n2 = sticks[i+1];
        int n3 = sticks[i+2];

        if (n1 < n2 + n3) {
            result = n1 + n2 + n3;
            break;
        }
    }

    printf("%d\n", result);
}

void load_testdata(int *T, int *n, int *sticks) {
    scanf("%d", T);
    //printf("DEBUG: T = %d\n", *T);

    for (int t=0; t<*T; t++) {
        //printf("DEBUG: case %d\n", t+1);

        scanf("%d", n);
        //printf("DEBUG: n = %d\n", *n);

        for (int s=0; s<*n; s++) {
            scanf("%d", &sticks[s]);
            //printf("DEBUG: stick length = %d\n", sticks[s]);
        }

        run_testcase(n, sticks);
    }
}

int main(){
    int T;
    int n;
    int sticks[1001];
    load_testdata(&T, &n, sticks);
    return 0;  
}