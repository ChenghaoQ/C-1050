#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
void updateBoard(Board* board, int x, int y);
int countMines(Board* squares,int x, int y);
void freeBoard(Board* board);



int main(int argc,char **argv)
{
	srand(time(NULL));////////////////////////

	if(argc!=4)
	{
		printf("Correct usage: ./a.out <number of rows><number of columns><number of mines>\n");
		return -1;
	}

	Board* b =randomizedBoard(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));  //Board pointer b 

	while(b->s == PLAYING)
	{
		printBoard(b);
		printf("\nSelect a row: ");
		int r;
		scanf("%d",&r);
		while(r<0||r>b->numRows)
		{
			printf("Invalid entry. Please try again:");
			scanf("%d",&r);
		}
		printf("Select a column:");
		int c;
		scanf("%d",&c);
		while(c<0|| c > b->numColumns)
		{
			printf("Invalid entry. Try again:");
			scanf("%d",&c);
		}
		
		if(b->squares[r][c].C==UNCOVERED)
		{
			printf("\nThat square is already uncovered!\n");
		}
		else
		{
			updateBoard(b,r,c);
		}
	}

	if(b->s == WON)
		printf("\nYou won!Congrats!\n");
	else
		printf("\nYou hit a mine! Oh no!\n");

	printUncoveredBoard(b);

	freeBoard(b);


	return 0;
}




Board* randomizedBoard(int rows,int columns, int numMines)
{
	int mines=0,r,c,i,j;
	Board* board;
	//Initializing
	board->numRows=rows;
	board->numColumns=columns;
	board->numMines=numMines;
	board->numRemaining=numMines;
	board->s=PLAYING;

	//set up the squares
	board->squares=malloc(sizeof(*board->squares)*rows);//May have a problem here
	for(i=0;i<rows;i++)
	{
		*(board->squares+i)=malloc(sizeof(*(*(board->squares+j)))*columns);
		for(j=0;j<columns;j++)
		{
			//set the attribute to each square
			(*(*(board->squares+i)+j)).T=NOTAMINE; //== sqr[i][j].T=NOTAMINE
			(*(*(board->squares+i)+j)).C=COVERED;
			(*(*(board->squares+i)+j)).surroundingMines=-2;
		}

	}


	//set up the mines
	do{
		r=rand()%rows;
		c=rand()%columns;
		if((*(*(board->squares+r)+c)).T==NOTAMINE)
		{
			(*(*(board->squares+r)+c)).T=MINE;
			mines++;
		}
	}while(mines<numMines);
	
	//call countMines to set the surroundingMines value of !each! square
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			if((*(*(board->squares+i)+j)).T==NOTAMINE)
			{
				countMines(board,i,j);
			}
		}
	}

	return board;
}


void updateBoard(Board* board, int x, int y);
int countMines(Board* squares,int x, int y);
void freeBoard(Board* board);








