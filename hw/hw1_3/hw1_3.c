#include <stdio.h>
#include <stdlib.h>

int main()
{
  //input is string
  char input[7];
  scanf("%s", &input);
  //printf("%s\n", input);
  //convert number1 to double
  double number1;
  number1 = atof(input);
  //printf("%f\n", number1);

  //reverse number
  int temp = input[0];
  input[0] = input[2];
  input[2] = temp;

  temp = input[4];
  input[4] = input[6];
  input[6] = temp;

  //printf("%s\n", input);

  //convert number2 to double
  double number2;
  number2 = atof(input);
  //printf("%f\n", number2);

  double output;
  output = number1 + number2;
  printf("%.3lf", output);

  return 0;
}