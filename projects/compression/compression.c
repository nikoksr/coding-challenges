/************************************************************
 * compression                                              *
 *                                                          *
 * -> collection of algorithms to compress data             *
 * -> examples: run-length-encoding and huffman coding      *
 ************************************************************/

/* includes */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* declarations */
struct compressed_string
{
    char letters[512];
    int counts[512];
};

void run_length_encode(const char *uncompr_string, struct compressed_string *compr_strg);
void run_length_decode(struct compressed_string *compr_strg, char *uncompr_string);

/* main / wrapper function */
int main()
{
    const int length = 30;
    char *some_string = (char *)malloc(sizeof(char) * length);
    strcpy(some_string, "aaabbbbbcdddddddddd");

    struct compressed_string compr_strg;

    run_length_encode(some_string, &compr_strg);
    printf("%s -> ", some_string);

    int strg_len = strlen(compr_strg.letters);

    for (int i = 0; i < strg_len; ++i)
    {
        printf("%c%d", compr_strg.letters[i], compr_strg.counts[i]);
    }

    printf("\n");

    char *dec_string = (char *)malloc(sizeof(char) * length);
    run_length_decode(&compr_strg, dec_string);
    printf("%s\n", dec_string);

    free(some_string);

    return 0;
}

/* definitions */
/* encode string using run-length algorithm */
void run_length_encode(const char *uncompr_string, struct compressed_string *compr_strg)
{
    const int length = strlen(uncompr_string);
    char letter;
    int letter_counter;
    int compr_strg_counter = 0;

    for (int i = 0; i < length; ++i)
    {
        letter = uncompr_string[i];
        letter_counter = 1;

        while (uncompr_string[i] == uncompr_string[i + 1])
        {
            ++letter_counter;
            ++i;
        }

        compr_strg->letters[compr_strg_counter] = letter;
        compr_strg->counts[compr_strg_counter] = letter_counter;
        ++compr_strg_counter;
    }
}

/* decode string using run-length algorithm */
void run_length_decode(struct compressed_string *compr_strg, char *uncompressed_string)
{
    const int length = strlen(compr_strg->letters);

    for (int i = 0; i < length; ++i)
    {
        int n = compr_strg->counts[i];
        char letter = compr_strg->letters[i];
        char letters[n + 1];

        for (int j = 0; j < n; ++j)
        {
            letters[j] = letter;
        }

        letters[n] = '\0';

        if (strlen(uncompressed_string) < 1)
        {
            strcpy(uncompressed_string, letters);
            continue;
        }

        strcat(uncompressed_string, letters);
    }
}
