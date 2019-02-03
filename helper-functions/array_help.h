#ifndef HELPER_FUNCS_H
#define HELPER_FUNCS_H

/* Print an array */
void print_array(int* arr, const unsigned int len, const unsigned int new_line);

/* Make an array of given length filled with random values */
void make_random_array(int* arr, const unsigned int len);

/* Make an array of given length filled with sorted values */
void make_sorted_array(int* arr, const unsigned int len);

/* Swap the values of two integer variables */
void swap(int* var_one, int* var_two);

#endif /* HELPER_FUNCS_H */
