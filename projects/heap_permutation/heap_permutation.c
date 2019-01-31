/************************************************************
 * heap permutation                                         *
 *                                                          *
 * -> the heap algorithm shows all possible permutations    *
 *      of a given array                                    *
 * -> it generates each permutation from the previous one   *
 *      by interchanging a single pair of elements          *
 * -> the other n−2 elements are not disturbed              *
 ************************************************************/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include "../../helper-functions/array_help.h"

/* declarations */
void heap_permutation(int* some_array, const unsigned int total_length, const unsigned int length);

/* main / wrapper function */
int main() {
  printf("HEAP PERMUTATION\n\n");

  /* Create sorted array of some size */
  const int len = 3;
  int* some_array = (int*)malloc(sizeof(int) * len);
  make_sorted_array(some_array, len);

  /* Run heap permutation against array */
  heap_permutation(some_array, len, len);
  free(some_array);
  return 0;
}

/* definitions */
void heap_permutation(int* some_array, const unsigned int total_length, const unsigned int length) {
  /* print array once length equals 1 */
  if (length == 1) {
    print_array(some_array, total_length, 25);
    return;
  }

  for (unsigned int i = 0; i < length; ++i) {
    /* recursive call and decreasing length by one */
    heap_permutation(some_array, total_length, length - 1);

    /* if length is even, swap i-th element and last element */
    if (length % 2 == 0) {
      swap(&some_array[i], &some_array[length - 1]);
    }
    /* if length is odd, swap first element and last element */
    else {
      swap(&some_array[0], &some_array[length - 1]);
    }
  }
}
