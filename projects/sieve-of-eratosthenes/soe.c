/*******************************************************************************
 * Title: Sieve of Eratosthenes
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Create a list of consecutive integers from 2 through n.
 *  Initially let p equal 2, the smallest prime and enumerate its multiples by
 *  counting in increments from 2p to n and remove them from the list. p itself
 *  should not be removed. Now find the first number greater than p in the list
 *  of remaining numbers. If there was no such number, stop. Otherwise, let p
 *  now equal this new number (which is the next prime), and repeat the process.
 *  When the algorithm terminates, the numbers remaining in the list are all the
 *  primes below n.
 ******************************************************************************/

/* Includes */
#include "../../helper-functions/array_help.h"
#include <stdio.h>
#include <stdlib.h>

/* Declarations */
void soe(int* arr, const unsigned int len);
void print_sieve(int* arr, const unsigned int len, const unsigned int new_line);

/* Main function */
int main() {
    printf("SIEVE OF ERASTOSTHENES\n\n");

    /* Make sorted array */
    const int start = 2;
    const int end = 100000;
    const unsigned int len = end - start + 1;
    int* arr = (int*)malloc(sizeof(int) * (size_t)len);

    make_sorted_array(arr, start, end);

    /* Sieve */
    soe(arr, len);
    print_sieve(arr, len, 20);
    free(arr);
    return 0;
}

/* Definitions */
void soe(int* arr, const unsigned int len) {
    unsigned int i = 0;
    int p = arr[i];
    const int max = arr[len - 1];

    while(p * p <= max) {
        for(unsigned int j = i + p; j <= len; j += p){
            if(arr[j] != 0 && arr[j] % p == 0) {
                arr[j] = 0;
            }
        }

        do {
            i++;
            p = arr[i];
        } while(p == 0);
    }
}

void print_sieve(int* arr, const unsigned int len, const unsigned int new_line) {
    unsigned int line_counter = 0;

    for(unsigned int i = 0; i < len; ++i) {
        if(arr[i] == 0) {
            continue;
        }

        if(line_counter != 0 && line_counter % new_line == 0) {
            printf("\n");
        }

        printf("%i ", arr[i]);
        line_counter++;
    }

    printf("\n");
}
