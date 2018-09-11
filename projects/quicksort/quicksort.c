/************************************************************
 * Quicksort Algorithm                                      *
 *                                                          *
 *  -> pick an element(pivot) from the array                * 
 *                                                          *
 *  -> partitioning:                                        *
 *      - reorder the array:                                *
 *          - elements with value less than pivot           *
 *              go to the left of pivot                     *
 *          - elements with value greater than pivot        *
 *              go to the right                             *
 *          - elements with value equal to pivot            *
 *              can go either way                           *
 *      - pivot is in its final position                    *
 *                                                          *
 *  -> recursively apply the above steps to the sub-array   *
 *      of elements with smaller and greater values         *
 *                                                          *
 *  -> using the median of three to choose the pivot and    *
 *      using the hoare partition scheme for the            *
 *      partitioning                                        * 
 ************************************************************/

/* includes */
#include "../../helper-functions/array_help.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* declarations */
void quicksort(int *, int, int);
int partitioning(int *, int, int, int);
int pick_median_pivot(int *, int, int);

/* main / wrapper function */
int main()
{
    printf("QUICKSORT\n\n");

    /* create a random array of given length */
    const int array_length = 1000000;
    int *number_array = (int *)malloc(sizeof(int) * array_length);
    make_random_array(number_array, array_length);

    /* print unsorted array */
    const int new_line = 50;
    print_array(number_array, array_length, new_line);
    printf("\n");

    /* sort the array */
    quicksort(number_array, 0, array_length - 1);

    /* print sorted array */
    print_array(number_array, array_length, new_line);
    printf("\n");

    free(number_array);

    return 0;
}

/* definitions */
/* quicksort algorithm */
void quicksort(int *number_array, const int low, const int high)
{
    if (low < high)
    {
        /* pick the pivot */
        int pivot = pick_median_pivot(number_array, low, high);

        /* partition the array */
        pivot = partitioning(number_array, pivot, low, high);

        /* recursion with both halfs of the partitioned array */
        quicksort(number_array, low, pivot);
        quicksort(number_array, pivot + 1, high);
    }
}

/* partition the array
 * hoare partition scheme */
int partitioning(int *number_array, const int pivot, const int low, const int high)
{
    int i = low - 1;
    int j = high + 1;

    for (;;)
    {
        /* search from left side for value bigger than the pivots value */
        do
        {
            i = i + 1;
        } while (number_array[i] < number_array[pivot]);

        /* search from rigth for value smaller than the pivots value */
        do
        {
            j = j - 1;
        } while (number_array[j] > number_array[pivot]);

        /* pivot is in its final position */
        if (i >= j)
        {
            return j;
        }

        /* swap the smaller value with the bigger value */
        swap(&number_array[i], &number_array[j]);
    }
}

/* picks pivot via median of three */
int pick_median_pivot(int *number_array, const int low, const int high)
{
    int middle = (low + high) / 2;

    if (number_array[middle] < number_array[low])
    {
        swap(&number_array[low], &number_array[middle]);
    }

    if (number_array[high] < number_array[low])
    {
        swap(&number_array[low], &number_array[high]);
    }

    if (number_array[middle] < number_array[high])
    {
        swap(&number_array[middle], &number_array[high]);
    }

    return high;
}
