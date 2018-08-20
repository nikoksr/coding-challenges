#include <stdio.h>
#include <limits.h>

/* menus */
void fibonacci_menu();
void fibonacci_factor_menu();
void fibonacci_number_menu();

/* fibonacci calculation */
void fibonacci_factor_limiter(int factor);
void fibonacci_number_limiter(int number);

/* wrapper function */
int main()
{
    fibonacci_menu(); 
    return 0;
}

/* menus */

/* fibonacci menu / main menu */
void fibonacci_menu()
{
    int input, valid_input;

    do
    {
        valid_input = 1;
    
        printf("Fibonacci Calculator\n\n");
        printf("[1] Fibonacci factor\n");
        printf("[2] Fibonacci number\n");
        printf("[3] Quit\n");
        printf("> ");
        scanf("%d", &input);

        switch (input) 
        {
            case 1:
                fibonacci_factor_menu();
                break;
            case 2:
                fibonacci_number_menu();
                break;
            case 3:
                break;
            default:
                valid_input = 0;
                break;
        }
    }
    while(valid_input != 1);
}

/* fibonacci factor menu / sub menu */
void fibonacci_factor_menu()
{
    int input, valid_input;

    do
    {
        valid_input = 1;

        printf("\nEnter a factor > 0: ");
        scanf("%d", &input);

        if(input < 0)
        {
            valid_input = 0;
            continue;
        }
    
        fibonacci_factor_limiter(input);
    }while(valid_input != 1);
}

/* fibonacci number menu / sub menu */
void fibonacci_number_menu()
{
    int input, valid_input;

    do
    {
        valid_input = 1;

        printf("\nEnter a number > 0: ");
        scanf("%d", &input);

        if(input < 0)
        {
            valid_input = 0;
            continue;
        }
    
        fibonacci_number_limiter(input);
    }while(valid_input != 1);
}

/* fibonacci calculations */
/* maximum factor */
void fibonacci_factor_limiter(int factor)
{
    int a = 0, b = 1, c = 0, counter = 1;
  
    printf("%6d : %6d\n", counter, a);

    while(counter < factor && (a + b) < INT_MAX)
    {
        c = a + b;
        b = a;
        a = c;
        counter = counter + 1;

        printf("%6d : %6d\n", counter, c);
    } 
}

/* maximum number */
void fibonacci_number_limiter(int number)
{
    int a = 0, b = 1, c = 0, counter = 1;
  
    printf("%6d : %6d\n", counter, a);

    while((a + b) < number && (a + b) < INT_MAX)
    {
        c = a + b;
        b = a;
        a = c;
        counter = counter + 1;

        printf("%6d : %6d\n", counter, c);
    } 
}
