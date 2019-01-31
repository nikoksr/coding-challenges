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
char* piglatin(char* str);
unsigned int is_letter_a_vowel(const char letter);
int index_of_first_vowel(char* str);
void remove_trailing_newline(char* str);

/* main / wrapper function */
int main() {
  /* Read in some string */
  const unsigned int max_len = 255;
  char str[max_len];

  printf(
      "PIG LATIN\n\n"
      "Enter a string: ");
  fgets(str, max_len, stdin);
  remove_trailing_newline(str);

  if (strlen(str) < 1) {
    printf("Warning: No valid input.\n");
    return 1;
  }

  /* run piglatin against string */
  char* pig_latin_str = piglatin(str);
  printf("%s - %s\n", str, pig_latin_str);

  /* if string was modified, free the allocated memory */
  if (strcmp(pig_latin_str, str) != 0 && strlen(str) > 0) {
    free(pig_latin_str);
  }

  return 0;
}

/* definitions */
/* pig latin wrapper function */
char* piglatin(char* str) {
  /* look for vowel in string */
  const int vowel_index = index_of_first_vowel(str);

  /* string doesn't contain a vowel */
  if (vowel_index == -1) {
    return str;
  }

  const unsigned int len = (unsigned int)strlen(str) - 1;
  char* pig_str = (char*)malloc(len * sizeof(str[0]));

  /* first letter is a vowel */
  if (vowel_index == 0) {
    strcat(pig_str, str);
    strcat(pig_str, "ay");
  }
  /* vowel found in string */
  else {
    /* copy string including the vowel to the piglatin string */
    char vowel_string[len - vowel_index];
    sprintf(vowel_string, "%.*s", len - vowel_index + 1,
            str + vowel_index);
    strcat(pig_str, vowel_string);

    /* append the string including the consonant */
    char consonant_string[vowel_index];
    sprintf(consonant_string, "%.*s", vowel_index, str);
    strcat(pig_str, consonant_string);

    /* append the ay */
    strcat(pig_str, "ay");
  }

  return pig_str;
}

/* check if a letter / char is a vowel */
unsigned int is_letter_a_vowel(const char letter) {
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
int index_of_first_vowel(char* str) {
  const unsigned int len = strlen(str);
  unsigned int index = 0;

  while (is_letter_a_vowel(str[index]) != 1) {
    if (index + 1 == len) {
      return -1;
    }

    index++;
  }

  return index;
}

/* removes trailing newline created by fgets() */
void remove_trailing_newline(char* str) {
  str[strcspn(str, "\n")] = 0;
}
