

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	const int MIN_ITEMS_FORECAST = 1, MAX_ITEMS_FORECAST = 10;
	const double MIN_INCOME = 500.00, MAX_INCOME = 400000.00, MIN_ITEM_PRICE = 100.00;
	char financeOption[10];
	int numItemsForecast, i, priority[10], MIN_PRIORITY_RANGE = 1, MAX_PRIORITY_RANGE = 3, count = 1;
	double netIncome, itemCost[10], totalCost = 0;
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	
	

	do
	{
		printf("\nEnter your monthly NET income: $");
		scanf(" %lf", &netIncome);
		if (netIncome >= MIN_INCOME)
		{
			if (netIncome > MAX_INCOME)
			{
				printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAX_INCOME);
				
			}
			else
			{
				do
				{
					printf("\nHow many wish list items do you want to forecast?: ");
					scanf(" %d", &numItemsForecast);

					if (numItemsForecast <= MAX_ITEMS_FORECAST)
					{
						if (numItemsForecast < MIN_ITEMS_FORECAST)
						{
							printf("ERROR: List is restricted to between %d and %d items.\n", MIN_ITEMS_FORECAST, MAX_ITEMS_FORECAST);
						}
						else
						{
							count = 0;
						}
					}
					else
					{
						printf("ERROR: List is restricted to between %d and %d items.\n", MIN_ITEMS_FORECAST, MAX_ITEMS_FORECAST);
					}

				} while (count > 0);
			}
		}
		else
		{
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN_INCOME);
			
		}
    } while (count > 0);

	
	for (i = 0; i < numItemsForecast; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);

		count = 1;
		do
		{
			printf("   Item cost: $");
			scanf(" %lf", &itemCost[i]);

			if (itemCost[i] < MIN_ITEM_PRICE)
			{
				printf("      ERROR: Cost must be at least $%.2lf\n", MIN_ITEM_PRICE);
			}
			else
			{
				count = 0;
			}

		} while (count > 0);
		count = 1;

	
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf(" %d", &priority[i]);

			if (priority[i] <= MAX_PRIORITY_RANGE)
			{
				if (priority[i] < MIN_PRIORITY_RANGE)
				{
					printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY_RANGE, MAX_PRIORITY_RANGE);
				}
				else
				{
					count = 0;
				}
			}
			else
			{
				printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY_RANGE, MAX_PRIORITY_RANGE);
			}

		} while (count > 0);
		count = 1;

		
		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &financeOption[i]);

			if (financeOption[i] != 'y')
			{
				if (financeOption[i] == 'n')
				{
					count = 0;
				}
				else
				{
					printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
				}
			}
			else
			{
				count = 0;
			}

		} while (count > 0);
		
	}


	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (i = 0; i < numItemsForecast; i++)
	{
		printf("  %d      %d        %c    %11.2lf\n", i + 1, priority[i], financeOption[i], itemCost[i]);
		totalCost += itemCost[i];
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", totalCost);
	printf("\n");
	printf("Best of luck in all your future endeavours!\n");
	return 0;
}