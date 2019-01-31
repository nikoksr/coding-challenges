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
void insertsort(int* arr, const unsigned int len);

/* main / wrapper function */
int main() {
  /* create random array of some length */
  const unsigned int len = 100000;
  int* some_array = (int*)malloc(sizeof(int) * len);
  make_random_array(some_array, len);

  /* run insertsort against array */
  const unsigned int new_line = 25;
  print_array(some_array, len, new_line);
  insertsort(some_array, len);
  print_array(some_array, len, new_line);
  free(some_array);
  return 0;
}

/* definitions */
/* run insertion sort algorithm */
void insertsort(int* arr, const unsigned int len) {
  unsigned int counter_one = 1;

  while (counter_one < len) {
    unsigned int counter_two = counter_one;

    while (counter_two > 0 &&
           arr[counter_two - 1] > arr[counter_two]) {
      swap(&arr[counter_two], &arr[counter_two - 1]);
      counter_two--;
    }

    counter_one++;
  }
}
