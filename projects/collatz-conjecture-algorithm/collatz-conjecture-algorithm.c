/************************************************
 *  Collatz Conjencture Algorithm               *
 *                                              *
 *  -> starting with a number n > 1             *
 *  -> if n is even, divide by 2                *
 *  -> if n is odd, multiply by 3               *
 *      and add 1                               *
 *  -> how many steps does it take              *
 *      until n equals 1?                       *
 ************************************************/

/* includes */
#include <stdio.h>

/* declarations */
int col_con_algo(const unsigned int number);

/* main / wrapper function */
int main() {
  printf("COLLATZ CONJENCTURE ALGORITHM\n\n");

  /* run algorithm and show results */
  const unsigned int number = 0;
  const unsigned int steps = col_con_algo(number);

  printf("It took %d steps to complete the algorithm.\n", steps);

  return 0;
}

/* collatz conjecture algorithm */
int col_con_algo(const unsigned int number) {
  /* input number has to be bigger than one */
  if (number < 2) {
    return -1;
  }

  /* the actual algorithm */
  unsigned int counter = 0;
  unsigned int number_copy = number;

  do {
    if (number_copy % 2 == 0) {
      number_copy = number_copy / 2;
    } else {
      number_copy = number_copy * 3 + 1;
    }

    counter++;
  } while (number_copy != 1);

  return counter;
}
