/*******************************************************************************
 * Title: Mergesort
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Mergesort is a divide and conquer algorithm. It divides the
 *  input array in two halves and calls itself for the two halfes and then merges
 *  the two sorted halves. An array of the length one is considered to be
 *  sorted.
 ******************************************************************************/

/* Includes */
#include "../../helper-functions/array_help.h"
#include <stdio.h>
#include <stdlib.h>

/* Declarations */
void split(int* arr, const unsigned int len);
void merge(int* arr, const unsigned int len);

/* Main function */
int main() {
    printf("MERGESORT\n\n");

    /* Make random array */
    const int start = 0;
    const int end = 100;
    const unsigned int len = end - start + 1;
    int* arr = (int*)malloc(sizeof(int) * (size_t)len);

    make_random_array(arr, start, end);
    return 0;
}

/* Definitions */
void split(int* arr, const unsigned int len) {
    if(len < 2) {
        return;
    }
}

void merge(int* arr, const unsigned int len) {
}
