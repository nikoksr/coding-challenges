/************************************************
 * Happy Numbers                                *
 *                                              *
 *  -> starting with any positive integer       *
 *  -> replace the number with the sum          *
 *      of the squares of its digits            *
 *  -> repeat until the number equals 1         *
 *      or it loops endlessly                   *
 *                                              *
 ************************************************/


/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* declarations */
int IsHappyNumber(unsigned int number);
int IsInArray(unsigned int number, unsigned int* number_array, int array_length);
unsigned int SumDigits(unsigned int number);


/* main / wrapper function */
int main()
{
    /* user input */
    unsigned int number = 1;

    printf("HAPPY NUMBERS\n\n");
    printf("Please enter a number(n > 0): ");
    scanf("%d", &number);
    printf("\n");

    /* calculate and evaluate */
    int result = IsHappyNumber(number);

    switch (result) 
    {
        case 1:
            printf("Number %d is a happy number.\n", number);
            break;

        case 0:
            printf("Number %d is not a happy number.\n", number);
            break;

        default:
            printf("Error: Unknown error.\n");
            break;
    }
  
    return 0;
}


/* check if a given number is a happy number */
int IsHappyNumber(unsigned int number)
{ 
    int array_length = 255;
    unsigned int* number_array = (unsigned int*) malloc(array_length * sizeof(unsigned int*));
    int counter = 0;
  
    /* while the number is > 1 and was not found previously (loop) - keep calculating */
    while(number > 1 && IsInArray(number, number_array, array_length) == 0)
    {
        /* overwrite array to prevent overflow */
        if(counter > 254)
        {
            counter = 0;
        }

        number_array[counter] = number;
        number = SumDigits(number);
        counter = counter + 1;
    }
  
      /* is a happy number */
      if(number == 1)
      {
          return 1;
      }
      
      /* is not a happy number */
      return 0;
}


/* checks an array of numbers if a given number is already in it */
int IsInArray(unsigned int number, unsigned int* number_array, int array_length)
{
    for(int i = 0; i < array_length; i++)
    {
        if(number_array[i] == number)
        {
            /* number found in array */
            return 1;
        }
    }
  
    /* number not found in array */
    return 0;
}


/* return sum of digits of a given integer */
unsigned int SumDigits(unsigned int number) 
{
    unsigned int sum = 0;

    while(number > 0)
    {
        unsigned int digit = number % 10;
        number = number / 10;
        sum = sum + (digit * digit);
    }

    return sum;
}
