/************************************************
 * factorial                                    *
 *                                              *
 *  -> calculate the factorial of a given       *
 *      number                                  *
 *  -> Example: 5! = 5 * 4 * 3 * 2 * 1 = 120    *
 *  -> 0! = 1 according to convention of        *
 *      an empty product                        *
 ************************************************/


/* includes */
#include <stdio.h>


/* declarations */
int factorial_non_recursive(int);
int factorial_recursive(int);
int factorial_pre_checking(int);


/* main / wrapper function */
int main()
{
    int number;
    
    printf("FACTORIAL\n\n"
            "Pleaser enter a number: ");
    scanf("%d", &number);
    printf("\nFactorial(recursive): %d\n"
            "Factorial(non-recursive): %d\n",
            factorial_recursive(number),
            factorial_non_recursive(number));

    return 0;
}


/* definitions */
/* calculating the factorial of a number using a 
 * non-recursive algorithm
 */
int factorial_non_recursive(int number)
{
    int result = factorial_pre_checking(number);

    if(result != number)
    {
        return result;
    }

    int product = 1;

    while(number > 0)
    {
        product = product * number;
        number = number - 1;
    }

    return product;
}


/* calculating the factorial of a number using a
 * recursive algorithm
 */
int factorial_recursive(int number)
{
    int result = factorial_pre_checking(number);

    if(result != number)
    {
        return result;
    }

    return (number * factorial_recursive(number - 1));
}


/* pre check the number to be factorialized 
 * -> if the number is smaller than 0, return -1 as
 *      a sign of an error
 * -> if the number is 0, return 1 - according to the convention of
 *      an empty product
 */
int factorial_pre_checking(int number)
{
    if(number < 0)
    {
        return -1;
    }

    if (number == 0)
    {
        return 1;
    }

    return number;
}
