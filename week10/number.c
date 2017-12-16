#include <stdio.h>
/*
 fixed point
 y*y = x
 y = x/y
 y-x/y ~ 0
 0.5*(y+x/y) is in between
*/
double abs0(double x)
{
    return (x>0) ? x : -x;
}
double sqrt0(double x, double guess)
{
    printf("%.12f %.12f\n", x, guess);
    if (abs0(guess*guess - x) < 0.00000001) return guess;
    else {
        return sqrt0(x, 0.5*(guess+(x/guess)) );
    }
}

int main(void)
{
    printf("%.12f\n", sqrt0(2, 1));
    return 0;
}