/************************************************
 * change return                                *
 *                                              *
 *  -> take in a price and the payed money      *
 *      and calculate the change                *
 *  -> additionally calculate how many of the   *
 *      different coins and banknotes you       *
 *      need to return
 ************************************************/

/* includes */
#include <math.h>
#include <stdio.h>

/* declarations */
float difference(const float value_one, const float value_two);
void change_return(const float price, float money_payed);

/* main / wrapper function */
int main() {
  /* take in price and the payed money and
   * calculate the change return
   * */
  float price, money_payed;

  printf("Enter a price(EUR): ");
  scanf("%f", &price);
  printf("Enter the money(EUR) you pay: ");
  scanf("%f", &money_payed);
  change_return(price, money_payed);
  return 0;
}

/* definitions */
/* calculate the rounded difference between two values */
float difference(const float value_one, const float value_two) {
  return roundf((value_one - value_two) * 100) / 100;
}

/* calculate the change return */
void change_return(const float price, float money_payed) {
  float diff = difference(money_payed, price);

  /* run until enough money was payed */
  while (diff < 0) {
    float additional_money = 0.0;

    printf("Sorry, you have to pay %5.2f Euros more.\n", (diff * -1));
    printf("Additional money(EUR): ");
    scanf("%f", &additional_money);

    money_payed += additional_money;
    diff = difference(money_payed, price);
  }

  /* EUR */
  const float money[] = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0,
                         1.0,   0.5,   0.2,   0.1,  0.05, 0.02, 0.01};

  const unsigned int amount_of_money_types = sizeof(money) / sizeof(money[0]);

  /* money to return */
  float return_money[amount_of_money_types];

  /* calculate the exact payback money
   * how many of every coin and banknote
   * */
  for (unsigned int i = 0; i < amount_of_money_types; i++) {
    return_money[i] = floorf(diff / money[i]);
    diff = difference(diff, (return_money[i] * money[i]));

    if (diff == 0.0) {
      break;
    }
  }

  /* print change return */
  printf("Here is your change: \n");

  for (unsigned int j = 0; j < amount_of_money_types; j++) {
    if (return_money[j] >= 1) {
      printf("%5.0f x %5.2f EUR\n", return_money[j], money[j]);
    }
  }

  printf("\nThank you very much.\n");
}
