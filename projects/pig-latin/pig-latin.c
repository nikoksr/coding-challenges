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
#include <string.h>
#include <stdlib.h>


/* declarations */
char *PigLatin(char *);
int IsLetterAVowel(char);
int IndexOfFirstVowel(char *);
void RemoveTrailingNewLine(char *);


/* main / wrapper function */
int main()
{
    char some_string[255];

    printf("PIG LATIN\n\n"
            "Enter a string: ");
    fgets(some_string, 255, stdin);
    
    RemoveTrailingNewLine(some_string);
    
    if(some_string == NULL ||
            strlen(some_string) < 1)
    {
        printf("Warning: No valid input.\n");
        return -1;
    }
    
    char *pig_latin_string = PigLatin(some_string);
    printf("%s - %s\n", some_string, pig_latin_string); 

    /* if string was modified, free the allocated memory */
    if(strcmp(pig_latin_string, some_string) != 0 &&
            strlen(some_string) > 0)
    {
        free(pig_latin_string);
    }

    return 0;
}


/* definitions */
/* pig latin wrapper function */
char *PigLatin(char *some_string)
{
    int vowel_index = IndexOfFirstVowel(some_string);

    /* string doesn't contain a vowel */
    if(vowel_index == -1)
    {
        return some_string;
    }
    
    int string_length = strlen(some_string) - 1;
    char *pig_string = (char *)malloc(string_length * sizeof(some_string[0]));
    
    /* first letter is a vowel */
    if(vowel_index == 0)
    {
        strcat(pig_string, some_string);
        strcat(pig_string, "ay");
    }
    /* vowel found in string */
    else
    {
        /* copy string including the vowel to the piglatin string */
        char vowel_string[string_length - vowel_index];
        sprintf(vowel_string, "%.*s", string_length - vowel_index + 1, some_string + vowel_index);
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
int IsLetterAVowel(char letter)
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int amount_vowels = strlen(vowels);
    int index = 0;
    
    while(vowels[index] != letter)
    {
        if(index + 1 == amount_vowels)
        {
            return 0;
        }

        index = index + 1;
    }

    return 1;
}


/* return the index of the first found vowel */
int IndexOfFirstVowel(char *some_string)
{
    int string_length = strlen(some_string);
    int index = 0;

    while(IsLetterAVowel(some_string[index]) != 1)
    {
        if(index + 1 == string_length)
        {
            return -1;
        }

        index = index + 1;
    }

    return index;
}


/* removes trailing newline created by fgets() */
void RemoveTrailingNewLine(char *some_string)
{
    some_string[strcspn(some_string, "\n")] = 0;
}
