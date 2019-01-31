/************************************************
 * Reverse String                               *
 *                                              *
 *  -> reverse and return a given string        *
 ************************************************/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* declarations */
void reverse_string(char* str);
void remove_trailing_newline(char* str);

/* main / wrapper function */
int main() {
  /* read in a string */
  const unsigned int max_len = 255;
  char str[max_len];
  printf("Enter some string: ");
  fgets(str, max_len, stdin);
  remove_trailing_newline(str);

  /* keep copy of unreverted string */
  char old_str[max_len];
  strcpy(old_str, str);

  /* revert string */
  reverse_string(str);
  printf("%s -> %s\n", old_str, str);
  return 0;
}

/* definitions */
/* reverse a given string */
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

/* removes a trailing newline created by fgets() */
void remove_trailing_newline(char* str) {
  str[strcspn(str, "\n")] = 0;
}
