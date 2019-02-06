/********************************************************************************
 * Title: Collatz Conjencture Algorithm
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Starting with a number n greater than 1. If n is even, divide it
 *  by 2. If n is odd, multiply it by 3 and add 1. How many steps does it take
 *  until n equals 1?
 ********************************************************************************/

/* Includes */
#include <stdio.h>

/* Declarations */
int col_con_algo(const unsigned int num);

/* Main function */
int main() {
    printf("COLLATZ CONJENCTURE ALGORITHM\n\n");

    const unsigned int num = 0;
    const unsigned int steps = col_con_algo(num);

    printf("It took %d steps to complete the algorithm.\n", steps);
    return 0;
}

/* Definitions */
int col_con_algo(const unsigned int num) {
    if (num < 2) {
        return -1;
    }

    unsigned int counter = 0;
    unsigned int num_copy = num;

    do {
        if (num_copy % 2 == 0) {
            num_copy = num_copy / 2;
        } else {
            num_copy = num_copy * 3 + 1;
        }

        counter++;
    } while (num_copy != 1);

    return counter;
}
