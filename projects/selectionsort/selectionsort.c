/************************************************************
 * selection sort                                           *
 *                                                          *
 * -> use linear search to find the smallest value in       *
 *      array                                               *
 * -> smallest value swaps with the leftmost value and is   *
 *      considered to be in its final position              *
 * -> these steps are repeated until array is fully sorted  *
 ************************************************************/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include "../../helper-functions/array_help.h"

/* declarations */
int find_smallest_value(int* arr, const unsigned int len, const unsigned int index);
void selection_sort(int* arr, const unsigned int len);

/* main / wrapper function */
int main() {
  printf("SELECTION-SORT\n\n");

  /* create a random array of given length */
  const unsigned int len = 100000;
  int* arr = (int*)malloc(sizeof(int) * len);
  make_random_array(arr, len);

  /* print unsorted array */
  const unsigned int new_line = 25;
  print_array(arr, len, new_line);

  /* sort the array */
  selection_sort(arr, len);

  /* print sorted array */
  print_array(arr, len, new_line);
  free(arr);
  return 0;
}

/* definitions */
/* finds smallest value in array and returns its index */
int find_smallest_value(int* arr, const unsigned int len, const unsigned int index) {
  unsigned int smallest = index;

  for (unsigned int i = (index + 1); i < len; ++i) {
    if (arr[i] < arr[smallest]) {
      smallest = i;
    }
  }

  return smallest;
}

/* selctionsort algorithm */
void selection_sort(int* arr, const unsigned int len) {
  unsigned int smallest;

  for (unsigned int i = 0; i < len; ++i) {
    smallest = find_smallest_value(arr, len, i);
    if (arr[smallest] < arr[i]) {
      swap(&arr[smallest], &arr[i]);
    }
  }
}
