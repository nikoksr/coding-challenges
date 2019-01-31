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
int col_con_algo(const unsigned int num);

/* main / wrapper function */
int main() {
  printf("COLLATZ CONJENCTURE ALGORITHM\n\n");

  /* run algorithm and show results */
  const unsigned int num = 0;
  const unsigned int steps = col_con_algo(num);

  printf("It took %d steps to complete the algorithm.\n", steps);

  return 0;
}

/* collatz conjecture algorithm */
int col_con_algo(const unsigned int num) {
  /* input number has to be bigger than one */
  if (num < 2) {
    return -1;
  }

  /* the actual algorithm */
  unsigned int counter = 0;
  unsigned int num_copy = num;

  do {
    if (num_copy % 2 == 0) {
      num_copy = num_copy / 2;
    } else {
      num_copy = num_copy * 3 + 1;
    }

    counter++;
  } while (num_copy != 1);

  return counter;
}
