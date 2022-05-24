

#define _CRT_SECURE_NO_WARNINGS

// system library
#include <stdio.h>
// user library
#include "w6p1.h"


// Function - 1 : get the input of int type from the user and validate that input for positive and non-zero number.
//                return the int type number and also assign it to the pointer.

int getIntPositive(int* wholeNumber)

{

	int intNumber = 0;

	while (intNumber < 1)
	{
		scanf("%d", &intNumber);
		if (intNumber < 1) printf("ERROR: Enter a positive value: ");

	}
	if (wholeNumber != NULL)
	{
		*wholeNumber = intNumber;
	}

	return intNumber;
}

// function - 2 : get the input of double type from user and validate it for positive and non-zero number.
//                return the double type number and also assign it to the pointer.

double getDoublePositive(double* doubleFloatingNumber)
{

	double doubleNum = 0.0;

	while (doubleNum < 1.0)
	{

		scanf("%lf", &doubleNum);
		if (doubleNum < 1) printf("ERROR: Enter a positive value: ");

	}
	if (doubleFloatingNumber != NULL)
	{
		*doubleFloatingNumber = doubleNum;
	}

	return doubleNum;
}

// function - 3 : for opening massage

void openingMessage(const int numberOfProducts)
{

	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\nEnter the details for %d dry food bags of product data for analysis.\n", MAXIMUM_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n\n", NUMBER_OF_GRAMS);
}

// function - 4 : get the input from user for cat food product details which includes SKU, price, weight, calories.

struct CatFoodInfo getCatFoodInfo(const int info)
{

	struct CatFoodInfo catProductData = {0} ;

	int sku, calories;
	double price, weightlbs;

	printf("Cat Food Product #%d\n", info + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	catProductData.skuNum = getIntPositive(&sku);

	printf("PRICE         : $");
	catProductData.priceOfProduct = getDoublePositive(&price);

	printf("WEIGHT (LBS)  : ");
	catProductData.productWeight = getDoublePositive(&weightlbs);

	printf("CALORIES/SERV.: ");
	catProductData.caloriesPerSer = getIntPositive(&calories);
	printf("\n");

	return catProductData;
}

// function - 5 : display the table header

void displayCatFoodHeader(void)
{

	printf("SKU         $Price    Bag-lbs Cal/Serv");
	printf("\n------- ---------- ---------- --------\n");

}

// function - 6 : display a record(values) of cat food product data

void displayCatFoodData(const int SKU, const double PRICE, const int CALORIES_SERVE, const double WEIGHTLBS)
{

	printf("%07d %10.2lf %10.1lf %8d\n", SKU, PRICE, WEIGHTLBS, CALORIES_SERVE);
}

// function - 7 : entry point to logic

void start(void)
{

	struct CatFoodInfo catDataArray[MAXIMUM_PRODUCTS];
	int  i = 0;

	openingMessage(MAXIMUM_PRODUCTS);

	for (i = 0; i < MAXIMUM_PRODUCTS; i++)
	{

		catDataArray[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAXIMUM_PRODUCTS; i++)
	{

		displayCatFoodData(catDataArray[i].skuNum, catDataArray[i].priceOfProduct, catDataArray[i].caloriesPerSer, catDataArray[i].productWeight);
	}
}