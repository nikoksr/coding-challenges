/************************************************
 * bubblesort                                   *
 *                                              *
 *  -> run through the list                     *
 *  -> compare pair of adjacent items           *
 *  -> swap them if they are in wrong order     *
 *  -> repeat until no more swaps are needed    *
 ************************************************/

 
/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../helper-functions/array_help.h"


/* declarations */
void bubblesort(int *, int);


/* main / wrapper function */
int main()
{
    printf("BUBBLESORT\n\n");

    /* create a random array of given length */
    const int array_length = 10;
    int *number_array = (int *) malloc(sizeof(int) * array_length);
    make_random_array(number_array, array_length);
    
    /* print unsorted array */
    const int new_line = 50;

    print_array(number_array, array_length, new_line);
    
    /* sort the array */
    bubblesort(number_array, array_length);
    
    /* print sorted array */
    print_array(number_array, array_length, new_line);

    free(number_array);
    
    return 0;
}


/* definitions */
/* bubblesort algorithm */
void bubblesort(int *some_array, const int array_length)
{
    for(int i = 0; i < array_length - 1; ++i)
    {
        /* if element bigger than following element -> swap them 
         * and start again at first element
         * */
        if(some_array[i] > some_array[i + 1])
        {
            swap(&some_array[i], &some_array[i + 1]);
            i = -1;
        }
    }
}
