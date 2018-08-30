#include "array_help.h"

/* print an array */
void PrintArray(int *some_array, int array_length, int new_line)
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
void MakeRandomArray(int *random_array, int array_length)
{
    srand(time(NULL));

    for(int i = 0; i < array_length; i++)
    {
        int random = rand() % 10;
        random_array[i] = random;
    }
}

/* swap the values of two integer variables */
void Swap(int *var_one, int *var_two)
{
    int temp = *var_one;
    *var_one = *var_two;
    *var_two = temp;
}
