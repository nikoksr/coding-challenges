/************************************************************
 * insert sort                                              *
 *                                                          *
 * -> iterate through array starting at the left side       *
 * -> if element left from current element is bigger        *
 *      -> swap elements                                    *
 ************************************************************/


/* includes */
#include <stdio.h>


/* declarations */
void PrintArray(int *, int);
void Swap(int *, int *);
void InsertSort(int *, int );


/* main / wrapper function */
int main()
{   
    const int length = 5;
    int some_array[5] = {3, 2, 5, 1, 4};

    PrintArray(some_array, length);
    InsertSort(some_array, length);
    PrintArray(some_array, length);

    return 0;
}


/* definitions */
/* print an array */
void PrintArray(int *some_array, int array_length)
{
    for(int i = 0; i < array_length; ++i)
    {
        if(i != 0 && i % 25 == 0)
        {
            printf("\n");
        }

        printf("%d", some_array[i]);
    }

    printf("\n");
}


/* swap two values */
void Swap(int *value_one, int *value_two)
{
    int temp = *value_one;
    *value_one = *value_two;
    *value_two = temp;
}


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
