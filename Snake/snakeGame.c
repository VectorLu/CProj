#include "snakeGame.h"

void gotoxy(int x, int y)
{
    COORD position;
    position.X = 2*x;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),place);
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
