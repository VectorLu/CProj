#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "snakeGame.h"

/* more easily to modify */
#define WELCOME "Welcome to the Snake game, please input:"
#define INPUT_TIP "Input error, please input integer number among 1-5!"

#define RECORD_SIZE 10
int gameRecord[RECORD_SIZE];

void menu(void);
void newGame(void);
void continueGame(void);
void chooseLevel(void);
void showRank(void);
void confirmExit(void);

int main()
{
    menu();
    return 0;
}

void menu(void)
{
    char menuOption = 1;
    //TODO locate the cursor

    printf("%s\n\n", WELCOME);
    printf(" 1 to start a new game\n\n");
    printf(" 2 to continue the game\n\n");
    printf(" 3 to choose a level you like(input 1, 2, 3)\n\n");
    printf(" 4 to check the ranking\n\n");
    printf(" 5 to exit the game\n\n");

    scanf ("%c", &menuOption);

    if (menuOption>'0' && menuOption<'6')
    {
        switch (menuOption)
        {
            case '1':
                newGame();
                break;
            case '2':
                continueGame();
                break;
            case '3':
                chooseLevel();
                break;
            case '4':
                showRank();
                break;
            case '5':
                confirmExit();
            default:
            //TODO locate the cursor
                printf("%s\n", INPUT_TIP);
        }
    }
    else
    {
        //TODO locate the cursor
        printf("%s\n", INPUT_TIP);
    }
}

void newGame(void)
{
    gameLevel = 0;
    snakeLength = 5;
    gameRecord[0] = gameLevel;
    gameRecord[1] = snakeLength;
    showGame(gameRecord);
}

void continueGame(void)
{
    //TODO implement of getRecord
    //TODO recordFile declare as a global file pointer
    gameRecord = getRecord(recordFile);
    showGame(gameRecord);
}

void chooseLevel(void)
{
    scanf("%d", &gameLevel);
    gameLevel--;
    snakeLength = 5 + 10*gameLevel;
    gameRecord[0] = gameLevel;
    gameRecord[1] = snakeLength;
    showGame(gameRecord);
}

//TODO showRank() and the file operations
void showRank(void)
{
    FILE *
}

void confirmExit(void)
{
    char input = n;
    printf("Input \"y\" to confirm to exit.\n");

    printf("Or input \"n\" to return the menu.\n");
    scanf("%c", &input);
    if (input == 'y')
    {
        exit(0);
    }
    else
    {
        menu();
    }
    return;
}
