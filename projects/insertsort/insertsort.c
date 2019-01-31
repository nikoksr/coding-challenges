/************************************************************
 * insert sort                                              *
 *                                                          *
 * -> iterate through array starting at the left side       *
 * -> if element left from current element is bigger        *
 *      -> swap elements                                    *
 ************************************************************/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include "../../helper-functions/array_help.h"

/* declarations */
void insertsort(int* arr, const unsigned int arr_len);

/* main / wrapper function */
int main() {
  /* create random array of some length */
  const unsigned int length = 100000;
  int* some_array = (int*)malloc(sizeof(int) * length);
  make_random_array(some_array, length);

  /* run insertsort against array */
  const unsigned int new_line = 25;
  print_array(some_array, length, new_line);
  insertsort(some_array, length);
  print_array(some_array, length, new_line);
  free(some_array);
  return 0;
}

/* definitions */
/* run insertion sort algorithm */
void insertsort(int* arr, const unsigned int arr_len) {
  unsigned int counter_one = 1;

  while (counter_one < arr_len) {
    unsigned int counter_two = counter_one;

    while (counter_two > 0 &&
           arr[counter_two - 1] > arr[counter_two]) {
      swap(&arr[counter_two], &arr[counter_two - 1]);
      counter_two--;
    }

    counter_one++;
  }
}
