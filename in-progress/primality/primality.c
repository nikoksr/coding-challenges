/************************************************************
 * primality                                                *
 *                                                          *
 * -> checking if a number is prime by dividing it by the   *
 *      numbers up to its square root                       *
 ************************************************************/

/* includes */
#include <math.h>
#include <stdio.h>

/* declarations */
int primality(int number);

/* main / wrapper function */
int main()
{
        printf("PRIMALITY\n\n");

        const int number = 7;

        int root = primality(number);
        printf("%d\n", 'r');

        return 0;
}

/* definitions */
/*  */
int primality(const int number)
{
        double root = (int)(sqrt((double)number));

        for (int i = 2; i < (root + 1); ++i)
        {
                if (number % i == 0)
                {
                        return 0;
                }
        }

        return 1;
}