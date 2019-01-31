/************************************************************
 * binary search                                            *
 *                                                          *
 * -> given a sorted array                                  *
 * -> search for a given value in this array                *
 * -> first, check the value of the element in the center   *
 *      of the array                                        *
 * -> either the value is lower, higher or equal to the     *
 *      searched value                                      *
 * -> in case of an equal value the search is completed     *
 * -> in case of a lower value, the searched value has to   *
 *      be on the left of the center value                  *
 * -> same goes for a higher value, just to the opposite    *
 *      site of the array                                   *
 * -> repeat the steps above                                *
 ************************************************************/

/* includes */
#include "../../helper-functions/array_help.h"
#include <stdio.h>
#include <stdlib.h>

/* declarations */
int binary_search(int* arr, unsigned int low, unsigned int high, const int searched_value);
void evaluate_search_result(const int res, const int searched_value);

/* main / wrapper function */
int main() {
  /* create sorted array */
  const unsigned int len = 9;
  int* arr = (int*)malloc(sizeof(int) * len);
  make_sorted_array(arr, len);

  /* print array */
  print_array(arr, len, 50);

  /* start binary search */
  const int searched_value = 7;
  const int res = binary_search(arr, 0, (len - 1), searched_value);

  /* evaluate result from binary search */
  evaluate_search_result(res, searched_value);
  free(arr);
  return 0;
}

/* definitions */
/* use binary search algorithm to find value in array
 * return index of value in array or -1 if value not found
 * */
int binary_search(int* arr, unsigned int low, int unsigned high, const int searched_value) {
  if (high < low) {
    return -1;
  }

  int center = (high + low) / 2;

  if (searched_value == arr[center]) {
    return center;
  }

  if (searched_value < arr[center]) {
    high = center - 1;
  } else {
    low = center + 1;
  }

  return binary_search(arr, low, high, searched_value);
}

/* evaluate the result from a binary search */
void evaluate_search_result(const int res, const int searched_value) {
  switch (res) {
    case -1:
      printf("Value not found.\n");
      break;
    default:
      printf("Value %d found at index %d\n", searched_value, res);
  }
}
