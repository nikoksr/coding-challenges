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
int is_happy_number(int);
int is_in_array(int, int *, int);
unsigned int sum_digits(int);


/* main / wrapper function */
int main()
{
    printf("HAPPY NUMBERS\n\n");
    
    /* calculate and evaluate */
    const int number = 10;
    const int result = is_happy_number(number);

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
int is_happy_number(int number)
{ 
    const int array_length = 255;
    int* number_array = (int *) malloc(sizeof(int) * array_length);
    int counter = 0;
  
    /* while the number is > 1 and was not found previously (loop) - keep calculating */
    while(number > 1 && is_in_array(number, number_array, array_length) == 0)
    {
        /* overwrite array to prevent overflow */
        if(counter > (array_length - 1))
        {
            counter = 0;
        }

        number_array[counter] = number;
        number = sum_digits(number);
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
int is_in_array(const int number, int *number_array, const int array_length)
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
unsigned int sum_digits(int number) 
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
