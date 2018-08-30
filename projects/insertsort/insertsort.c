/************************************************************
 * insert sort                                              *
 *                                                          *
 * -> iterate through array starting at the left side       *
 * -> if element left from current element is bigger        *
 *      -> swap elements                                    *
 ************************************************************/


/* includes */
#include <stdio.h>
#include "../../helper-functions/arrays/array_help.h"


/* declarations */
void InsertSort(int *, int );


/* main / wrapper function */
int main()
{   
    const int new_line = 25;
    const int length = 5;
    int some_array[5] = {3, 2, 5, 1, 4};

    PrintArray(some_array, length, new_line);
    InsertSort(some_array, length);
    PrintArray(some_array, length, new_line);

    return 0;
}


/* definitions */
/* run insertion sort algorithm */
void InsertSort(int *some_array, int array_length)
{
    int counter_one = 1;

    while(counter_one < array_length)
    {
        int counter_two = counter_one;

        while(counter_two > 0 &&
                some_array[counter_two - 1] > some_array[counter_two])
        {
            Swap(&some_array[counter_two], &some_array[counter_two - 1]);
            counter_two = counter_two - 1;
        }

        counter_one = counter_one + 1;
    }
}
