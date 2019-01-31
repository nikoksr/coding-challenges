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
void fizzbuzz(const unsigned int start, const unsigned int end);

/* main / wrapper function */
int main() {
  const unsigned int start = 1;
  const unsigned int end = 100;

  fizzbuzz(start, end);
  return 0;
}

/* definitions */
void fizzbuzz(const unsigned int start, const unsigned int end) {
  if (end < start) {
    printf("Invalid values.\n");
    return;
  }

  for (unsigned int i = start; i <= end; ++i) {
    char output[9];
    output[0] = '\0';

    /* Check for fizz and buzz first. If both than buzz gets appended to buzz. */
    if(i % 3 == 0) {
      strcat(output, "Fizz");
    }
    if(i % 5 == 0) {
      strcat(output, "Buzz");
    }

    /* Check if number was fizz, buzz or both. If not print the number. */
    const unsigned len = (unsigned int)strlen(output);

    if(len < 1) {
      sprintf(output, "%u", i);
    }

    printf("%s\n", output);
  }
}
