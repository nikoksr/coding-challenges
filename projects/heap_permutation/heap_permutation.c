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
void heap_permutation(int* arr, const unsigned int original_len, const unsigned int len);

/* main / wrapper function */
int main() {
  printf("HEAP PERMUTATION\n\n");

  /* Create sorted array of some size */
  const int len = 3;
  int* arr = (int*)malloc(sizeof(int) * len);
  make_sorted_array(arr, len);

  /* Run heap permutation against array */
  heap_permutation(arr, len, len);
  free(arr);
  return 0;
}

/* definitions */
void heap_permutation(int* arr, const unsigned int original_len, const unsigned int new_len) {
  /* print array once length equals 1 */
  if (new_len == 1) {
    print_array(arr, original_len, 25);
    return;
  }

  for (unsigned int i = 0; i < new_len; ++i) {
    /* recursive call and decreasing length by one */
    heap_permutation(arr, original_len, new_len - 1);

    /* if length is even, swap i-th element and last element */
    if (new_len % 2 == 0) {
      swap(&arr[i], &arr[new_len - 1]);
    }
    /* if length is odd, swap first element and last element */
    else {
      swap(&arr[0], &arr[new_len - 1]);
    }
  }
}
