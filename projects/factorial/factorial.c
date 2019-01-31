/************************************************
 * factorial                                    *
 *                                              *
 *  -> calculate the factorial of a given       *
 *      number                                  *
 *  -> Example: 5! = 5 * 4 * 3 * 2 * 1 = 120    *
 *  -> 0! = 1 according to convention of        *
 *      an empty product                        *
 ************************************************/

/* includes */
#include <stdio.h>

/* declarations */
unsigned int factorial_non_recursive(unsigned int num);
unsigned int factorial_recursive(unsigned int num);
unsigned int factorial_pre_checking(const unsigned int);

/* main / wrapper function */
int main() {
  printf("FACTORIAL\n\n");

  const unsigned int num = 10;

  printf(
      "\nFactorial(recursive): %d\n"
      "Factorial(non-recursive): %d\n",
      factorial_recursive(num), factorial_non_recursive(num));

  return 0;
}

/* definitions */
/* calculating the factorial of a number using a
 * non-recursive algorithm
 */
unsigned int factorial_non_recursive(unsigned int num) {
  const unsigned int res = factorial_pre_checking(num);

  if (res != num) {
    return res;
  }

  unsigned int product = 1;

  while (num > 0) {
    product *= num;
    num--;
  }

  return product;
}

/* calculating the factorial of a number using a
 * recursive algorithm
 */
unsigned int factorial_recursive(unsigned int num) {
  const unsigned int res = factorial_pre_checking(num);

  if (res != num) {
    return res;
  }

  return (num * factorial_recursive(num - 1));
}

/* pre check the number to be factorialized
 * -> if the number is smaller than 0, return -1 as
 *      a sign of an error
 * -> if the number is 0, return 1 - according to the convention of
 *      an empty product
 */
unsigned int factorial_pre_checking(const unsigned int num) {
  if (num < 0) {
    return -1;
  }

  if (num == 0) {
    return 1;
  }

  return num;
}
