#include<stdio.h>
#include<string.h>

/*
Input
There are multiple lines in each testcase. Each line contains a string si that HT wrote on the paper.

The input file is ended by 'EOF'.

It is guaranteed that :

At most 10 lines in each testcase.
testcase #1 ~ #4 : 1 ≤ | s | ≤ 200
testcase #5 Bonus: 1 ≤ | s | ≤ 2000
*/

int isPalindrome(char *str, int l, int r) {
    if ( l == r ) return 1;
    else {
        /*
        int even_or_odd;
        if ( ( r - l + 1 ) % 2 == 0 ) {
            // even
            even_or_odd = 0;
        }
        else {
            // odd
            even_or_odd = 1;
        }*/

        int loops = (r - l + 1) / 2;
        //printf("DEBUG: loops = %d\n", loops);

        for (int i=0; i < loops; i++) {
            if (str[l+i] != str[r-i]) return 0;
        }
    }

    return 1;
}

void run_testcase(char *str) {
    unsigned long len = strlen(str);
    //printf("DEBUG: len = %lu\n", len);

    int number_of_exquisite_substrings = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if ( isPalindrome(str, i, j) ) {
                number_of_exquisite_substrings++;
                //printf("DEBUG: number of exquisite substrings ++\n");
            }
        }
    }

    printf("%d\n", number_of_exquisite_substrings);
}

void load_testdata(char *str) {
    while (scanf("%s", str) != EOF) {
        //printf("DEBUG: str = %s\n", str);
        //printf("DEBUG: len(str) = %lu\n", strlen(str));
        run_testcase(str);
    }
}

int main(){
    char str[2001];
    load_testdata(str);

    return 0;  
}