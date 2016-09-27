#ifndef _snakeGame_H_
#define _snakeGame_H_

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int *getRecord(FILE *recordFile);
void showGame(int *gameRecord);


typedef struct CoordinateTag{
    int x;
    int y;
} Coordinate;


/*
** Using array to implement snake is easy,
** but I wanna use linked list to practice
** the operations of this data structure
** and to implement a dynamic snake :)
*/
typedef struct SnakeXYTag{
    Coordinate coordinate;
    snakeXYTag *next;
} SnakeXY;
typedef struct SnakeTag{
    SnakeXY *head;
    SnakeXY *tail;
    int alive;
    int length;
    int level;  /*speed*/
    char name[20];
} Snake;

typedef struct RankTag{
    int ranking;
    /*
    ** Don't use char *, just use array,
    ** no need to malloc and free
    */
    char playerName[20];
    int scores;
} Rank;


#endif
