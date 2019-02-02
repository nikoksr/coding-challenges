/********************************************************************************
 * Title: Selection Sort
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Use linear-search to find the smallest value in the array. Swap
 *  it with the leftmost value and consider it to be in its final position. This
 *  process gets repeated until the array is sorted. After every sorted element
 *  the index for the next run gets raised by 1. 
 *******************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include "../../helper-functions/array_help.h"

/* Declarations */
int find_smallest_value(int* arr, const unsigned int len, const unsigned int index);
void selection_sort(int* arr, const unsigned int len);

/* Main function */
int main() {
  printf("SELECTION-SORT\n\n");

  /* Create a random array */
  const unsigned int len = 100000;
  int* arr = (int*)malloc(sizeof(int) * len);
  make_random_array(arr, len);

  /* Print the unsorted array */
  const unsigned int new_line = 25;
  print_array(arr, len, new_line);

  /* Sort the array */
  selection_sort(arr, len);

  /* Print the sorted array */
  print_array(arr, len, new_line);
  free(arr);
  return 0;
}

/* Definitions */
int find_smallest_value(int* arr, const unsigned int len, const unsigned int index) {
  unsigned int smallest = index;

  for (unsigned int i = (index + 1); i < len; ++i) {
    if (arr[i] < arr[smallest]) {
      smallest = i;
    }
  }

  return smallest;
}

void selection_sort(int* arr, const unsigned int len) {
  unsigned int smallest;

  for (unsigned int i = 0; i < len; ++i) {
    smallest = find_smallest_value(arr, len, i);
    if (arr[smallest] < arr[i]) {
      swap(&arr[smallest], &arr[i]);
    }
  }
}
