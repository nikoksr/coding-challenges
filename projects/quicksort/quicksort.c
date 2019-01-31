/************************************************************
 * Quicksort Algorithm                                      *
 *                                                          *
 *  -> pick an element(pivot) from the array                *
 *  -> partitioning:                                        *
 *      - reorder the array:                                *
 *          - elements with value less than pivot           *
 *              go to the left of pivot                     *
 *          - elements with value greater than pivot        *
 *              go to the right                             *
 *          - elements with value equal to pivot            *
 *              can go either way                           *
 *      - pivot is in its final position                    *
 *  -> recursively apply the above steps to the sub-array   *
 *      of elements with smaller and greater values         *
 *  -> using the median of three to choose the pivot and    *
 *      using the hoare partition scheme for the            *
 *      partitioning                                        *
 ************************************************************/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../helper-functions/array_help.h"

/* declarations */
void quicksort(int* arr, const unsigned int low, const unsigned int high);
unsigned int partitioning(int* arr, const unsigned int pivot, const unsigned int low, const unsigned int high);
unsigned int pick_median_pivot(int* arr, const unsigned int low, const unsigned int high);

/* main / wrapper function */
int main() {
  printf("QUICKSORT\n\n");

  /* create a random array of given length */
  const unsigned int len = 1000000;
  int* arr = (int*)malloc(sizeof(int) * len);
  make_random_array(arr, len);

  /* print unsorted array */
  const unsigned int new_line = 50;
  print_array(arr, len, new_line);
  printf("\n");

  /* sort the array */
  quicksort(arr, 0, len - 1);

  /* print sorted array */
  print_array(arr, len, new_line);
  printf("\n");
  free(arr);
  return 0;
}

/* definitions */
/* quicksort algorithm */
void quicksort(int* arr, const unsigned int low, const unsigned int high) {
  if (low < high) {
    /* pick the median pivot */
    unsigned int pivot = pick_median_pivot(arr, low, high);

    /* partition the array */
    pivot = partitioning(arr, pivot, low, high);

    /* recursion with both halfs of the partitioned array */
    quicksort(arr, low, pivot);
    quicksort(arr, pivot + 1, high);
  }
}

/* partition the array
 * hoare partition scheme */
unsigned int partitioning(int* arr, const unsigned int pivot, const unsigned int low, const unsigned int high) {
  unsigned int i = low - 1;
  unsigned int j = high + 1;

  for (;;) {
    /* search from left side for value bigger than the pivots value */
    do {
      i++;
    } while (arr[i] < arr[pivot]);

    /* search from rigth for value smaller than the pivots value */
    do {
      j++;
    } while (arr[j] > arr[pivot]);

    /* pivot is in its final position */
    if (i >= j) {
      return j;
    }

    /* swap the smaller value with the bigger value */
    swap(&arr[i], &arr[j]);
  }
}

/* picks pivot via median of three */
unsigned int pick_median_pivot(int* arr, const unsigned int low, const unsigned int high) {
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
