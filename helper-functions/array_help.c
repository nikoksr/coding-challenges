#include "array_help.h"

#include <stdio.h>                                                                                   
#include <stdlib.h>                                                                                  
#include <time.h>

/* print an array */
void print_array(int *some_array, const int array_length, const int new_line)
{
    /* loop through every element */
    for(int i = 0; i < array_length; ++i)
    {
        /* new row after every n-th element */
        if(i != 0
                && i % new_line == 0)
        {
            printf("\n");
        }

        printf("%d ", some_array[i]);
    }

    printf("\n");
}

/* make an array of given length filled with random values */
void make_random_array(int *random_array, const int array_length)
{
    srand(time(NULL));

    for(int i = 0; i < array_length; i++)
    {
        int random = rand() % 10;
        random_array[i] = random;
    }
}


/* make an array of given length filled with sorted values */
void make_sorted_array(int *sorted_array, const int array_length)
{
    for(int i = 0; i < array_length; ++i)
    {
        sorted_array[i] = (i + 1);
    }
}

/* swap the values of two integer variables */
void swap(int *var_one, int *var_two)
{
    int temp = *var_one;
    *var_one = *var_two;
    *var_two = temp;
}
