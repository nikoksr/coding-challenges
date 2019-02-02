/********************************************************************************
 * Title: Reverse String
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Reverse a given string.
 ********************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declarations */
void reverse_string(char* str);
void remove_trailing_newline(char* str);

/* Main function */
int main() {
  const unsigned int max_len = 255;
  char str[max_len] = "Hello World!";

  /* Keep copy of original string */
  char original_str[max_len];

  strcpy(original_str, str);

  /* Revert string */
  reverse_string(str);
  printf("%s -> %s\n", original_str, str);
  return 0;
}

/* Definitions */
void reverse_string(char* str) {
  const unsigned int len = strlen(str);
  unsigned int reverse_counter = len - 1;
  char reverse_str[len];

  for (unsigned int i = 0; i < len; ++i) {
    reverse_str[i] = str[reverse_counter];
    reverse_counter--;
  }

  reverse_str[len] = '\0';
  strcpy(str, reverse_str);
}

void remove_trailing_newline(char* str) {
  str[strcspn(str, "\n")] = 0;
}
