/************************************************************
 * insert sort                                              *
 *                                                          *
 * -> iterate through array starting at the left side       *
 * -> if element left from current element is bigger        *
 *      -> swap elements                                    *
 ************************************************************/

/* includes */
#include "../../helper-functions/array_help.h"
#include <stdio.h>
#include <stdlib.h>

/* declarations */
void insertsort(int *, int);

/* main / wrapper function */
int main()
{
    const int length = 100000;
    int *some_array = (int *)malloc(sizeof(int) * length);
    make_random_array(some_array, length);

    const int new_line = 25;
    print_array(some_array, length, new_line);
    insertsort(some_array, length);
    print_array(some_array, length, new_line);

    free(some_array);

    return 0;
}

/* definitions */
/* run insertion sort algorithm */
void insertsort(int *some_array, const int array_length)
{
    int counter_one = 1;

    while (counter_one < array_length)
    {
        int counter_two = counter_one;

        while (counter_two > 0 &&
               some_array[counter_two - 1] > some_array[counter_two])
        {
            swap(&some_array[counter_two], &some_array[counter_two - 1]);
            counter_two = counter_two - 1;
        }

        counter_one = counter_one + 1;
    }
}
