#include<stdio.h>
#include<string.h>

/*
Input
There are multiple lines in each testcase. Each line contains a string si that HT writes on the paper.

The input file is ended by 'EOF'.

It is guaranteed that :

At most 10 lines in each testcase.
testcase #1 : Sample Input
testcase #2~4 : 1 ≤ | si | ≤ 10, at most one "lucky number" appears in each line
testcase #5~8 : 1 ≤ | si | ≤ 100
testcase #9 : 1 ≤ | si | ≤ 5000
testcase #10 : 1 ≤ | si | ≤ 200000
If you can't pass testcase #9 & #10 immediately, try to solve another two problems first. 

Output
For each string si, please output a line contains one integer representing the number of "lucky substrings" in si.
*/

void run_testcase(char *str, int *idx9) {
    //printf("DEBUG: str = %s\n", str);
    int num_lucky_substring = 0;

    unsigned long len = strlen(str);
    //printf("DEBUG: len(str) = %lu\n", len);

    // prepare an array to store all indeices of '9' character
    int num_of_9s = 0;
    for (int i=0; i<len; i++) {
        char c = str[i];
        //printf("DEBUG: c = %c\n", c);

        if (c == '9') {
            idx9[num_of_9s] = i;
            num_of_9s++;
        }
    }

    // list all substrings
    //
    // for a string of length N
    // it has 1 substring of length N-0
    // it has 2 substring of length N-1
    // it has 3 substring of length N-2
    // ...
    // it has N substring of length 1
    //
    //
    // the first and last characters of the 1st substring of length N are
    // 0, (N-1)
    //
    // the first and last characters of the 1st substring of length N-1 are
    // 0, (N-1)-1
    // the first and last characters of the 2nd substring of length N-1 are
    // 1, (N-1)-0
    //
    // the first and last characters of the 1st substring of length N-2 are
    // 0, (N-1)-2
    // the first and last characters of the 2nd substring of length N-2 are
    // 1, (N-1)-1
    // the first and last characters of the 3rd substring of length N-2 are
    // 2, (N-1)-0
    int N = len;
    for (int i=0; i<N; i++) {
        int first;
        int eol;

        // shift first and last
        //printf("DEBUG: substring of length %D\n", i+1);
        for (int j=0; j<N-i; j++) {
            first = j;
            eol = j+(i+1);

            /*printf("DEBUG: substring = ");
            for (int k=first; k<eol; k++) {
                printf("%c", str[k]);
            }
            printf("\n");*/

            // given a substring and a sorted array of [0, 5, 9] which means s[0] == s[5] == s[9] == '9'
            // determine if the given substring has '9' character
            // check first <= 0 < eol, if true return true else check next
            // check first <= 5 < eol, if true return true else check next
            // check first <= 9 < eol, if true return true else check next
            // return false
            if (num_of_9s > 0 && idx9[0] < eol && idx9[num_of_9s-1] >= first) {
                for (int k=0; k<num_of_9s; k++) {
                    if (first <= idx9[k] && idx9[k] < eol) {
                        num_lucky_substring++;
                        break;
                    }
                }
            }
        }
    }
 
    printf("%d\n", num_lucky_substring);
}

void load_testdata(char *str, int *idx9) {
    while (scanf("%s", str) != EOF) {
        //printf("DEBUG: str = %s\n", str);
        run_testcase(str, idx9);
    }
}

int main(){
    char str[200001];
    int idx9[200001];
    load_testdata(str, idx9);
    return 0;  
}