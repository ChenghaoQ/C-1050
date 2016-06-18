#include<stdio.h>
#include<stdlib.h>
typedef enum status
{
	PLAYING,
	WON,
	LOST
}Status;
typedef enum type
{
	MINE,
	NOTAMINE
}Type;
typedef enum cover
{
	COVERED,
	UNCOVERED
}Cover;
typedef struct square
{
	int surroundingMines;
	Cover C;
	Type T;
}Square;
typedef struct board
{
	int numRows;
	int numColumns;
	int numMines;
	int numRemaining;
	Status s;
	Square** squares;
}Board;

Board* randomizedBoard(int rows,int columns, int numMines);


