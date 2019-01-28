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
char* reverse_string(char*);
void remove_trailing_newline(char*);

/* main / wrapper function */
int main() {
  char some_string[255];

  printf("Enter some string: ");
  fgets(some_string, 255, stdin);

  remove_trailing_newline(some_string);
  printf("%s%s\n", some_string, reverse_string(some_string));

  return 0;
}

/* definitions */
/* reverse a given string */
char* reverse_string(char* some_string) {
  const int string_length = strlen(some_string) - 1;
  int reverse_counter = string_length - 1;
  char* reverse_string = (char*)malloc(string_length * sizeof(char));

  for (int i = 0; i < string_length; ++i) {
    reverse_string[i] = some_string[reverse_counter];
    reverse_counter = reverse_counter - 1;
  }

  return reverse_string;
}

/* removes a trailing newline created by fgets() */
void remove_trailing_newline(char* some_string) {
  some_string[strcspn(some_string, "\n")] = 0;
}
