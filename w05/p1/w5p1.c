


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MINIMUM_LIVES 1
#define MAXIMUM_LIVES 10
#define MINIMUM_PATH_LENGTH 10
#define MAXIMUM_PATH_LENGTH 70
#define MULTIPLE_OF_PATH_LENGTH 5

struct PlayerInfo
{
	int numberOfLives;
	char playerSymbol;
	int numOfTreasures;
	int pastPosition[MAXIMUM_PATH_LENGTH];
};

struct GameInfo
{
	int numberOfMoves;
	int pathLength;
	int bombPlacement[MAXIMUM_PATH_LENGTH];
	int treasurePlacement[MAXIMUM_PATH_LENGTH];

};

int main(void)
{
	int i, j, maximumMoves, setLimit = 5, count = 1;

	struct PlayerInfo playerConfug = { 0,0,0,{0}};
	struct GameInfo gameConfug = { 0,0,{0},{0} };

	printf("================================\n");
	printf("         Treasure Hunt!\n");
	printf("================================\n\n");

	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &playerConfug.playerSymbol);

	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &playerConfug.numberOfLives);
        
		if (playerConfug.numberOfLives< MINIMUM_LIVES || playerConfug.numberOfLives> MAXIMUM_LIVES)
		{
			printf("     Must be between 1 and 10!\n");
		}
		else
		{
			count = 0;
			printf("Player configuration set-up is complete\n\n");
		}
	} while (count>0);

	printf("GAME Configuration\n");
	printf("------------------\n");

	count = 1;
	do
	{
		printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE_OF_PATH_LENGTH, MINIMUM_PATH_LENGTH, MAXIMUM_PATH_LENGTH);
		scanf(" %d", &gameConfug.pathLength);
		if (gameConfug.pathLength > MINIMUM_PATH_LENGTH || gameConfug.pathLength< MAXIMUM_PATH_LENGTH)
		{
			if ((gameConfug.pathLength % MULTIPLE_OF_PATH_LENGTH) == 0)
			{
				count = 0;
			}
			else
			{
				printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE_OF_PATH_LENGTH, MINIMUM_PATH_LENGTH, MAXIMUM_PATH_LENGTH);
			}
		}
		else
		{
			printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE_OF_PATH_LENGTH, MINIMUM_PATH_LENGTH, MAXIMUM_PATH_LENGTH);
		}
		
	} while (count > 0);

	maximumMoves = (gameConfug.pathLength * 75) / 100;
	count = 1;
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gameConfug.numberOfMoves);

		if (gameConfug.numberOfMoves < playerConfug.numberOfLives || gameConfug.numberOfMoves > maximumMoves)
		{
			
			printf("    Value must be between %d and %d\n", playerConfug.numberOfLives, maximumMoves);
		}
		else
		{
			count = 0;
		}
	} while (count > 0);

	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of %d where a value\n", setLimit);
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameConfug.pathLength);
	for (i = 0; i < gameConfug.pathLength; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		for (j = i; j < setLimit; j++)
		{
			scanf("%d", &gameConfug.bombPlacement[j]);
		}
		setLimit += 5;
	}
        printf("BOMB placement set\n");


	printf("\nTREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameConfug.pathLength);
	setLimit = 5;
	for (i = 0; i < gameConfug.pathLength; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		for (j = i; j < setLimit; j++)
		{
			scanf("%d", &gameConfug.treasurePlacement[j]);
		}
		setLimit += 5;
	}
        printf("TREASURE placement set\n");
        printf("\nGAME configuration set-up is complete...\n");


	printf("\n------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", playerConfug.playerSymbol);
	printf("   Lives      : %d\n", playerConfug.numberOfLives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");

	printf("Game:\n");
	printf("   Path Length: %d\n", gameConfug.pathLength);
	
	printf("   Bombs      : ");
    for (i = 0; i < gameConfug.pathLength; i++)
	{
		printf("%d", gameConfug.bombPlacement[i]);
	}

	printf("\n   Treasure   : ");
	for(i=0;i< gameConfug.pathLength; i++)
	{
		printf("%d", gameConfug.treasurePlacement[i]);
	}

	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");

    return 0;
}