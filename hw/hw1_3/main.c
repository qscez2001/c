/* Hello World program */

#include<stdio.h>
#include<stdlib.h>

int main()
{
    char input_six_digits [8];
    printf ("Enter a six-ditgit number (e.g., 123.456): ");
    fgets (input_six_digits, 8, stdin);

    char reversed_six_digits [8];
    for (int i=0; i<3;i++) {
        reversed_six_digits[2-i] = input_six_digits[i];
    }
    reversed_six_digits[3] = '.';
    for (int i=4; i<7;i++) {
        reversed_six_digits[7-i+3] = input_six_digits[i];
    }
    printf("%s + %s = ?\n", input_six_digits, reversed_six_digits);

    char digit [2];
    digit[0] = input_six_digits[0];
    printf("the firt digit is %d\n", atoi(digit));
}
