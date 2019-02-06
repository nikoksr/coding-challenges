/********************************************************************************
 * Title: Run-Length Encoding
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Run-length encoding (RLE) is a very simple form of lossless data
 *  compression in which runs of data (that is, sequences in which the same data
 *  value occurs in many consecutive data elements) are stored as a single data
 *  value and count, rather than as the original run.
 * Example: aaabbcddd -> 3a2b1c3d
 *******************************************************************************/

/* Includes */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declarations */
struct compressed_str {
    char letters[512];
    int counts[512];
};

void run_length_encode(const char* uncompressed_str, struct compressed_str* compressed_str);
void run_length_decode(struct compressed_str* compressed_str, char* uncompressed_str);
void print_compressed_string(struct compressed_str* compressed_str);

/* Main function */
int main() {
    const unsigned int len = 119;
    char* str = (char*)malloc(len);

    strcpy(str, "aaaaaaaaaaaaaabbbbbbbbbbbbbbbcccccccccccccdddddddddddeeeeeefffffggghh"
           "iijjjjkklllmmmnnnnoooppqqrrssstttuuuvvwwwxxxyyyzz");

    /* Compress string */
    struct compressed_str compressed_str;

    run_length_encode(str, &compressed_str);
    printf("Compressed:\t");
    print_compressed_string(&compressed_str);

    /* Uncompress string */
    char* decompress_str = (char*)malloc(len);

    run_length_decode(&compressed_str, decompress_str);
    printf("Decompressed:\t%s\n", decompress_str);
    free(str);
    return 0;
}

/* Definitions */
void run_length_encode(const char* uncompressed_str, struct compressed_str* compressed_str) {
    const unsigned int len = strlen(uncompressed_str);
    unsigned int compressed_str_counter = 0;

    for (unsigned int i = 0; i < len; ++i) {
        char letter = uncompressed_str[i];
        unsigned int letter_counter = 1;

        /* Count consecutive occurence of character */
        while (uncompressed_str[i] == uncompressed_str[i + 1]) {
            ++letter_counter;
            ++i;
        }

        /* Write character and amount of consecutive occurences in arrays */
        compressed_str->letters[compressed_str_counter] = letter;
        compressed_str->counts[compressed_str_counter] = letter_counter;
        ++compressed_str_counter;
    }

    compressed_str->letters[compressed_str_counter] = '\0';
}

void run_length_decode(struct compressed_str* compressed_str, char* uncompressed_str) {
    const unsigned int len = strlen(compressed_str->letters);
    unsigned int uncompressed_len = 0;

    for (unsigned int i = 0; i < len; ++i) {
        unsigned int count = compressed_str->counts[i];
        char letters[count + 1];
        char letter = compressed_str->letters[i];

        for (unsigned int j = 0; j < count; ++j) {
            letters[j] = letter;
        }

        letters[count] = '\0';
        strcat(uncompressed_str, letters);
        uncompressed_len += count;
    }

    uncompressed_str[uncompressed_len] = '\0';
}

void print_compressed_string(struct compressed_str* compressed_str) {
    const unsigned int len = strlen(compressed_str->letters);

    for (unsigned int i = 0; i < len; ++i) {
        printf("%c%d", compressed_str->letters[i], compressed_str->counts[i]);
    }

    printf("\n");
}
