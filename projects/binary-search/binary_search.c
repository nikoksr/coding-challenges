/************************************************************
 * binary search                                            *
 *                                                          *
 * -> given is a sorted array                               *
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
int binary_search(int* number_array,
                  int low,
                  int high,
                  const int searched_value);
void evaluate_search_result(const int result, const int searched_value);

/* main / wrapper function */
int main() {
  /* create sorted array */
  const int length = 9;
  int* number_array = (int*)malloc(sizeof(int) * length);
  make_sorted_array(number_array, length);

  /* pint array */
  const int new_line = 50;
  print_array(number_array, length, new_line);

  /* start binary search */
  const int searched_value = 7;
  const int result =
      binary_search(number_array, 0, (length - 1), searched_value);

  /* evaluate result from binary search */
  evaluate_search_result(result, searched_value);

  free(number_array);
  return 0;
}

/* definitions */
/* use binary search algorithm to find value in array
 * return index of value in array or -1 if value not found
 * */
int binary_search(int* number_array,
                  int low,
                  int high,
                  const int searched_value) {
  if (high < low) {
    return -1;
  }

  int center = ((high + low) / 2);

  if (searched_value == number_array[center]) {
    return center;
  }

  if (searched_value < number_array[center]) {
    high = center - 1;
  } else {
    low = center + 1;
  }

  return binary_search(number_array, low, high, searched_value);
}

/* evaluate the result from a binary search */
void evaluate_search_result(const int result, const int searched_value) {
  switch (result) {
    case -1:
      printf("Value not found.\n");
      break;
    default:
      printf("Value %d found at index %d\n", searched_value, result);
  }
}
