/********************************************************************************
 * Title: Quicksort Algorithm
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Given an array consisting of integers. The starting element (
 *  pivot) is either the first, middle or last element or gets chosen randomly.
 *  To improve the runtime (especially in big arrays) a better pivot may be
 *  chosen by comparing the first, middle and last element. The elements are
 *  swapped depending on their value. So the smallest value gets assigned to the
 *  first element, the middle value to the middle element and the biggest value
 *  to the last element. The last element becomes the pivot. Now compare every
 *  element with the pivot. Elements with a bigger value than the pivot go to the
 *  right of the pivot and values smaller than the pivot got to the left. Values
 *  that are equal to the pivot can go either way. The pivot is in its final
 *  position after it got compared with every element. Now the array gets split.
 *  All values bigger and all values smaller than the pivot, so the values left
 *  and right from and unequal to the pivot, respectively become a sub-array.
 *  Recursively apply the above steps to the sub-arrays.
 *******************************************************************************/

/* Includes */
#include "../../helper-functions/array_help.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Declarations */
void quicksort(int* arr, const unsigned int low, const unsigned int high);
unsigned int partitioning(int* arr, const unsigned int pivot, const unsigned int low, const unsigned int high);
unsigned int pick_median_of_three_pivot(int* arr, const unsigned int low, const unsigned int high);

/* Main function */
int main() {
  printf("QUICKSORT\n\n");

  /* Create a random array */
  const unsigned int len = 1000000;
  int* arr = (int*)malloc(sizeof(int) * len);
  make_random_array(arr, len);

  /* Print unsorted array */
  const unsigned int new_line = 50;
  print_array(arr, len, new_line);
  printf("\n");

  /* Sort the array */
  quicksort(arr, 0, len - 1);

  /* Print sorted array */
  print_array(arr, len, new_line);
  printf("\n");
  free(arr);
  return 0;
}

/* Definitions */
void quicksort(int* arr, const unsigned int low, const unsigned int high) {
  if (low < high) {
    /* Pick the median */
    unsigned int pivot = pick_median_of_three_pivot(arr, low, high);

    /* Partition the array */
    pivot = partitioning(arr, pivot, low, high);

    /* Recursion with both halfs of the partitioned array */
    quicksort(arr, low, pivot);
    quicksort(arr, pivot + 1, high);
  }
}

unsigned int partitioning(int* arr, const unsigned int pivot, const unsigned int low, const unsigned int high) {
  unsigned int i = low - 1;
  unsigned int j = high + 1;

  for (;;) {
    /* Search from left side for value bigger than the pivots value */
    do {
      i++;
    } while (arr[i] < arr[pivot]);

    /* Search from right for value smaller than the pivots value */
    do {
      j++;
    } while (arr[j] > arr[pivot]);

    /* Pivot is in its final position */
    if (i >= j) {
      return j;
    }

    /* Swap the smaller value with the bigger value */
    swap(&arr[i], &arr[j]);
  }
}

unsigned int pick_median_of_three_pivot(int* arr, const unsigned int low, const unsigned int high) {
  const unsigned int middle = (low + high) / 2;

  if (arr[middle] < arr[low]) {
    swap(&arr[low], &arr[middle]);
  }

  if (arr[high] < arr[low]) {
    swap(&arr[low], &arr[high]);
  }

  if (arr[middle] < arr[high]) {
    swap(&arr[middle], &arr[high]);
  }

  return high;
}
