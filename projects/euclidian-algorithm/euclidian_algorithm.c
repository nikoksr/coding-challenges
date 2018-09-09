/************************************************************
 * euclidian algorithm                                      *
 *                                                          *
 * -> finds the greatest common divisor of two numbers      *
 * -> find the remainder(modulo) of the larger number       * 
 *      divided by the smaller number                       *
 * -> repeat this step but divide the previous divisor by   *
 *      the previous remainder                              *
 * -> repeat this until the remainder becomes zero or one   *
 * -> if the remainder becomes zero, the previous remainder *
 *      is the GCD of the two numbers we started with       *
 * -> if the remainder becomes one, then one is the GCD     *
 ************************************************************/

/* includes */
#include <stdio.h>

/* declarations */
void sort_bigger_smaller(int *num_one, int *num_two);
int euclidian_algo(int bigger, int smaller);
int greatest_common_divisor(const int num_one, const int num_two);

/* main / wrapper function */
int main()
{
    const int num_one = 120;
    const int num_two = 180;

    int gcd = greatest_common_divisor(num_one, num_two);
    printf("%d\n", gcd);
    
    return 0;
}

/* definitions */
/* make num_one the bigger equal the bigger number
 * and num_two equal the smaller number
 * */
void sort_bigger_smaller(int *num_one, int *num_two)
{
    if(*num_one < *num_two)
    {
        int temp = *num_one;
        *num_one = *num_two;
        *num_two = temp;
    }
}

/* the actual algorithm */
int euclidian_algo(int bigger, int smaller)
{
    /* actual algorithm */
    int remainder = bigger % smaller;
    int old_remainder;

    while(remainder > 1)
    {
        old_remainder = remainder;
        bigger = smaller;
        smaller = remainder;
        remainder = bigger % smaller;
    }

    if(remainder == 0)
    {
        return old_remainder;
    }
    
    return 1;
}

/* using the euclidian algorithm to calculate the GCD of two numbers */
int greatest_common_divisor(const int num_one, const int num_two)
{
    /* catch case where numbers are equal */
    if(num_one == num_two)
    {
        return num_one;
    }

    /* sort values
     * variables used for better understanding
     * */
    int bigger = num_one;
    int smaller = num_two;

    sort_bigger_smaller(&bigger, &smaller);    
  
    /* catch case where the smaller value is the BCD */
    if(bigger % smaller == 0)
    {
        return smaller;
    }

    int result_euc = euclidian_algo(bigger, smaller);

    return result_euc;
}
