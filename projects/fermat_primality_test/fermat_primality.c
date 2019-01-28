/************************************************************
 * fermat's primality test - fermat's little theorem        *
 *                                                          *
 * -> probabilistically checking if a number is prime       *
 * -> n = given number                                      *
 * -> r = a random number (1 <= r < n)                      *
 * -> r ^ (n - 1) % n                                       *
 * -> if n is a prime this function will return 1 for any r *
 * -> if n is not a prime this function may return 1 or 0   *
 * -> to counter the probabilistic nature of this function  *
 *      it can be run multiple times with different random  *
 *      values to lower the chance of an incorrect result   *
 ************************************************************/

/* includes */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* declarations */
int pow_remainder(int number, int random_num);
int fermat_test(const int number, const int runs);

/* main / wrapper function */
int main() {
  /* project title */
  printf("FERMAT PRIMALITY TEST\n\n");

  /* number to test */
  const int number = 7919;
  /* number of runs - more runs equal higher result precision */
  const int runs = 1;
  const int result = fermat_test(number, runs);

  printf("%d -> %d\n", number, result);

  return 0;
}

/* definitions */
/*
 * necessary function since pow of e.g. 13^11 would result in a value
 *  that is too big to store for any c type
 * remain = (random_number ^ exponent) % number
 */
int pow_remainder(int number, int random_num) {
  int exponent = number - 1;
  int remain = 1;

  while (exponent > 0) {
    /*
     * only calculate if exponent is odd, since an even exponent
     *   would result in 0 remain
     */
    if (exponent % 2 != 0) {
      remain = (remain * random_num) % number;
    }

    exponent = exponent / 2;
    random_num = (random_num * random_num) % number;
  }

  return remain;
}

/* fermat primal algorithm */
int fermat_test(const int number, const int runs) {
  if (number < 2) {
    return 0;
  }

  if (number == 2) {
    return 1;
  }

  srand(time(NULL));

  for (int i = 0; i < runs; ++i) {
    const int random_num = rand() % (number - 2) + 2;

    /* fermats little theorem */
    int ferm = pow_remainder(number, random_num);

    if (ferm != 1) {
      return 0;
    }
  }

  return 1;
}