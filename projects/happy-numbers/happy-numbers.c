/********************************************************************************
 * Title: Happy Numbers
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Starting with any positive integer n. Replace n with the sum of
 *  the squares of its digits. Repeat until the number equals 1 or break if it
 *  it appears to loop endlessly.
 ********************************************************************************/

/* Includes */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Declarations */
unsigned int is_happy_number(unsigned int num);
unsigned int is_in_array(const unsigned int num, unsigned int* arr, const unsigned int arr_len);
unsigned int sum_digits(unsigned int num);

/* Main function */
int main() {
  printf("HAPPY NUMBERS\n\n");

  const unsigned int num = 10;
  const unsigned int res = is_happy_number(num);

  switch (res) {
    case 1:
      printf("Number %d is a happy number.\n", num);
      break;
    case 0:
      printf("Number %d is not a happy number.\n", num);
      break;
    default:
      printf("Error: Unknown error.\n");
      break;
  }

  return 0;
}

/* Declarations */
unsigned int is_happy_number(unsigned int num) {
  const unsigned int arr_len = 255;
  unsigned int* arr = (unsigned int*)malloc(sizeof(unsigned int) * arr_len);
  unsigned int counter = 0;

  /* While the number is greater than 1 and was not previously found */
  while (num > 1 && is_in_array(num, arr, arr_len) == 0) {
    if (counter > (arr_len - 1)) {
      counter = 0;
    }

    arr[counter] = num;
    num = sum_digits(num);
    counter++;
  }

  if (num == 1) {
    return 1;
  }

  return 0;
}

unsigned int is_in_array(const unsigned int num, unsigned int* arr, const unsigned int arr_len) {
  for (unsigned int i = 0; i < arr_len; i++) {
    if (arr[i] == num) {
      return 1;
    }
  }

  return 0;
}

unsigned int sum_digits(unsigned int num) {
  unsigned int sum = 0;

  while (num > 0) {
    const unsigned int digit = num % 10;
    num /= 10;
    sum += (digit * digit);
  }

  return sum;
}
