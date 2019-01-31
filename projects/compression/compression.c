/************************************************************
 * run-length encoding
 *
 * Run-length encoding (RLE) is a very simple form of
 * lossless data compression in which runs of data (that
 * is, sequences in which the same data value occurs in
 * many consecutive data elements) are stored as a single
 * data value and count, rather than as the original run.
 *
 * Example: aaabbcddd -> 3a2b1c3d
 ************************************************************/

/* includes */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* declarations */
struct compressed_string {
  char letters[512];
  int counts[512];
};

void run_length_encode(const char* uncompr_string,
                       struct compressed_string* compr_strg);
void run_length_decode(struct compressed_string* compr_strg,
                       char* uncompr_string);
void print_compressed_string(struct compressed_string* compr_strg);

/* main / wrapper function */
int main() {
  /* string to compress */
  const unsigned int length = 119;
  char* some_string = (char*)malloc(length);
  strcpy(some_string,
         "aaaaaaaaaaaaaabbbbbbbbbbbbbbbcccccccccccccdddddddddddeeeeeefffffggghh"
         "iijjjjkklllmmmnnnnoooppqqrrssstttuuuvvwwwxxxyyyzz");

  /* compressed string */
  struct compressed_string compr_strg;
  run_length_encode(some_string, &compr_strg);
  printf("Compressed:\t");
  print_compressed_string(&compr_strg);

  /* uncompress string */
  char* dec_string = (char*)malloc(length);
  run_length_decode(&compr_strg, dec_string);
  printf("Decompressed:\t%s\n", dec_string);

  free(some_string);

  return 0;
}

/* definitions */
/* encode string using run-length algorithm */
void run_length_encode(const char* uncompr_string,
                       struct compressed_string* compr_strg) {
  const unsigned int length = strlen(uncompr_string);
  unsigned int compr_strg_counter = 0;

  for (unsigned int i = 0; i < length; ++i) {
    char letter = uncompr_string[i];
    unsigned int letter_counter = 1;

    /* count consecutive occurence of character */
    while (uncompr_string[i] == uncompr_string[i + 1]) {
      ++letter_counter;
      ++i;
    }

    /* write character and amount of consecutive occurences in arrays */
    compr_strg->letters[compr_strg_counter] = letter;
    compr_strg->counts[compr_strg_counter] = letter_counter;
    ++compr_strg_counter;
  }

  compr_strg->letters[compr_strg_counter] = '\0';
}

/* decode run-length encoded string */
void run_length_decode(struct compressed_string* compr_strg,
                       char* uncompressed_string) {
  const unsigned int length = strlen(compr_strg->letters);
  unsigned int uncompressed_length = 0;

  for (unsigned int i = 0; i < length; ++i) {
    unsigned int count = compr_strg->counts[i];
    uncompressed_length += count;

    char letters[count + 1];
    char letter = compr_strg->letters[i];

    for (unsigned int j = 0; j < count; ++j) {
      letters[j] = letter;
    }
    letters[count] = '\0';
    strcat(uncompressed_string, letters);
  }

  uncompressed_string[uncompressed_length] = '\0';
}

/* print the compressed string struct */
void print_compressed_string(struct compressed_string* compr_strg) {
  const unsigned int length = strlen(compr_strg->letters);

  for (unsigned int i = 0; i < length; ++i) {
    printf("%c%d", compr_strg->letters[i], compr_strg->counts[i]);
  }

  printf("\n");
}
