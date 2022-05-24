

#define _CRT_SECURE_NO_WARNINGS

// system library
#include <stdio.h>
// user library
#include "w6p2.h"


// Function - 1 : get the input of int type from the user and validate that input for positive and non-zero number.
//                return the int type number and also assign it to the pointer.

int getIntPositive(int* wholeNumber)

{

	int intNumber = 0;

	do
	{
		scanf("%d", &intNumber);
		if (intNumber < 1) printf("ERROR: Enter a positive value: ");

	} while (intNumber < 1);
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

	do
	{

		scanf("%lf", &doubleNum);
		if (doubleNum < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (doubleNum < 1.0);
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
	//struct CatFoodInfo getCatFoodInfo(int*skuNum, double*priceOfProduct, double*productWeight, int*caloriesPerSer, const int info)
{

	struct CatFoodInfo catProductData = { 0 };

	int sku, calories;
	double price, weightlbs;

	printf("Cat Food Product #%d\n", info + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	catProductData.skuNum = getIntPositive(&sku);
	//*skuNum = getIntPositive(NULL);

	printf("PRICE         : $");
	catProductData.priceOfProduct = getDoublePositive(&price);
	//*priceOfProduct = getDoublePositive(NULL);


	printf("WEIGHT (LBS)  : ");
	catProductData.productWeight = getDoublePositive(&weightlbs);
	//*productWeight = getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	catProductData.caloriesPerSer = getIntPositive(&calories);
	//*caloriesPerSer = getIntPositive(NULL);
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


// function - 8 : to convert weight in pounds to weight in kg

double convertLbsKg(const double* weightLbs, double* weightKg)
{
	
	double i;
	i = *weightLbs / KG_IN_LBS;
	if (weightKg != NULL)
	{
		*weightKg = i;
	}
	return i ;
}

// function - 9 : to convert weight in pounds to weight in grams

int convertLbsG(const double* weightLbs, int* weightGram)
{

	int j;
	j = convertLbsKg(weightLbs, 0) * 1000;
	if (weightGram != NULL)
	{
		*weightGram = j;
	}
	return j ;
}

// function - 10 : to convert from weight in pound to weight in kg and gram

void convertLbs(const double* convertLbs, double* weightKg, int* weightGram)
{

	convertLbsKg(convertLbs, weightKg);
    convertLbsG(convertLbs, weightGram);
}

// function - 11 : to calculate the number of serving 

double calculateServings(const int servingSize, const int totalGram, double* calculatedResult)
{

	double i;
	i = (double)totalGram / (double)servingSize;

	if (calculatedResult != NULL)
	{
		*calculatedResult = i;
	}
	return i ;
}

// function - 12 : to calculate the cost per serving

double calculateCostPerServing(const double* price, const double* result, double* resultcost)
{

	double expense = 0;
	expense = *price / *result;

	if (resultcost != NULL)
	{
		*resultcost = expense;
	}
	return expense;
}

// function - 13 : to calculate cost per calorie

double calculateCostPerCal(const double* priceOfProduct, const double* totalCalories, double* calculatedResult)
{
	double expense = 0;
	expense = *priceOfProduct / *totalCalories;

	if (calculatedResult != NULL)
	{
		*calculatedResult = expense;
	}
	return expense;
}

// function - 14 : Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo getCatFoodInfo)
{

	struct ReportData enteredData;
	double calories;

	enteredData.skuNum = getCatFoodInfo.skuNum;
	enteredData.priceOfProduct = getCatFoodInfo.priceOfProduct;
	enteredData.productWeight = getCatFoodInfo.productWeight;
	enteredData.caloriesPerSer = getCatFoodInfo.caloriesPerSer;
	enteredData.weightKg = convertLbsKg(&getCatFoodInfo.productWeight, &enteredData.weightKg);
	enteredData.weightGram = convertLbsG(&getCatFoodInfo.productWeight, &enteredData.weightGram);
	enteredData.totalServ = calculateServings(NUMBER_OF_GRAMS, enteredData.weightGram, &enteredData.totalServ);
	enteredData.costPerServ = calculateCostPerServing(&enteredData.priceOfProduct, &enteredData.totalServ, &enteredData.costPerServ);
	calories = enteredData.caloriesPerSer * enteredData.totalServ;
	enteredData.caloriesPerServ = calculateCostPerCal(&enteredData.priceOfProduct, &calories, &enteredData.caloriesPerServ);

	return enteredData;
}

// function - 15 : to display the header and the formatted table for the analysis results

void displayReportHeader(void)
{

	printf("\nAnalysis Report (Note: Serving = %dg", NUMBER_OF_GRAMS);
	printf("\n---------------\n");

	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// function - 16 : to display the data or values in the formatted table

void displayReportData(const struct ReportData enteredData, const int cheap)
{

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", enteredData.skuNum, enteredData.priceOfProduct, enteredData.productWeight, enteredData.weightKg, enteredData.weightGram, enteredData.caloriesPerSer, enteredData.totalServ, enteredData.costPerServ, enteredData.caloriesPerServ);

}

// function - 17 : to display the final analysis recommandation massage

void displayFinalAnalysis(const struct CatFoodInfo  cheapperProducts)
{
	printf("\nFinal Analysis\n--------------");
	printf("\nBased on the comparison data, the PURRR-fect economical option is:\n");

	printf("SKU:%07d Price: $%.2lf\n", cheapperProducts.skuNum, cheapperProducts.priceOfProduct);
	printf("\nHappy shopping!\n");
}

// function - 7 : entry point to the logic

void start(void)
{
	struct CatFoodInfo catDataArray[MAXIMUM_PRODUCTS];
	int  i = 0, cheapProducts = 0;
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

	struct ReportData infoArray[MAXIMUM_PRODUCTS];
	displayReportHeader();

	for (i = 0; i < MAXIMUM_PRODUCTS; i++)
	{
		infoArray[i] = calculateReportData(catDataArray[i]);
		if (infoArray[i].costPerServ < infoArray[i - 1].costPerServ) cheapProducts = i;
	}

	int j;
	for (j = 0; j < MAXIMUM_PRODUCTS; j++)
	{
		
		struct ReportData min = { 0 };
		min = infoArray[j];
		displayReportData(min, cheapProducts);
		if (cheapProducts == j) printf(" ***");
		printf("\n");
	}

	displayFinalAnalysis(catDataArray[cheapProducts]);
}




