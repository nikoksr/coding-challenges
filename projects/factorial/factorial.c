/********************************************************************************
 * Title: Factorial
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Calculate the factorial of a given number n. The factorial is the
 *  product of all positive integers less than or equal to n.
 * Example: 5! = 5 * 4 * 3 * 2 * 1 = 120
 *******************************************************************************/

/* Includes */
#include <stdio.h>

/* Declarations */
unsigned int factorial_non_recursive(unsigned int num);
unsigned int factorial_recursive(unsigned int num);
unsigned int factorial_pre_checking(const unsigned int);

/* Main function */
int main() {
    printf("FACTORIAL\n\n");

    const unsigned int num = 10;

    printf(
        "\nFactorial(recursive): %d\n"
        "Factorial(non-recursive): %d\n",
        factorial_recursive(num), factorial_non_recursive(num));
    return 0;
}

/* Definitions */
unsigned int factorial_non_recursive(unsigned int num) {
    const unsigned int res = factorial_pre_checking(num);

    if (res != num) {
        return res;
    }

    unsigned int product = 1;

    while (num > 0) {
        product *= num;
        num--;
    }

    return product;
}

unsigned int factorial_recursive(unsigned int num) {
    const unsigned int res = factorial_pre_checking(num);

    if (res != num) {
        return res;
    }

    return (num * factorial_recursive(num - 1));
}

unsigned int factorial_pre_checking(const unsigned int num) {
    if (num < 0) {
        return -1;
    }

    if (num == 0) {
        return 1;
    }

    return num;
}
