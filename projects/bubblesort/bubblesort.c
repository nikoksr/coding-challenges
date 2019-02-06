/********************************************************************************
 * Title: Bubblesort
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Given an array filled with numbers. Iterate over the array and
 *  compare every pair of adjacent elements. Swap them if the value of the left
 *  element is bigger than the value of the right element. Repeat until the array
 *  is sorted.
 *******************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../helper-functions/array_help.h"

/* Declarations */
void bubblesort(int* arr, const unsigned int len);

/* Main function */
int main() {
    printf("BUBBLESORT\n\n");

    /* Create a random array */
    const int start = 0;
    const int end = 1000;
    const unsigned int len = end - start + 1;
    int* arr = (int*)malloc(sizeof(int) * len);
    make_random_array(arr, start, end);

    /* Print unsorted array */
    const unsigned int new_line = 50;
    print_array(arr, len, new_line);

    /* Sort the array */
    bubblesort(arr, len);

    /* Print sorted array */
    print_array(arr, len, new_line);
    free(arr);
    return 0;
}

/* Definitions */
void bubblesort(int* arr, const unsigned int len) {
    for (unsigned int i = 0; i < len - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            swap(&arr[i], &arr[i + 1]);
            i = -1;
        }
    }
}
