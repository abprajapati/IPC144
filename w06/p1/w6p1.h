

// declaring macros

#define MAXIMUM_PRODUCTS 3
#define NUMBER_OF_GRAMS 64

// declaring structure

struct CatFoodInfo
{
	int skuNum;
	double priceOfProduct;
	int caloriesPerSer;
	double productWeight;
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

void displayCatFoodData(const int SKU, const double PRICE, const int CALORIESSERVE, const double WEIGHTLBS) ;

// function - 7 : entry point to logic

void start(void);
