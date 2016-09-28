#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "snakeGame.h"

/* more easily to modify */
#define WELCOME "Welcome to the Snake game, please input:"
#define INPUT_TIP "Input error, please input integer number among 1-5!"

void menu(void);

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
