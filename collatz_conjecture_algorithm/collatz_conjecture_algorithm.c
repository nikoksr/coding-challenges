/************************************************
 *  Collatz Conjencture Algorithm               *
 *                                              *
 *  -> starting with a number n > 1             *
 *  -> if n is even, divide by 2                *
 *  -> if n is odd, multiply by 3               *
 *      and add 1                               *
 *  -> how many steps does it take              *
 *      until n equals 1                        *
 ************************************************/


/* includes */
#include <stdio.h>


/* declarations */
int ColConAlgo(unsigned int number);


/* main / wrapper function */
int main()
{   
    /* user input */
    int number = 0;
    printf("COLLATZ CONJENCTURE ALGORITHM\n\n");
    printf("Please enter a number(n > 1): ");
    scanf("%d", &number);
    printf("\n");

    /* run algorithm and show results */
    int steps = ColConAlgo(number);
    printf("It took %d steps to complete the algorithm.\n", steps);

    return 0;
}


/* collatz conjecture algorithm */
int ColConAlgo(unsigned int number)
{
    /* input number has to be bigger than one */
    if(number < 2)
    {
        return -1;
    }

    /* the actual algorithm */
    int counter = 0;
    unsigned int number_copy = number;
    
    do
    {
        if(number_copy % 2 == 0)
        {
            number_copy = number_copy / 2;
        }
        else
        {
            number_copy = number_copy * 3 + 1;
        }
        
        counter = counter + 1;
    }
    while(number_copy != 1);

    return counter;
}
