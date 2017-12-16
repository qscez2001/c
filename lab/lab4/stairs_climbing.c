//11700 - Stairs Climbing

#include <stdio.h>

/*
Input
An integer N represents the number of testcases.

Then , there are following N lines.

Each line contain an integer X that  represents the number of stairs in that testcase.

P.S. 1<= X <=40

Output
An integer represents the number of possible way to climb N stairs.

Note that you have to add '\n' at the end of output

Sample Input
3
3
5
7

Sample Output
3
8
21
*/

int recursive_method(int accum, int X) {
    if (accum > X) return 0;
    else if (accum == X) return 1;
    else return recursive_method(accum+1, X) + recursive_method(accum+2, X); // i.e., accum < X
}

void fn(int X) {
    int ans = recursive_method(0, X);
    printf("%d\n", ans);
}

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++) {
        int X;
        scanf(" %d", &X);
        fn(X);
    }
}