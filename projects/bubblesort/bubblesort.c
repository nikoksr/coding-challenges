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


/* declarations */
void Bubblesort(int *, int);
void Swap(int *, int *);
void PrintArray(int *, int);
int *MakeRandomArray(int);


/* main / wrapper function */
int main()
{
    int array_length;
    
    /* take in individual array length */
    printf("BUBBLESORT\n\nEnter the length of your random array: ");
    scanf("%d", &array_length);
    
    /* create a random array of given length */
    int *number_array = MakeRandomArray(array_length);
    
    /* print unsorted array */
    printf("\nRandom Array:\n");
    PrintArray(number_array, array_length);
    
    /* sort the array */
    Bubblesort(number_array, array_length);
    
    /* print sorted array */
    printf("\nSorted Array:\n");
    PrintArray(number_array, array_length);
    
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


/* swap values of two items */
void Swap(int *number_one, int *number_two)
{
    int temp = *number_one;
    *number_one = *number_two;
    *number_two = temp;
}


/* print an array */
void PrintArray(int *some_array, int array_length)
{
    /* loop through every element */
    for(int i = 0; i < array_length; ++i)
    {
        /* new row after every 25th element */
        if(i != 0 && i % 25 == 0)
        {
            printf("\n");
        }

        printf("%d ", some_array[i]);
    }

    printf("\n");
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
