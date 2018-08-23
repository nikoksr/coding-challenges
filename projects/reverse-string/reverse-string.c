/************************************************
 * Reverse String                               *
 *                                              *
 *  -> reverse and return a given string        *
 ************************************************/


/* includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* declarations */
char *ReverseString(char *);
void RemoveTrailingNewLine(char *);

/* main / wrapper function */
int main()
{
    char some_string[255];

    printf("Enter some string: ");
    fgets(some_string, 255, stdin);

    RemoveTrailingNewLine(some_string);
    printf("%s%s\n", some_string, ReverseString(some_string));

    return 0;
}


/* definitions */
/* reverse a given string */
char *ReverseString(char *some_string)
{
    int string_length = strlen(some_string) - 1;
    int reverse_counter = string_length - 1;
    char *reverse_string = (char *) malloc(string_length * sizeof(char));

    for(int i = 0; i < string_length; ++i)
    {
        reverse_string[i] = some_string[reverse_counter];
        reverse_counter = reverse_counter - 1;
    }

    return reverse_string;
}


/* removes a trailing newline created by fgets() */
void RemoveTrailingNewLine(char *some_string)
{
    some_string[strcspn(some_string, "\n")] = 0;
}
