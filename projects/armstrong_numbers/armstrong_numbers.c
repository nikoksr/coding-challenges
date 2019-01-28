/************************************************************
 * armstring numbers                                        *
 *                                                          *
 * -> Given is a number of three digits                     *
 * -> An armstrong number itself is equal to the cubes of   *
 *      its digits                                          *
 * -> Example:                                              *
 *      371 = 3**3 + 7**3 + 1**3                            *
 ************************************************************/

/* includes */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* declarations */
int is_armstrong_number(const int number);
void print_result(const int number, const int result);

/* main / wrapper function */
int main() {
  printf("ARMSTRONG NUMBER\n\n");

  const int number = 153;
  const int result = is_armstrong_number(number);
  print_result(number, result);

  return 0;
}

/* definitions */
/* function to check if a number is an armstrong number
 * returns 1 if true, returns 0 if false, returns -1 if error
 */
int is_armstrong_number(const int number) {
  if (number < 0) {
    return -1;
  }

  int num = number;
  int armstrong = 0;
  int number_of_digits = floor(log10(abs(num))) + 1;

  while (num > 0) {
    int digit = num % 10;
    num = num / 10;
    armstrong = armstrong + pow(digit, number_of_digits);
  }

  if (armstrong == number) {
    return 1;
  }

  return 0;
}

/* print the result */
void print_result(const int number, const int result) {
  char result_text[24];

  switch (result) {
    case 1:
      strcpy(result_text, "true");
      break;
    case 0:
      strcpy(result_text, "false");
      break;
    case -1:
      strcpy(result_text, "Error: Value smaller 0.");
      break;
    default:
      strcpy(result_text, "Unknown error.");
      break;
  }

  printf("%d -> %s\n", number, result_text);
}