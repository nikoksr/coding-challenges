/********************************************************************************
 * Title: Euclidian Algorithm
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Search the greatest common divisor of two numbers. Start by
 *  calculating the remainder(modulo) of the larger number divided by the smaller
 *  number. Repeat this step but divide the previous divisor by the previous
 *  remainder. Repeat this until the remainderor one of the remainders equals
 *  zero. In this case the previous remainder is the GCD. If the remainder
 *  equals one the GCD is 1.
 *******************************************************************************/

/* Includes */
#include <stdio.h>

/* Declarations */
void sort_bigger_smaller(unsigned int* num_one, unsigned int* num_two);
unsigned int euclidian_algo(unsigned int bigger, unsigned int smaller);
unsigned int greatest_common_divisor(const unsigned int num_one, const int unsigned num_two);

/* Main function */
int main() {
    const unsigned int num_one = 120;
    const unsigned int num_two = 180;
    const unsigned int gcd = greatest_common_divisor(num_one, num_two);

    printf("%d\n", gcd);
    return 0;
}

/* Definitions */
void sort_bigger_smaller(unsigned int* num_one, unsigned int* num_two) {
    if (*num_one < *num_two) {
        const unsigned int tmp = *num_one;
        *num_one = *num_two;
        *num_two = tmp;
    }
}

unsigned int euclidian_algo(unsigned int bigger, unsigned int smaller) {
    unsigned int remainder = bigger % smaller;
    unsigned int old_remainder;

    while (remainder > 1) {
        old_remainder = remainder;
        bigger = smaller;
        smaller = remainder;
        remainder = bigger % smaller;
    }

    if (remainder == 0) {
        return old_remainder;
    }

    return 1;
}

unsigned int greatest_common_divisor(const unsigned int num_one, const unsigned int num_two) {
    if (num_one == num_two) {
        return num_one;
    }

    unsigned int bigger = num_one;
    unsigned int smaller = num_two;
    sort_bigger_smaller(&bigger, &smaller);

    if (bigger % smaller == 0) {
        return smaller;
    }

    return euclidian_algo(bigger, smaller);
}
