/********************************************************************************
 * Title: Armstrong Numbers
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Given is a three-digit number. An armstrong number itself is
 *  equal to the cubes of its digits.
 * Example: 371 = 3^3 + 7^3 + 1^3
 *******************************************************************************/

/* Includes */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declarations */
unsigned int is_armstrong_number(const unsigned int num);
void print_result(const unsigned int num, const unsigned int res);

/* Main function */
int main() {
    printf("ARMSTRONG NUMBER\n\n");

    const unsigned int num = 371;
    const unsigned int res = is_armstrong_number(num);

    print_result(num, res);
    return 0;
}

/* Definitions */
unsigned int is_armstrong_number(const unsigned int num) {
    if (num < 0) {
        return 2;
    }

    unsigned int n = num;
    unsigned int armstrong = 0;
    const unsigned int number_of_digits = floor(log10(n)) + 1;

    while (n > 0) {
        unsigned int digit = n % 10;
        n /= 10;
        armstrong += pow(digit, number_of_digits);
    }

    if (armstrong == num) {
        return 1;
    }

    return 0;
}

void print_result(const unsigned int num, const unsigned int res) {
    char res_text[24];

    switch (res) {
    case 0:
        strcpy(res_text, "false");
        break;
    case 1:
        strcpy(res_text, "true");
        break;
    case 2:
        strcpy(res_text, "Error: Value smaller 0.");
        break;
    default:
        strcpy(res_text, "Unknown error.");
        break;
    }

    printf("%d -> %s\n", num, res_text);
}
