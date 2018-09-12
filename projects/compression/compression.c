/************************************************************
 * compression                                              *
 *                                                          *
 * -> collection of algorithms to compress data             *
 * -> examples: run-length-encoding and huffman coding      *
 ************************************************************/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* declarations */
void run_length_encode(const char *dec_string, char *enc_string);
void run_length_decode(const char *enc_string, char *dec_string);

/* main / wrapper function */
int main()
{
    const int length = 15;
    char *some_string = (char *)malloc(sizeof(char) * length);
    char *compr_string = (char *)malloc(sizeof(char) * length);

    strcpy(some_string, "aaabbbbbcddddd");
    run_length_encode(some_string, compr_string);
    printf("%s -> %s\n", some_string, compr_string);

    return 0;
}

/* definitions */
/* encode string using run-length algorithm */
void run_length_encode(const char *dec_string, char *enc_string)
{
    const int length = strlen(dec_string);
    char c;
    int counter;
    int old_i;

    for (int i = 0; i < length; ++i)
    {
        c = dec_string[i];
        counter = 1;
        old_i = i;

        while (dec_string[i] == dec_string[i + 1])
        {
            ++counter;
            ++i;
        }

        char new_str[2];
        new_str[0] = c;
        new_str[1] = counter + '0';

        if (i < 1)
        {
            strcpy(enc_string, new_str);
        }

        strcat(enc_string, new_str);
        i = old_i + counter - 1;
    }
}

/* decode string using run-length algorithm */
void run_length_decode(const char *enc_string, char *dec_string)
{
    /* IN PROGRESS */

    const int length = strlen(enc_string);

    for (int i = 0; i < length; ++i)
    {
    }
}
