

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
int main(void)
{
	double amountdollar, r1, r2, r3;
	int toonies_coin, loonies_coin, quarters_coin;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf",&amountdollar);
	printf("\n");
	toonies_coin = (int)(amountdollar) / 2;
	r1 = (amountdollar-((double)toonies_coin*2.00));
	printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies_coin, r1);
	loonies_coin = (int)(r1 / 1.00);
	r2 = r1 - (loonies_coin*1.00);
	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies_coin, r2);
	quarters_coin = (int)(r2 / 0.25);
	r3 = r2 - (quarters_coin * 0.25);
	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n\n", quarters_coin, r3);
	printf("Machine error! Thank you for letting me keep $%.2lf!\n", r3);
	return 0;
}
