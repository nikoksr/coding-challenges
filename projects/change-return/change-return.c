/********************************************************************************
 * Title: Change-Return
 * Project: Coding Challenges
 * Author: Niko Köser
 * Description: Given a product price and the amount of money payed by the
 *  customer. Calculate the change money and calculate the optimal distribution
 *  of coins and banknotes you have to return.
 *******************************************************************************/

/* Includes */
#include <math.h>
#include <stdio.h>

/* Declarations */
float difference(const float value_one, const float value_two);
void change_return(const float price, float money_payed);

/* Main function */
int main() {
    float price = 45.99;
    float money_payed = 50.0;

    change_return(price, money_payed);
    return 0;
}

/* Definitions */
float difference(const float value_one, const float value_two) {
    return roundf((value_one - value_two) * 100) / 100;
}

void change_return(const float price, float money_payed) {
    float diff = difference(money_payed, price);

    /* Run until enough money was payed */
    while (diff < 0) {
        float additional_money = 0.0;

        printf("Sorry, you have to pay %5.2f more Euros.\n", (diff * -1));
        printf("Add money(EUR): ");
        scanf("%f", &additional_money);
        money_payed += additional_money;
        diff = difference(money_payed, price);
    }

    /* Available coins and banknotes */
    const float money[] = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0,
                           1.0,   0.5,   0.2,   0.1,  0.05, 0.02, 0.01};
    const unsigned int amount_of_money_types = sizeof(money) / sizeof(money[0]);

    /* Money to return */
    float return_money[amount_of_money_types];

    /* Calculate the distribution of money to return */
    for (unsigned int i = 0; i < amount_of_money_types; i++) {
        return_money[i] = floorf(diff / money[i]);
        diff = difference(diff, (return_money[i] * money[i]));

        if (diff == 0.0) {
            break;
        }
    }

    printf("Here is your change: \n");

    for (unsigned int j = 0; j < amount_of_money_types; j++) {
        if (return_money[j] >= 1) {
            printf("%5.0f x %5.2f EUR\n", return_money[j], money[j]);
        }
    }

    printf("\nThank you very much.\n");
}
