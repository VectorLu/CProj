#ifndef _snakeGame_H_
#define _snakeGame_H_

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    Coordinate snakeCoordinate;
    snakeXYTag *next;
} SnakeXY;

/*
** The structure Snake describes all the attributes of the snake and
** stores all the information of
** the current game player.
** If you need add or delete some functions of the snake game,
** you can do it by modifying the structure Snake.
*/
typedef struct SnakeTag{
    SnakeXY *head;
    SnakeXY *tail;
    Coordinate direction;
    int alive;
    int length;
    int level;  /*speed*/
    char name[20];
} Snake;

typedef struct RankTag{
    char playerName[20];
    int ranking;
    int scores;
    /*
    ** Don't use char *, just use array,
    ** no need to malloc and free.
    */
} Rank;

/*
** To locate the cursor.
*/
void gotoxy(int x, int y);

/*
** Just to check if the snake ...
** Use const to ensure the Snake will
** not be modified.
*/
int eatItself(const Snake *snake);
int bashAgainstAWall(const Snake *snake);
/*
** To modify the alive, and to return alive.
*/
int isAlive(Snake *snake);
int saveRank(Snake *snake);

/*
** Just to check if the snake ...
** Use const to ensure the Snake will
** not be modified.
*/
int detonateAMine(const Snake *snake);
void halfSnake(Snake *snake);

int eatPoison(const Snake *snake);
void cutSnakeTail(Snake *snake);

/*
** TODO !Give the snake intelligence
** to avoid the danger
** and get the food.
*/
int eatWisdom(const Snake *snake);
void autoGo(Snake *snake);

int eatFood(const Snake *snake);
void addSnakeTail(Snake *snake);

int monitorKeyboard(Coordinate *direction);
void changeDirection(Snake *snake, const Coordinate *direction);

int saveSnake(Snake *snake);

void showSnake(const SnakeXY *head);

/* To update the info regularly. */
void updateGame(Snake *snake);

void showGame(const Snake *snake);

void newGame(void);
void continueGame(void);
void chooseLevel(void);
void showRank(void);
void confirmExit(void);

#endif
