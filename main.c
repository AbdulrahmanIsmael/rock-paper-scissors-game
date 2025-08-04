#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int getComputerRandomChoice();
int getPlayerChoice();
int findWinner(int playerChoice, int computerChoice);

int main()
{
    printf("*** Welcome to Rock Paper Scissors Game V1.0 ***\n");

    // Get player name
    char playerName[30] = "";
    printf("What's your name? ");
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strlen(playerName) - 1] = '\0';

    // computer choice
    int computerChoice = getComputerRandomChoice();
    printf("Hello, %s - Game starts...\n", playerName);

    // player choice
    int playerChoice = getPlayerChoice();

    // who is winning
    findWinner(playerChoice, computerChoice);

    printf("Thank you for playing, see you soon!");
    return 0;
}

int getComputerRandomChoice()
{
    srand(time(NULL));
    int choice = (rand() % (3 - 1 + 1)) + 1;
    return choice;
}

int findWinner(int playerChoice, int computerChoice)
{
    if (computerChoice == 1)
    {
        printf("Computer Choice: 1. Rock\n");
    }
    else if (computerChoice == 2)
    {
        printf("Computer Choice: 2. Paper\n");
    }
    else if (computerChoice == 3)
    {
        printf("Computer Choice: 3. Scissors\n");
    }

    if (playerChoice == computerChoice)
    {
        printf("It's a TIE!\n");
        return 0;
    }

    if (playerChoice == 1)
    {
        switch (computerChoice)
        {
        case 2:
            printf("Computer Won! - Game Over\n");
            return 2;
            break;
        case 3:
            printf("You Won - Amazing!\n");
            return 1;
            break;
        default:
            printf("There must be something wrong, please try again\n");
            return 3;
        }
    }
    else if (playerChoice == 2)
    {
        switch (computerChoice)
        {
        case 1:
            printf("You Won - Amazing!\n");
            return 1;
            break;
        case 3:
            printf("Computer Won - Game Over\n");
            return 2;
            break;
        default:
            printf("There must be something wrong, please try again\n");
            return 3;
        }
    }
    else if (playerChoice == 3)
    {
        switch (computerChoice)
        {
        case 1:
            printf("Computer Won! - Game Over\n");
            return 2;
            break;
        case 2:
            printf("You Won - Amazing!\n");
            return 1;
            break;
        default:
            printf("There must be something wrong, please try again\n");
            return 3;
        }
    }
}

int getPlayerChoice()
{
    int playerChoice = 0;

    do
    {
        printf("What is your choice: \n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");

        printf("Your Choice (1 or 2 or 3): ");
        scanf("%d", &playerChoice);
    } while (playerChoice < 1 || playerChoice > 3);
    return playerChoice;
}