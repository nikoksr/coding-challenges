/********************************************************************************
 * Title: Bruteforce Prime
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Use bruteforce to check if a number n is prime. A number is prime
 *  if it's a natural number, it's greater than 1 and it's only divisble by 1 and
 *  itself. At fist the bruteforce method checks if the number is odd. If it is,
 *  the algorithm simply tries to divide the given number by every single odd
 *  number smaller than the half of given number.
 *******************************************************************************/

/* Includes */
#include <stdio.h>

/* Declarations */
int is_prime(const unsigned int num);
void find_primes(const unsigned int start, const unsigned int end);

/* Main function */
int main() {
  printf("BRUTEFORCE PRIME\n\n");

  const unsigned int start = 2;
  const unsigned int end = 100;

  find_primes(start, end);
  return 0;
}

int is_prime(const unsigned int num) {
  // Check if too small
  if (num < 2) {
    return 0;
  }

  // Check if is 2
  if (num == 2) {
    return 1;
  }

  // Check if even
  if (num % 2 == 0) {
    return 0;
  }

  // Bruteforce
  for (unsigned int i = 3; i < num / 2; i += 2) {
    if (num % i == 0) {
      return 0;
    }
  }

  return 1;
}

void find_primes(const unsigned int start, const unsigned int end) {
  if (end < start) {
    printf("Start has to be smaller than end.\n");
    return;
  }

  for (unsigned int i = start; i <= end; ++i) {
    if (is_prime(i) == 1) {
      printf("%i\n", i);
    }
  }
}
