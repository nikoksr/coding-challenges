/********************************************************************************
 * Title: Fermat's Primality Test - Fermat's Little Theorem
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Probabilistically checking if a number is prime. Given a natural
 *  number n and a random natural number r greater than 1 and smaller than n.
 *  Calcualte the result of r ^ (n - 1) % n. If n is prime this function will
 *  return 1 for any r. If n is not prime this function may return 1 or 0.
 *  To counter the probabilistic nature of this function it can be run multiple
 *  times with different random values to lower the chance of an incorrect result.
 ********************************************************************************/

/* Includes */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Declarations */
unsigned int pow_remainder(const unsigned int num, unsigned int random_num);
unsigned int fermat_test(const unsigned int num, const unsigned int runs);

/* Main function */
int main() {
  printf("FERMAT PRIMALITY TEST\n\n");

  const unsigned int num = 7919;
  const unsigned int runs = 1;
  const unsigned int res = fermat_test(num, runs);

  printf("%d -> %d\n", num, res);
  return 0;
}

/* Definitions */
/*
 * Necessary function since pow of e.g. 13^11 would result in a value that is
 * too big to store for any c-type.
 */
unsigned int pow_remainder(const unsigned int num, unsigned int random_num) {
  unsigned int exponent = num - 1;
  unsigned int remain = 1;

  while (exponent > 0) {
    /*
     * Only calculate if exponent is odd, since an even exponent
     * would result in 0 remaining.
     */
    if (exponent % 2 != 0) {
      remain = (remain * random_num) % num;
    }

    random_num = (random_num * random_num) % num;
    exponent /= 2;
  }

  return remain;
}

unsigned int fermat_test(const unsigned int num, const unsigned int runs) {
  if (num < 2) {
    return 0;
  }

  if (num == 2) {
    return 1;
  }

  srand(time(NULL));

  for (unsigned int i = 0; i < runs; ++i) {
    const unsigned int random_num = rand() % (num - 2) + 2;
    const unsigned int ferm = pow_remainder(num, random_num);

    if (ferm != 1) {
      return 0;
    }
  }

  return 1;
}
