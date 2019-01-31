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
int is_armstrong_number(const unsigned int num);
void print_result(const unsigned int num, const unsigned int result);

/* main / wrapper function */
int main() {
  printf("ARMSTRONG NUMBER\n\n");

  const unsigned int num = 153;
  const unsigned int result = is_armstrong_number(num);
  print_result(num, result);

  return 0;
}

/* definitions */
/* function to check if a number is an armstrong number
 * returns 1 if true, returns 0 if false, returns -1 if error
 */
int is_armstrong_number(const unsigned int num) {
  if (num < 0) {
    return -1;
  }

  unsigned int n = num;
  unsigned int armstrong = 0;
  const unsigned int number_of_digits = floor(log10(num)) + 1;

  while (num > 0) {
    unsigned int digit = num % 10;
    n /= 10;
    armstrong += pow(digit, number_of_digits);
  }

  if (armstrong == n) {
    return 1;
  }

  return 0;
}

/* print the result */
void print_result(const unsigned int num, const unsigned int result) {
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

  printf("%d -> %s\n", num, result_text);
}
