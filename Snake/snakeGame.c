#include "snakeGame.h"

/*
** The cmd interface x = y/2
** need to adjust.
*/
void gotoxy(int x, int y)
{
    COORD position;
    position.X = 2*x;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
    return;
}

void newGame(void)
{
    //TODO initialize a snake
    Snake newSnake = {

    };
    Snake *pNewSnake = &newSnake;
    showGame(pNewSnake);
}

void continueGame(void)
{
    //TODO implement of getRecord
    //TODO recordFile declare as a global file pointer
    FILE *snakeRecord = fopen("snakeRecord.log", "r");
    if (snakeRecord == NULL)
    {
        // TODO locate the cursor
        printf("There is no record.\n");
        printf("Input n to begin a new game, or q to go back to the menu.");
        char choose;
        scanf("%c", &choose);
        switch (choose)
        {
            case 'n':
                newGame();
                break;
            case 'q':
                menu();
                break;
            default:
                menu();
        }
    }
    else
    {
        Snake *ctnSnake = getRecord(snakeRecord);
        showGame(ctnSnake);
    }
    return;
}

void chooseLevel(void)
{
    Snake *chooseSnake;
    int gameLevel = 1;
    scanf("%d", &gameLevel);
    chooseSnake.level = gameLevel - 1;
    chooseSnake.length = 5 + 10*gameLevel;
    showGame(chooseSnake);
}

//TODO showRank() and the file operations
//TODO C - relative path
void showRank(void)
{
    //TODO FILE *readFile = fopen("./")
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
}
