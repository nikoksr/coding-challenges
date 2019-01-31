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
unsigned int pow_remainder(const unsigned int num, unsigned int random_num);
unsigned int fermat_test(const unsigned int num, const unsigned int runs);

/* main / wrapper function */
int main() {
  /* project title */
  printf("FERMAT PRIMALITY TEST\n\n");

  /* number to test */
  const unsigned int num = 7919;
  /* number of runs - more runs equal higher precision */
  const unsigned int runs = 1;
  const unsigned int res = fermat_test(num, runs);

  printf("%d -> %d\n", num, res);

  return 0;
}

/* definitions */
/*
 * necessary function since pow of e.g. 13^11 would result in a value
 *  that is too big to store for any c type
 * remain = (random_number ^ exponent) % number
 */
unsigned int pow_remainder(const unsigned int num, unsigned int random_num) {
  unsigned int exponent = num - 1;
  unsigned int remain = 1;

  while (exponent > 0) {
    /*
     * only calculate if exponent is odd, since an even exponent
     *   would result in 0 remain
     */
    if (exponent % 2 != 0) {
      remain = (remain * random_num) % num;
    }

    exponent /= 2;
    random_num = (random_num * random_num) % num;
  }

  return remain;
}

/* fermat primal algorithm */
unsigned int fermat_test(const unsigned int num, const unsigned int runs) {
  if (num < 2) {
    return 0;
  }

  if (num == 2) {
    return 1;
  }

  srand(time(NULL));

  /* fermats little theorem */
  for (unsigned int i = 0; i < runs; ++i) {
    const int random_num = rand() % (num - 2) + 2;
    const unsigned int ferm = pow_remainder(num, random_num);

    if (ferm != 1) {
      return 0;
    }
  }

  return 1;
}
