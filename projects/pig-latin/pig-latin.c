/************************************************************
 * pig latin                                                *
 *                                                          *
 * -> take an english word or sentence                      *
 * -> transpose the initial consonant sound to the end      *
 *      of the word                                         *
 * -> and affix an 'ay'                                     *
 * -> for words beginning with vowels only an 'ay'          *
 *      gets appended                                       *
 * -> Examples: 'banana' - 'ananabay'                       *
 *              'glove'  - 'oveglay'                        *
 *              'egg'    - 'eggay'                          *
 ************************************************************/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* declarations */
char* piglatin(char* some_string);
int is_letter_a_vowel(const char letter);
int index_of_first_vowel(char* some_string);
void remove_trailing_newline(char* some_string);

/* main / wrapper function */
int main() {
  /* Read in some string */
  char some_string[255];

  printf(
      "PIG LATIN\n\n"
      "Enter a string: ");
  fgets(some_string, 255, stdin);
  remove_trailing_newline(some_string);

  if (strlen(some_string) < 1) {
    printf("Warning: No valid input.\n");
    return 1;
  }

  /* run piglatin against string */
  char* pig_latin_string = piglatin(some_string);
  printf("%s - %s\n", some_string, pig_latin_string);

  /* if string was modified, free the allocated memory */
  if (strcmp(pig_latin_string, some_string) != 0 && strlen(some_string) > 0) {
    free(pig_latin_string);
  }

  return 0;
}

/* definitions */
/* pig latin wrapper function */
char* piglatin(char* some_string) {
  /* look for vowel in string */
  const int vowel_index = index_of_first_vowel(some_string);

  /* string doesn't contain a vowel */
  if (vowel_index == -1) {
    return some_string;
  }

  const unsigned int string_length = (unsigned int)strlen(some_string) - 1;
  char* pig_string = (char*)malloc(string_length * sizeof(some_string[0]));

  /* first letter is a vowel */
  if (vowel_index == 0) {
    strcat(pig_string, some_string);
    strcat(pig_string, "ay");
  }
  /* vowel found in string */
  else {
    /* copy string including the vowel to the piglatin string */
    char vowel_string[string_length - vowel_index];
    sprintf(vowel_string, "%.*s", string_length - vowel_index + 1,
            some_string + vowel_index);
    strcat(pig_string, vowel_string);

    /* append the string including the consonant */
    char consonant_string[vowel_index];
    sprintf(consonant_string, "%.*s", vowel_index, some_string);
    strcat(pig_string, consonant_string);

    /* append the ay */
    strcat(pig_string, "ay");
  }

  return pig_string;
}

/* check if a letter / char is a vowel */
int is_letter_a_vowel(const char letter) {
  const char vowels[] = {'a', 'e', 'i', 'o', 'u'};
  const unsigned int amount_vowels = (unsigned int)strlen(vowels);
  unsigned int index = 0;

  while (vowels[index] != letter) {
    if (index + 1 == amount_vowels) {
      return 0;
    }

    index = index + 1;
  }

  return 1;
}

/* return the index of the first found vowel */
int index_of_first_vowel(char* some_string) {
  const unsigned int string_length = strlen(some_string);
  unsigned int index = 0;

  while (is_letter_a_vowel(some_string[index]) != 1) {
    if (index + 1 == string_length) {
      return -1;
    }

    index++;
  }

  return index;
}

/* removes trailing newline created by fgets() */
void remove_trailing_newline(char* some_string) {
  some_string[strcspn(some_string, "\n")] = 0;
}
