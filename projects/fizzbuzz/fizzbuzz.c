/********************************************************************************
 * Title: Fizz Buzz
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: For a natural number n. If n is a multiplier of 3 print fizz,
 *  if n is a multiplier of 5 print buzz, if n is a multiplier of 3 and 5 print
 *  fizzbuzz. If none of the above statements applies, print n. Increase n by one
 *  and repeat the previous steps.
 ************************************************/

/* Includes */
#include <stdio.h>
#include <string.h>

/* Declarations */
void fizzbuzz(const unsigned int start, const unsigned int end);

/* Main function */
int main() {
  const unsigned int start = 1;
  const unsigned int end = 100;

  fizzbuzz(start, end);
  return 0;
}

/* Definitions */
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
