/************************************************
 * Fizz Buzz                                    *
 *                                              *
 *  -> print number 1 to 100                    *
 *  -> for multipliers of 3 print fizz          *
 *  -> for multipliers of 5 print buzz          *
 *  -> for multipliers of 3 and 5               *
 *      print fizzbuzz                          *
 ************************************************/


/* includes */
#include <stdio.h>
#include <string.h>


/* declarations */
void FizzBuzz(int, int);


/* main / wrapper function */
int main()
{
    FizzBuzz(1, 100);

    return 0;
}


/* definitions */
void FizzBuzz(int start, int end)
{
    if(end < start)
    {
        printf("Invalid values.\n");
        return;
    }

    for(int i = start; i <= end; ++i)
    {
        char output[8 + 1];

        if(i % 3 == 0 && i % 5 == 0)
        {
            strcpy(output, "FizzBuzz");
        }
        else if(i % 3 == 0)
        {
            strcpy(output, "Fizz");
        }
        else if(i % 5 == 0)
        {
            strcpy(output, "Buzz");
        }
        else
        {
            sprintf(output, "%d", i);
        }

        printf("%s\n", output);
    }
}
