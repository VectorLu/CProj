#ifndef _snakeGame_H_
#define  _snakeGame_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void showGame(int *gameRecord);
void confirmExit(void);

int *getRecord(FILE *recordFile);

/*
** use snakeXY()
*/
typedef struct snakeXY{
    int x;
    int y;
    struct snakeXY *next;
} snakeXY;

typedef struct rankRecord{
    int ranking;
    /*
    ** Don't use char *, just use array,
    ** no need to malloc and free
    */
    char playerName[20];
    int scores;
}

int snakeLength = 5;
int alive = 1;
int gameLevel = 0;

#endif
