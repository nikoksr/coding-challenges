#include "array_help.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* print an array */
void print_array(int* arr, const unsigned int arr_len, const unsigned int new_line) {
  /* loop through every element */
  for (unsigned int i = 0; i < arr_len; ++i) {
    /* new row after every n-th element */
    if (i != 0 && i % new_line == 0) {
      printf("\n");
    }

    printf("%d ", arr[i]);
  }

  printf("\n");
}

/* make an array of given length filled with random values */
void make_random_array(int* arr, const unsigned int arr_len) {
  srand(time(NULL));

  for (unsigned int i = 0; i < arr_len; i++) {
    int random = rand() % 10;
    arr[i] = random;
  }
}

/* make an array of given length filled with sorted values */
void make_sorted_array(int* arr, const unsigned int arr_len) {
  for (unsigned int i = 0; i < arr_len; ++i) {
    arr[i] = (i);
  }
}

/* swap the values of two integer variables */
void swap(int* var_one, int* var_two) {
  const int temp = *var_one;
  *var_one = *var_two;
  *var_two = temp;
}
