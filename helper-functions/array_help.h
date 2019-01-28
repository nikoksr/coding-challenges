#ifndef HELPER_FUNCS_H
#define HELPER_FUNCS_H

/* make an array of given length filled with random values */
void make_random_array(int* random_array, const int array_length);

/* make an array of given length filled with sorted values */
void make_sorted_array(int* sorted_array, const int array_length);

/* print an array */
void print_array(int* some_array, const int array_length, const int new_line);

/* swap the values of two integer variables */
void swap(int* var_one, int* var_two);

#endif /* HELPER_FUNCS_H */
