#include <stdio.h>
#include <ctype.h>

char calculate(void);

int main(void)
{
    printf("%c\n", calculate());
    return 0;
}

char calculate(void)
{
    int c;
    char ans;
    char op1, op2;

    c = getchar();
    
    //ans = calculate();
    if (c=='L') {
        // printf("(");
        op1 = calculate();
        // printf("+");
        op2 = calculate();
        // printf(")");
        ans = op1;
        //printf("%.3f\n", ans);
        //calculate();
    } else if (c=='R') {
        // printf("(");
        op1 = calculate();
        // printf("-");
        op2 = calculate();
        // printf(")");
        ans = op2;
        //printf("%.3f\n", ans);
        //calculate();
    } else if (c=='=') {
        ungetc(c, stdin);
    } else {
        //ungetc(c, stdin);
        //scanf("%lf", &ans);
        ans = c;
        //printf("%.3f", ans);
    }

    return ans;
}