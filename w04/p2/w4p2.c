

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define MAX_ITEMS_FORECAST 10
#define MIN_ITEMS_FORECAST 1

int main(void)
{
	
	const int MIN_PRIORITY_RANGE = 1, MAX_PRIORITY_RANGE = 3;
	const double MIN_INCOME = 500.00, MAX_INCOME = 400000.00, MIN_ITEM_PRICE = 100.00;
	char  financeOption[MAX_ITEMS_FORECAST] = {0};
	int numItemsForecast, i, priority[MAX_ITEMS_FORECAST] = {0};
	int  wayOfForecast, priorityFilter, count = 1, years, months;
	double netIncome, priority1Amount=0, priority2Amount=0, priority3Amount=0, totalCost = 0, 
		itemCost[MAX_ITEMS_FORECAST] = {0};
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
			    count = 0;
			}
		}
		else
		{
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN_INCOME);

		}
	} while (count > 0);

    
	count = 1;
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
	
	
	count = 1;
	do
	{
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");

		printf("Selection: ");
		scanf("%d", &wayOfForecast);

		if (wayOfForecast == 1)
		{
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalCost);
			
			years = (int)(totalCost / netIncome) / 12;
			months = (((int)(totalCost / netIncome) % 12) + 1);
			printf("Forecast: %d years, %d months\n", years, months);
		
			for (i = 0; count && i < numItemsForecast; i++)
			{
				if (financeOption[i] == 'y')
				{

					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
					printf("====================================================\n\n");
					count = 0;
				}
                                 else
                                 {
                                  printf("====================================================\n\n");

                                 }

			}
			count = 1;
		}
		
		else if (wayOfForecast == 2)
		{
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &priorityFilter);

			if (priorityFilter == 1)
			{
				printf("\n====================================================\n");
			    printf("Filter:   by priority (1)\n");
				
				for (i = 0; i < numItemsForecast; i++)
				{
					if (priority[i] == 1)
					{
						priority1Amount += itemCost[i];
	                }
				}
				printf("Amount:   $%.2lf\n", priority1Amount);
				years = (int)(priority1Amount / netIncome) / 12;
				months = (((int)(priority1Amount / netIncome) % 12) + 1);
				printf("Forecast: %d years, %d months\n", years, months);
				
				for (i = 0; count && i < numItemsForecast; i++)
				{
					if (priority[i] == 1)
					{
						if (financeOption[i] == 'y')
						{

							printf("NOTE: Financing options are available on some items.\n");
							printf("      You can likely reduce the estimated months.\n");
							printf("====================================================\n\n");
							count = 0;
						}
					}
				}
				count = 1;
				
			}
			else if (priorityFilter == 2)
			{
				printf("\n====================================================\n");
				printf("Filter:   by priority (2)\n");
				
				for (i = 0; i < numItemsForecast; i++)
				{
					if (priority[i] == 2)
					{
						priority2Amount += itemCost[i];
					}
				}
				printf("Amount:   $%.2lf\n", priority2Amount);
				years = (int)(priority2Amount / netIncome) / 12;
				months = (((int)(priority2Amount / netIncome) % 12) + 1);
				printf("Forecast: %d years, %d months\n", years, months);
				
				for (i = 0; count && i < numItemsForecast; i++)
				{
					if (priority[i] == 2)
					{
						if (financeOption[i] == 'y')
						{

							printf("NOTE: Financing options are available on some items.\n");
							printf("      You can likely reduce the estimated months.\n");
							printf("====================================================\n\n");
							count = 0;
						}
                                               else
                                               {
                                                  printf("====================================================\n\n");

                                               }
					}
				}
				count = 1;
				
			}
			else if (priorityFilter == 3)
			{
				printf("\n====================================================\n");
				printf("Filter:   by priority (3)\n");
				
				for (i = 0; i < numItemsForecast; i++)
				{
					if (priority[i] == 3)
					{
						priority3Amount += itemCost[i];
					}
				}
				printf("Amount:   $%.2lf\n", priority3Amount);
				
				years = (int)(priority3Amount / netIncome) / 12;
				months = (((int)(priority3Amount / netIncome) % 12) + 1);
				printf("Forecast: %d years, %d months\n", years, months);
				
				for (i = 0; count && i < numItemsForecast; i++)
				{
					if (priority[i] == 3)
					{
						if (financeOption[i] == 'y')
						{

							printf("NOTE: Financing options are available on some items.\n");
							printf("      You can likely reduce the estimated months.\n");
							printf("====================================================\n\n");
							count = 0;
						}
                                                 else
                                               {
                                                  printf("====================================================\n\n");

                                               }

					}
				}
				count = 1;
			}
		}
		else if (wayOfForecast == 0)
		{
			printf("\nBest of luck in all your future endeavours!\n");
			count = 0;
		}
		else
		{
			printf("\nERROR: Invalid menu selection.\n\n");
		}
	} while (count > 0);
	return 0;
}