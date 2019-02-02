/********************************************************************************
 * Title: Insert Sort
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Iterate through an unsorted array consisting of integers starting
 *  at the first element of the array which is considered as sorted. Iterate over
 *  the array and check each element with the previous elements. Elements smaller
 *  than the current element are inserted before the current element.
 *******************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include "../../helper-functions/array_help.h"

/* Declarations */
void insertsort(int* arr, const unsigned int len);

/* Main function */
int main() {
  /* Create random integer array */
  const unsigned int len = 100000;
  int* arr = (int*)malloc(sizeof(int) * len);

  make_random_array(arr, len);

  /* Run insertsort against the array */
  const unsigned int new_line = 25;

  print_array(arr, len, new_line);
  insertsort(arr, len);
  print_array(arr, len, new_line);
  free(arr);
  return 0;
}

/* Definitions */
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
