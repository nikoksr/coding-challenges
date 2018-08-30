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
#include "../../helper-functions/arrays/array_help.h"


/* declarations */
void Bubblesort(int *, int);


/* main / wrapper function */
int main()
{
    int array_length;
    
    /* take in individual array length */
    printf("BUBBLESORT\n\nEnter the length of your random array: ");
    scanf("%d", &array_length);
    
    /* create a random array of given length */
    int *number_array = (int *) malloc(array_length * sizeof(int));
    MakeRandomArray(number_array, array_length);
    
    /* print unsorted array */
    int new_line = 25;

    printf("\nRandom Array:\n");
    PrintArray(number_array, array_length, new_line);
    
    /* sort the array */
    Bubblesort(number_array, array_length);
    
    /* print sorted array */
    printf("\nSorted Array:\n");
    PrintArray(number_array, array_length, new_line);

    free(number_array);
    
    return 0;
}


/* definitions */
/* bubblesort algorithm */
void Bubblesort(int *some_array, int array_length)
{
    for(int i = 0; i < array_length - 1; ++i)
    {
        /* if element bigger than following element -> swap them 
         * and start again at first element
         * */
        if(some_array[i] > some_array[i + 1])
        {
            Swap(&some_array[i], &some_array[i + 1]);
            i = -1;
        }
    }
}
