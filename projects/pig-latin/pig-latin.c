/********************************************************************************
 * Title: Pig Latin
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Take an english word and transpose the initial consonant sound
 *  to the end of the word and affix 'ay'. For words beginning with vowels, only
 *  'ay' gets appended to the word.
 * Example: 'banana' - 'ananabay'
 *          'glove'  - 'oveglay'
 *          'egg'    - 'eggay'
 *******************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declarations */
char* piglatin(char* str);
unsigned int is_letter_a_vowel(const char letter);
int index_of_first_vowel(char* str);
void remove_trailing_newline(char* str);

/* Main function */
int main() {
  printf("PIG LATIN\n\n");

  char str[] = "banana";

  /* Run piglatin against string */
  char* pig_latin_str = piglatin(str);

  printf("%s - %s\n", str, pig_latin_str);
  free(pig_latin_str);
  return 0;
}

/* Definitions */
char* piglatin(char* str) {
  /* Look for vowel in string */
  const int vowel_index = index_of_first_vowel(str);

  /* String doesn't contain a vowel */
  if (vowel_index == -1) {
    return str;
  }

  const unsigned int len = (unsigned int)strlen(str) - 1;
  char* pig_str = (char*)malloc(len * sizeof(str[0]));

  /* First letter is a vowel */
  if (vowel_index == 0) {
    strcat(pig_str, str);
    strcat(pig_str, "ay");
  }
  /* Vowel found in string */
  else {
    /* Copy string including the vowel to the piglatin string */
    char vowel_string[len - vowel_index];
    sprintf(vowel_string, "%.*s", len - vowel_index + 1,
            str + vowel_index);
    strcat(pig_str, vowel_string);

    /* Append the string including the consonant */
    char consonant_string[vowel_index];
    sprintf(consonant_string, "%.*s", vowel_index, str);
    strcat(pig_str, consonant_string);

    /* Append the ay */
    strcat(pig_str, "ay");
  }

  return pig_str;
}

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

void remove_trailing_newline(char* str) {
  str[strcspn(str, "\n")] = 0;
}
