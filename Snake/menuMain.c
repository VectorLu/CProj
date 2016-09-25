#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

/* more easily to modify */
#define WELCOME "Welcome to the Snake game, please input:"
#define INPUT_TIP "Input error, please input integer number among 1-5!"


void showGame(int gameLevel, int snakeLength);
void confirmExit(void);
void menu(void);
void newGame(void);

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

int main()
{
    /*
    ** Created by Victoria Lu on 20160920
    ** According to the flowchart, code five significant functions.
    ** Give some user tips.
    */
    menu();

    return 0;
}

void menu(void)
{
    char menuOption = 1;
    //TODO locate the cursor

    printf("%s\n\n", WELCOME);
    /*
    ** just once, it is not necessary to use macro
    */
    printf(" 1 to start a new game\n\n");
    printf(" 2 to continue the game\n\n");
    printf(" 3 to choose a level you like\n\n");
    printf(" 4 to check the ranking\n\n");
    printf(" 5 to exit the game\n\n");

    scanf("%c", &menuOption);
    if (menuOption>0 && menuOption<4)
    {
        switch (menuOption)
        {
            case 1:
                newGame();
                break;
            case 2:
                continueGame();
                break;
            case 3:
                chooseLevel();
                break;

            /*
            ** INPUT_TIP appears not only once,
            ** using macro is a good option
            */
            default:
            //TODO locate the cursor
                printf("%s\n", INPUT_TIP);
        }
        //TODO display the game views and a series of judges
    }
    else if (menuOption == 4)
    {
        showRank();
    }
    else if (menuOption == 5)
    {
        confirmExit();
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
    showGame(gameLevel, snakeLength);
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
