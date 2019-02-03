#include "array_help.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* arr, const unsigned int len, const unsigned int new_line) {
  for (unsigned int i = 0; i < len; ++i) {
    /* New line after every n-th element */
    if (i != 0 && i % new_line == 0) {
      printf("\n");
    }

    printf("%d ", arr[i]);
  }

  printf("\n");
}

void make_random_array(int* arr, const unsigned int len) {
  srand(time(NULL));

  for (unsigned int i = 0; i < len; i++) {
    int random = rand() % 10;
    arr[i] = random;
  }
}

void make_sorted_array(int* arr, const unsigned int len) {
  for (unsigned int i = 0; i < len; ++i) {
    arr[i] = (i);
  }
}

void swap(int* var_one, int* var_two) {
  const int temp = *var_one;
  *var_one = *var_two;
  *var_two = temp;
}
