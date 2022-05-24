

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main(void)
{
	int toonies_coin, loonies_coin, quarters_coin, dimes_coin, nickels_coin, pennies_coin, cent;
	int rem1, rem2, rem3, rem4, rem5, rem6;
	double dollar_amount, ser_fee, bal_dispense;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &dollar_amount);
	ser_fee = (5 * dollar_amount) / 100;
	printf("Service fee (5.0 percent): %.2lf\n", ser_fee);
	bal_dispense = dollar_amount - ser_fee;
	printf("Balance to dispense: $%.2lf\n\n", bal_dispense);
	cent = (int)((bal_dispense + 0.005) * 100);
	toonies_coin = cent / 200;
	rem1 = cent % 200;
	printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies_coin, (double)rem1 / 100.00);
	loonies_coin = rem1 / 100;
	rem2 = rem1 % 100;
	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies_coin, (double)rem2 / 100.00);
	quarters_coin = rem2 / 25;
	rem3 = rem2 % 25;
	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarters_coin, (double)rem3 / 100.00);
	dimes_coin = rem3 / 10;
	rem4 = rem3 % 10;
	printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", dimes_coin, (double)rem4 / 100.00);
	nickels_coin = rem4 / 5;
	rem5 = rem4 % 5;
	printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", nickels_coin, (double)rem5 / 100.00);
	pennies_coin = rem5 / 1;
	rem6 = rem5 % 1;
	printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n\n", pennies_coin, (double)rem6 / 100.00);
	printf("All coins dispensed!\n");
	return 0;
}
