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
void printBoard(Board* board);
void printUncoveredBoard(Board* board);


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
	board=malloc(sizeof(Board));
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
			(*(*(board->squares+r)+c)).surroundingMines=-1;
			printf("\nA mine has been set");
			mines++;
		}
	}while(mines<numMines);

	do{
		r=rand()%rows;
		c=rand()%columns;
		if((*(*(board->squares+r)+c)).T==NOTAMINE)
		{
			countMines(board,r,c);
			printf("12312321321312321");
			break;
		}
	}while((*(*(board->squares+r)+c)).T==NOTAMINE);	
	//call countMines to set the surroundingMines value of !each! square
				


	return board;
}


void updateBoard(Board* board, int x, int y)
{
	int i,j;
	if((*(*(board->squares+x)+y)).surroundingMines==-1)
	{
		board->s=LOST;
		return;
	}
	else if ((*(*(board->squares+x)+y)).surroundingMines!=-1)
	{
		(*(*(board->squares+x)+y)).C=UNCOVERED;
		board->numRemaining--;
	}
	/*if ((*(*(board->squares+x)+y)).surroundingMines==0)
	{	
		for(i=-1;i<=1;i++)
		{
			for(j=-1;j<=-1;j++)
			{
				if((*(*(board->squares+x+i)+y+j)).surroundingMines!=-1)
				{
					updateBoard(board,x+i,y+j);
				}
			}
		}
	}*/

		


	if(board->numRemaining==0)
	{
		board->s=WON;
	}
}
int countMines(Board* squares,int x, int y)
{
	int i,j,mines=0;
	//check if in the field
	(*(*(squares->squares+x)+y)).surroundingMines=0;
	
	//if in the field
	for(i=-1;i<2;i++)
	{
		for(j=-1;j<2;j++)
		
		{
			if(x+i<0||x+i>squares->numColumns-1||y+j<0||y+j>squares->numRows-1)
			{
				printf("%d %d Over the boarder\nCurrent at %d %d\n\n",x+i,y+j,x,y);
				continue;
			}
			
			printf("%d %d In the border\nCurrent at %d %d\n\n",x,y,x+i,y+j);
			
			if((*(*(squares->squares+x+i)+y+j)).surroundingMines==-2)
			{
				printf("================Move to another=========");
				if(countMines(squares,x+i,y+j)==1)
				{
					
					mines++;
				}
			//	countMines(squares,x+i,j+y);
			}
			continue;
			if((*(*(squares->squares+x+i)+y+j)).surroundingMines==-1)
			{
				mines++;
			}
		}
	}

	printf("===================================================");	
	if((*(*(squares->squares+x)+y)).T==MINE)
	{
		(*(*(squares->squares+x)+y)).surroundingMines=-1;
		return 1;
	}
	else
	{
		(*(*(squares->squares+x)+y)).surroundingMines=mines;
		return 0;
	}

			
}
void freeBoard(Board* board)
{
	int i;
	for(i=0;i<board->numRows;i++)
	{
		free(*(board->squares+i));
	}
	free(board->squares);
	free(board);
}











void printBoard(Board* board)
{
	Square** squares = board->squares;

    int i, j;
    printf("\x1B[0m\n\n");
    printf("\x1B[0m\t   Columms:\n");

	printf("         ");
	for(i = 0; i < board->numColumns; i++)
	{
		printf("%d ", i);
	}
    printf("\n");
    for(i = 0; i < board->numRows; i++)
    {
        printf("\x1B[0m\nRow %d -> ", i);
        for(j = 0; j < board->numColumns; j++)
        {
            if(squares[i][j].C == COVERED)
            {
                printf("\x1B[0mx ");
            }
            else if (squares[i][j].surroundingMines == 0) 
            {
                printf("\x1B[32m%d ", squares[i][j].surroundingMines);
            } else {
                printf("\x1B[33m%d ", squares[i][j].surroundingMines);
            }
        }
    }
	printf("\n\n");
}

void printUncoveredBoard(Board* board)
{
	Square** squares = board->squares;

    int i, j;
    printf("\x1B[0m\n\n");
    printf("\x1B[0m\t   Columms:\n");
    printf("         ");
	for(i = 0; i < board->numColumns; i++)
	{
		printf("%d ", i);
	}
    printf("\n");
    for(i = 0; i < board->numRows; i++)
    {
        printf("\x1B[0m\nRow %d -> ", i);
        for(j = 0; j < board->numColumns; j++)
        {
            if(squares[i][j].T == MINE)
            {
                printf("\x1B[31mM ");
            }
            else if (squares[i][j].surroundingMines == 0) 
            {
                printf("\x1B[32m%d ", squares[i][j].surroundingMines);
            } else {
                printf("\x1B[33m%d ", squares[i][j].surroundingMines);
            }
        }
    }
	printf("\n\n");
}







