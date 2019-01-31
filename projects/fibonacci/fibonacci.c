#include <limits.h>
#include <stdio.h>

/* fibonacci calculation */
void fibonacci_factor_limiter(const unsigned int factor);
void fibonacci_number_limiter(const unsigned int num);

/* wrapper function */
int main() {
  /* maximum number */
  const int number = 100;
  fibonacci_number_limiter(number);

  /* maximum factor */
  const int factor = 10;
  fibonacci_factor_limiter(factor);

  return 0;
}

/* fibonacci calculations */
/* maximum factor */
void fibonacci_factor_limiter(const unsigned int factor) {
  unsigned int a = 0, b = 1, c = 0, counter = 1;
  printf("%6d : %6d\n", counter, a);

  while (counter < factor && (a + b) < INT_MAX) {
    c = a + b;
    b = a;
    a = c;
    counter += 1;
    printf("%6d : %6d\n", counter, c);
  }
}

/* maximum number */
void fibonacci_number_limiter(const unsigned int num) {
  int a = 0, b = 1, c = 0, counter = 1;
  printf("%6d : %6d\n", counter, a);

  while ((a + b) < num && (a + b) < INT_MAX) {
    c = a + b;
    b = a;
    a = c;
    counter += 1;
    printf("%6d : %6d\n", counter, c);
  }
}
