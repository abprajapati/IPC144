

// declaring macros

#define MAXIMUM_PRODUCTS 3
#define NUMBER_OF_GRAMS 64
#define KG_IN_LBS 2.20462

// declaring structure

struct CatFoodInfo
{
	int skuNum;
	double priceOfProduct;
	int caloriesPerSer;
	double productWeight;
};
struct ReportData
{
	int skuNum;
	double  priceOfProduct;
	int  caloriesPerSer;
	double  productWeight;
	double weightKg;
	int weightGram;
	double totalServ;
	double costPerServ;
	double caloriesPerServ;

};


// declaring function prototypes

// function - 1 : get the input of int type from the user and validate that input for positive and non-zero number.
//                return the int type number and also assign it to the pointer.

int getIntPositive(int* wholeNumber);

// function - 2 : get the input of double type from user and validate it for positive and non-zero number.
//                return the double type number and also assign it to the pointer.

double getDoublePositive(double* doubleFloatingNumber);

// function - 3 : for opening massage

void openingMessage(const int numberOfproducts);

// function - 4 : get the input from user for cat food product details which includes SKU, price, weight, calories.

struct CatFoodInfo getCatFoodInfo(const int info);

// function - 5 : display the table header

void displayCatFoodHeader(void);

// function - 6 : display a record(values) of cat food product data

void displayCatFoodData(const int SKU, const double PRICE, const int CALORIESSERVE, const double WEIGHTLBS);

// function - 8 : to convert weight in pounds to weight in kg

double convertLbsKg(const double* weightLbs, double* weightKg);

// function - 9 : to convert weight in pounds to weight in grams

int convertLbsG(const double* weightLbs, int* weightGram);

// function - 10 : to convert from weight in pound to weight in kg and gram

void convertLbs(const double* convertLbs, double* weightKg, int* weightGram);

// function - 11 : to calculate the number of serving 

double calculateServings(const int servingSize, const int totalGram, double* calculatedResult);

// function - 12 : to calculate the cost per serving

double calculateCostPerServing(const double* priceOfProduct, const double* totalNumServ, double* calculatedResult);

// function - 13 : to calculate cost per calorie

double calculateCostPerCal(const double* priceOfProduct, const double* totalCalories, double* calculatedResult);

// function - 14 : Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo  getCatFoodInfo);

// function - 15 : to display the header and the formatted table for the analysis results

void displayReportHeader(void);

// function - 16 : to display the data or values in the formatted table

void displayReportData(const struct ReportData enteredData, const int cheap);

// function - 17 : to display the final analysis recommandation massage

void displayFinalAnalysis(const struct CatFoodInfo getCatFoodInfo);

// function - 7 : entry point to logic

void start(void);

