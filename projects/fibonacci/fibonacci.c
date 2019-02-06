/********************************************************************************
 * Title: Fibonacci
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Each number is the sum of the two preceding ones.
 * Example: 0 + 1 = 1
 *          1 + 1 = 2
 *          1 + 2 = 3
 *          2 + 3 = 5
 *          3 + 5 = 8
 *          ...
 *******************************************************************************/

/* Includes */
#include <limits.h>
#include <stdio.h>

/* Declarations */
void fibonacci_factor_limiter(const unsigned int factor);
void fibonacci_number_limiter(const unsigned int num);

/* Main function */
int main() {
    const unsigned int num = 100;
    const unsigned int factor = 10;

    fibonacci_number_limiter(num);
    fibonacci_factor_limiter(factor);
    return 0;
}

/* Definitions */
void fibonacci_factor_limiter(const unsigned int factor) {
    unsigned int a = 0, b = 1, c = 0, counter = 1;
    printf("%6d : %6d\n", counter, a);

    while (counter < factor && (a + b) < INT_MAX) {
        c = a + b;
        b = a;
        a = c;
        counter++;
        printf("%6d : %6d\n", counter, c);
    }
}

void fibonacci_number_limiter(const unsigned int num) {
    unsigned int a = 0, b = 1, c = 0, counter = 1;
    printf("%6d : %6d\n", counter, a);

    while ((a + b) < num && (a + b) < INT_MAX) {
        c = a + b;
        b = a;
        a = c;
        counter++;
        printf("%6d : %6d\n", counter, c);
    }
}
