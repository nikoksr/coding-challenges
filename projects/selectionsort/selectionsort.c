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
int find_smallest_value(int* number_array, const unsigned int length, const unsigned int index);
void selection_sort(int* number_array, const unsigned int length);

/* main / wrapper function */
int main() {
  printf("SELECTION-SORT\n\n");

  /* create a random array of given length */
  const unsigned int length = 100000;
  int* number_array = (int*)malloc(sizeof(int) * length);
  make_random_array(number_array, length);

  /* print unsorted array */
  const unsigned int new_line = 25;
  print_array(number_array, length, new_line);

  /* sort the array */
  selection_sort(number_array, length);

  /* print sorted array */
  print_array(number_array, length, new_line);
  free(number_array);
  return 0;
}

/* definitions */
/* finds smallest value in array and returns its index */
int find_smallest_value(int* number_array, const unsigned int length, const unsigned int index) {
  int smallest = index;
  unsigned int i;

  for (i = (index + 1); i < length; ++i) {
    if (number_array[i] < number_array[smallest]) {
      smallest = i;
    }
  }

  return smallest;
}

/* selctionsort algorithm */
void selection_sort(int* number_array, const unsigned int length) {
  int smallest;

  for (unsigned int i = 0; i < length; ++i) {
    smallest = find_smallest_value(number_array, length, i);
    if (number_array[smallest] < number_array[i]) {
      swap(&number_array[smallest], &number_array[i]);
    }
  }
}
