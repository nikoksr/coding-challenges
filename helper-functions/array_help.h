#ifndef HELPER_FUNCS_H
#define HELPER_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* make an array of given length filled with random values */
void MakeRandomArray(int *random_array, int array_length);

/* print an array */
void PrintArray(int *some_array, int array_length, int new_line);

/* swap the values of two integer variables */
void Swap(int *var_one, int *var_two);

#endif /* HELPER_FUNCS_H */
