/********************************************************************************
 * Title: Binary Search
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Given a sorted array, search for a given value in this array.
 *  First, check the value of the element in the center of the array. Either the
 *  value is lower, higher or equal to the searched value. In case of an equal
 *  value the search is completed. In case of a lower value the searched value
 *  has to be to on left side of the current element. Same goes for a higher
 *  value which has to be on the right side of the current element. Go to the
 *  center element of the corresponding side. Repeat these steps until the value
 *  is either found or not.
 *******************************************************************************/

/* Includes */
#include "../../helper-functions/array_help.h"
#include <stdio.h>
#include <stdlib.h>

/* Declarations */
int binary_search(int* arr, unsigned int low, unsigned int high, const int searched_value);
void evaluate_search_result(const int res, const int searched_value);

/* Main function */
int main() {
    /* Create sorted array */
    const int start = 0;
    const int end = 10;
    const unsigned int len = end - start + 1;
    int* arr = (int*)malloc(sizeof(int) * len);
    make_sorted_array(arr, start, end);

    /* Print array */
    print_array(arr, len, 50);

    /* Start binary search */
    const int searched_value = 7;
    const int res = binary_search(arr, 0, (len - 1), searched_value);

    free(arr);
    evaluate_search_result(res, searched_value);
    return 0;
}

/* Definitions */
int binary_search(int* arr, unsigned int low, int unsigned high, const int searched_value) {
    if (high < low) {
        return -1;
    }

    int center = (high + low) / 2;

    if (searched_value == arr[center]) {
        return center;
    }

    if (searched_value < arr[center]) {
        high = center - 1;
    } else {
        low = center + 1;
    }

    return binary_search(arr, low, high, searched_value);
}

void evaluate_search_result(const int res, const int searched_value) {
    switch (res) {
    case -1:
        printf("Value not found.\n");
        break;
    default:
        printf("Value %d found at index %d\n", searched_value, res);
    }
}
