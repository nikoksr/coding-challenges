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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/* declarations */
int *MakeRandomArray(int);
void PrintArray(int *, int);
void Quicksort(int *, int, int);
int Partitioning(int *, int, int, int);
void Swap(int *, int *);
int PickMedianPivot(int *, int, int);


/* main / wrapper function */
int main()
{
    /* take in individual array length */
    int array_length;
    printf("Enter the length of your random array: ");
    scanf("%d", &array_length);
    
    /* create a random array of given length */
    int *number_array = MakeRandomArray(array_length);
    
    /* print unsorted array */
    printf("\nRandom Array:\n");
    PrintArray(number_array, array_length);
    
    /* sort the array */
    Quicksort(number_array, 0, array_length - 1);
    
    /* print sorted array */
    printf("\nSorted Array:\n");
    PrintArray(number_array, array_length);
    
    free(number_array);

    return 0;
}


/* makes an array of given length filled with random values */
int *MakeRandomArray(int array_length)
{
    size_t array_size = array_length * sizeof(int); 
    int *number_array = (int *) malloc(array_size);

    srand(time(NULL));

    for(int i = 0; i < array_length; i++)
    {
        int random = rand() % 10;
        number_array[i] = random;
    }

    return number_array;
}


/* prints an array */
void PrintArray(int *number_array, int array_length)
{
    /* loop through every element */
    for(int i = 0; i < array_length; ++i)
    {
        /* new row after every 25th element */
        if(i % 25 == 0)
        {
            printf("\n");
        }

        printf("%d ", number_array[i]);
    }

    printf("\n");
}


/* quicksort algorithm */
void Quicksort(int *number_array, int low, int high)
{ 
    if(low < high)
    { 
        /* pick the pivot */
        int pivot = PickMedianPivot(number_array, low, high);
        
        /* partition the array */
        pivot = Partitioning(number_array, pivot, low, high);

        /* recursion with both halfs of the partitioned array */
        Quicksort(number_array, low, pivot);
        Quicksort(number_array, pivot + 1, high);
    }
}


/* partition the array
 * hoare partition scheme */
int Partitioning(int *number_array, int pivot, int low, int high)
{
    int i = low - 1;
    int j = high + 1;

    for(;;)
    {
        /* search from left side for value bigger than the pivots value */
        do
        {
            i = i + 1;
        }
        while(number_array[i] < number_array[pivot]);

        /* search from rigth for value smaller than the pivots value */
        do 
        {
            j = j - 1;
        }
        while(number_array[j] > number_array[pivot]);

        /* pivot is in its final position */
        if(i >= j)
        {
            return j;
        }

        /* swap the smaller value with the bigger value */
        Swap(&number_array[i], &number_array[j]);
    }
}


/* picks pivot via median of three */
int PickMedianPivot(int *number_array, int low, int high)
{
    int middle = (low + high) / 2;

    if(number_array[middle] < number_array[low])
    {
        Swap(&number_array[low], &number_array[middle]);
    }

    if(number_array[high] < number_array[low])
    {
        Swap(&number_array[low], &number_array[high]);
    }
    
    if(number_array[middle] < number_array[high])
    {
        Swap(&number_array[middle], &number_array[high]);
    }

    return high;
}


/* swaps to elements of an array */
void Swap(int *value_one, int *value_two)
{
    int temp = *value_one;
    *value_one = *value_two;
    *value_two = temp;
}
