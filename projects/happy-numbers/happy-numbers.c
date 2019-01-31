/************************************************
 * Happy Numbers                                *
 *                                              *
 *  -> starting with any positive integer       *
 *  -> replace the number with the sum          *
 *      of the squares of its digits            *
 *  -> repeat until the number equals 1         *
 *      or break if it loops endlessly          *
 *                                              *
 ************************************************/

/* includes */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* declarations */
unsigned int is_happy_number(unsigned int num);
unsigned int is_in_array(const unsigned int num, unsigned int* arr, const unsigned int arr_len);
unsigned int sum_digits(unsigned int num);

/* main / wrapper function */
int main() {
  printf("HAPPY NUMBERS\n\n");

  /* calculate and evaluate */
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

/* check if a given number is a happy number */
unsigned int is_happy_number(unsigned int num) {
  const unsigned int arr_len = 255;
  unsigned int* arr = (unsigned int*)malloc(sizeof(unsigned int) * arr_len);
  unsigned int counter = 0;

  /* while the number is > 1 and was not found previously (loop) - keep
   * calculating */
  while (num > 1 && is_in_array(num, arr, arr_len) == 0) {
    /* overwrite array to prevent overflow */
    if (counter > (arr_len - 1)) {
      counter = 0;
    }

    arr[counter] = num;
    num = sum_digits(num);
    counter++;
  }

  /* is a happy number */
  if (num == 1) {
    return 1;
  }

  /* is not a happy number */
  return 0;
}

/* checks an array of numbers if a given number is already in it */
unsigned int is_in_array(const unsigned int num, unsigned int* arr, const unsigned int arr_len) {
  for (unsigned int i = 0; i < arr_len; i++) {
    if (arr[i] == num) {
      /* number found in array */
      return 1;
    }
  }

  /* number not found in array */
  return 0;
}

/* return sum of digits of a given integer */
unsigned int sum_digits(unsigned int num) {
  unsigned int sum = 0;

  while (num > 0) {
    const unsigned int digit = num % 10;
    num /= 10;
    sum += (digit * digit);
  }

  return sum;
}
