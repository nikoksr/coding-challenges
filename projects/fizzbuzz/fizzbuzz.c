/************************************************
 * Fizz Buzz                                    *
 *                                              *
 *  -> print number 1 to 100                    *
 *  -> for multipliers of 3 print fizz          *
 *  -> for multipliers of 5 print buzz          *
 *  -> for multipliers of 3 and 5               *
 *      print fizzbuzz                          *
 ************************************************/

/* includes */
#include <stdio.h>
#include <string.h>

/* declarations */
void fizzbuzz(int, int);

/* main / wrapper function */
int main() {
  const int start = 1;
  const int end = 100;

  fizzbuzz(start, end);

  return 0;
}

/* definitions */
void fizzbuzz(const int start, const int end) {
  if (end < start) {
    printf("Invalid values.\n");
    return;
  }

  for (int i = start; i <= end; ++i) {
    char output[8 + 1];

    if (i % 3 == 0 && i % 5 == 0) {
      strcpy(output, "FizzBuzz");
    } else if (i % 3 == 0) {
      strcpy(output, "Fizz");
    } else if (i % 5 == 0) {
      strcpy(output, "Buzz");
    } else {
      sprintf(output, "%d", i);
    }

    printf("%s\n", output);
  }
}
