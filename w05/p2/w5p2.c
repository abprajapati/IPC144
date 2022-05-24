

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
	int i, j, maximumMoves, setLimit = 5, count = 1, upcomingMove = 0, info = 1, record = 1;
	int const MINIMUM_MOVES = 1;
	char presentMove[MAXIMUM_PATH_LENGTH] = { 0 };
	struct PlayerInfo playerConfug = { 0,0,0,{0} };
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
	} while (count > 0);

	printf("GAME Configuration\n");
	printf("------------------\n");

	count = 1;
	do
	{
		printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE_OF_PATH_LENGTH, MINIMUM_PATH_LENGTH, MAXIMUM_PATH_LENGTH);
		scanf(" %d", &gameConfug.pathLength);
		if (gameConfug.pathLength > MINIMUM_PATH_LENGTH || gameConfug.pathLength < MAXIMUM_PATH_LENGTH)
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
	for (i = 0; i < gameConfug.pathLength; i++)
	{
		printf("%d", gameConfug.treasurePlacement[i]);
	}

	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");

	count = 1;


	
for (i = 0; i < gameConfug.pathLength; i++)
{
	presentMove[i] = '-';
}

do
{
	record = 1;


	printf("\n  ");

	for (i = 0; i < gameConfug.pathLength; i++)
	{
		printf("%c", presentMove[i]);
	}

	printf("\n  ");

	for (i = 0; i < gameConfug.pathLength; i++)
	{

		if ((i + 1) % 10 != 0)
		{
			printf("|");
		}
		else
		{
			printf("%d", (i + 1) / 10);
		}
	}

	printf("\n  ");

	for (i = 0; i < gameConfug.pathLength; i++)
	{
		printf("%d", (i + 1) % 10);
	}
	printf("\n");


	printf("+---------------------------------------------------+");
	printf("\n  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d", playerConfug.numberOfLives, playerConfug.numOfTreasures, gameConfug.numberOfMoves);
	printf("\n+---------------------------------------------------+\n");

	if (playerConfug.numberOfLives == 0 || gameConfug.numberOfMoves == 0)
	{
		printf("\n##################");
		printf("\n#   Game over!   #\n");
		printf("##################\n");
		printf("\nYou should play again and try to beat your score!\n");
		info = 0;
		record = 0;

	}

	if (playerConfug.numberOfLives == 0 || gameConfug.numberOfMoves == 0)
	{
		count = 0;
	}

	while (info > 0)
	{
		printf("Next Move [%d-%d]: ", MINIMUM_MOVES, gameConfug.pathLength);
		scanf("%d", &upcomingMove);

		if (upcomingMove < MINIMUM_MOVES || upcomingMove > gameConfug.pathLength)
		{

			printf("  Out of Range!!!\n");
		}
		else
		{
			info = 0;
		}
	}
	info = 1;

	printf("\n");

	while (record > 0)
	{
		if (gameConfug.bombPlacement[upcomingMove - 1] == 1 && gameConfug.treasurePlacement[upcomingMove - 1] == 0)
		{
			presentMove[upcomingMove - 1] = '!';

			if (playerConfug.pastPosition[upcomingMove - 1] == 1)
			{
				printf("===============> Dope! You've been here before!\n\n");
				record = 0;
			}
			else
			{
				gameConfug.numberOfMoves -= 1;
				playerConfug.pastPosition[upcomingMove - 1] = 1;
				printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
				presentMove[upcomingMove - 1] = '!';
				playerConfug.numberOfLives -= 1;
				record = 0;
			}
		}
		else if (gameConfug.bombPlacement[upcomingMove - 1] == 1 && gameConfug.bombPlacement[upcomingMove - 1] == 1)
		{
			presentMove[upcomingMove - 1] = '&';

			if (playerConfug.pastPosition[upcomingMove - 1] == 1)
			{
				printf("===============> Dope! You've been here before!\n\n");
				record = 0;
			}
			else
			{
				gameConfug.numberOfMoves -= 1;
				playerConfug.pastPosition[upcomingMove - 1] = 1;
				printf("===============> [&] !!! BOOOOOM !!! [&]\n");
				printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
				presentMove[upcomingMove - 1] = '&';
				playerConfug.numberOfLives -= 1;
				playerConfug.numOfTreasures += 1;
				record = 0;
			}
		}
		else if (gameConfug.bombPlacement[upcomingMove - 1] == 0 && gameConfug.treasurePlacement[upcomingMove - 1] == 1)
		{
			presentMove[upcomingMove - 1] = '$';

			if (playerConfug.pastPosition[upcomingMove - 1] == 1)
			{
				printf("===============> Dope! You've been here before!\n\n");
				record = 0;
			}
			else
			{
				gameConfug.numberOfMoves -= 1;
				playerConfug.pastPosition[upcomingMove - 1] = 1;
				printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
				presentMove[upcomingMove - 1] = '$';
				playerConfug.numOfTreasures += 1;
				record = 0;
			}
		}
		else if (gameConfug.bombPlacement[upcomingMove - 1] == 0 && gameConfug.treasurePlacement[upcomingMove - 1] == 0)
		{
			presentMove[upcomingMove - 1] = '.';

			if (playerConfug.pastPosition[upcomingMove - 1] == 1)
			{
				printf("===============> Dope! You've been here before!\n\n");
				record = 0;
			}
			else
			{
				gameConfug.numberOfMoves -= 1;
				playerConfug.pastPosition[upcomingMove - 1] = 1;
				printf("===============> [.] ...Nothing found here... [.]\n\n");
				presentMove[upcomingMove - 1] = '.';
				record = 0;
			}
		}

	

	if (playerConfug.numberOfLives == 0 || gameConfug.numberOfMoves == 0)
	{
		printf("No more LIVES remaining!\n\n");
		info = 0;

		record = 0;

	}


	for (i = 0; i < gameConfug.pathLength; i++)
	{
		if (upcomingMove != i + 1)
		{
			printf(" ");
		}
		else
		{
			printf("  %c", playerConfug.playerSymbol);
		}
	}
	}
} while (count > 0);




return 0;
}