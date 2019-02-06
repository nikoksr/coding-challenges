/********************************************************************************
 * Title: Heap Permutation
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: The algorithm shows all possible permutations of a given array.
 *  It generates each permutation based on the previous one by interchanging a
 *  single pair of elements in the array while the other n−2 elements are not
 *  disturbed.
 *******************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include "../../helper-functions/array_help.h"

/* Declarations */
void heap_permutation(int* arr, const unsigned int original_len, const unsigned int len);

/* Main function */
int main() {
    printf("HEAP PERMUTATION\n\n");

    /* Create sorted array and run heap permutation */
    const int start = 0;
    const int end = 4;
    const unsigned int len = end - start + 1;
    int* arr = (int*)malloc(sizeof(int) * len);

    make_sorted_array(arr, start, end);
    heap_permutation(arr, len, len);
    free(arr);
    return 0;
}

/* Definitions */
void heap_permutation(int* arr, const unsigned int original_len, const unsigned int new_len) {
    if (new_len == 1) {
        print_array(arr, original_len, 25);
        return;
    }

    for (unsigned int i = 0; i < new_len; ++i) {
        /* Decrease length by one and call recursivly */
        heap_permutation(arr, original_len, new_len - 1);

        /* If length is even, swap i-th and last element */
        if (new_len % 2 == 0) {
            swap(&arr[i], &arr[new_len - 1]);
        }
        /* If length is odd, swap first and last element */
        else {
            swap(&arr[0], &arr[new_len - 1]);
        }
    }
}
