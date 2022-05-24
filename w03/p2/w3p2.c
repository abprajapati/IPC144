


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3
int main(void)
{
	const int JAN = 1, DEC = 12, MinRating = 0.0, MaxRating = 5.0;
	int year, month, i, count = 0;
	double SumMorRating=0, SumEveRating=0, eve_rating, mor_rating;
	printf("General Well-being Log\n");
	printf("======================\n");
	

    do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d", &year);
		scanf("%d", &month);
	
		if (year >= MIN_YEAR && year <= MAX_YEAR)
		{ 
			if (month >= JAN && month <= DEC)
			{
				printf("\n*** Log date set! ***\n\n");
				count = 1;
			}
			else
				printf("   ERROR: Jan.(1) - Dec.(12)\n");

		}
		else if (year < MIN_YEAR || year > MAX_YEAR)
		{
			if (month < JAN || month > DEC)
			{
				printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
				
			}
			else
				printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}
	} while (count < 1);


	for (i = 0; i < LOG_DAYS; i++)
	{
		
	
		switch (month)
		{
		case 1:printf("%d-JAN-%02d\n", year,i+1);
			break;
		case 2:printf("%d-FEB-%02d\n", year,i+1);
			break;
		case 3:printf("%d-MAR-%02d\n", year, i+1);
			break;
		case 4:printf("%d-APR-%02d\n", year,i+1);
			break;
		case 5:printf("%d-MAY-%02d\n", year, i+1);
			break;
		case 6:printf("%d-JUN-%02d\n", year, i+1);
			break;
		case 7:printf("%d-JUL-%02d\n", year, i+1);
			break;
		case 8:printf("%d-AUG-%02d\n", year, i+1);
			break;
		case 9:printf("%d-SEP-%02d\n", year, i+1);
			break;
		case 10:printf("%d-OCT-%02d\n", year, i+1);
			break;
		case 11:printf("%d-NOV-%02d\n", year, i+1);
			break;
		case 12:printf("%d-DEC-%02d\n", year, i+1);
			break;
		}
		count = 1;
		do
			{
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &mor_rating);
				if (mor_rating > MaxRating || mor_rating < MinRating)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else
				{
					SumMorRating += mor_rating;
					do
					{
						printf("   Evening rating (0.0-5.0): ");
						scanf("%lf", &eve_rating);
						if (eve_rating > MaxRating || eve_rating < MinRating)
						{
							printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
						}
						else
						{
							SumEveRating += eve_rating;
							count = 0;
							printf("\n");
						}
					} while (count > 0);
				}
		} while (count > 0);
		
	}
	
	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n", SumMorRating);
	printf("Evening total rating: %.3lf\n", SumEveRating);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n\n", SumMorRating + SumEveRating);
	printf("Average morning rating:  %0.1lf\n", SumMorRating / LOG_DAYS);
	printf("Average evening rating:  %0.1lf\n", SumEveRating / LOG_DAYS);
	printf("----------------------------\n");
	printf("Average overall rating:  %.1lf", (SumMorRating + SumEveRating) / ((double)LOG_DAYS * 2.0));
	return 0;
}
