

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
int main(void)
{
	const int JAN = 1, DEC = 12;
	int year, month, count = 1;
	printf("General Well-being Log\n");
	printf("======================\n");
	while (count>0)
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d", &year);
		scanf("%d", &month);

		if (year >= MIN_YEAR && year <= MAX_YEAR)
		{
			if (month >= JAN && month <= DEC)
			{
				printf("\n*** Log date set! ***\n\n");
				count = 0;
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
		

	}
	switch (month)
	{
	case 1:printf("Log starting date: %d-JAN-01\n",year);
		break;
	case 2:printf("Log starting date: %d-FEB-01\n", year);
		break;
	case 3:printf("Log starting date: %d-MAR-01\n", year);
		break;
	case 4:printf("Log starting date: %d-APR-01\n", year);
		break;
	case 5:printf("Log starting date: %d-MAY-01\n", year);
		break;
	case 6:printf("Log starting date: %d-JUN-01\n", year);
		break;
	case 7:printf("Log starting date: %d-JUL-01\n", year);
		break;
	case 8:printf("Log starting date: %d-AUG-01\n", year);
		break;
	case 9:printf("Log starting date: %d-SEP-01\n", year);
		break;
	case 10:printf("Log starting date: %d-OCT-01\n", year);
		break;
	case 11:printf("Log starting date: %d-NOV-01\n", year);
		break;
	case 12:printf("Log starting date: %d-DEC-01\n", year);
		break;
	}
	return 0;
}
