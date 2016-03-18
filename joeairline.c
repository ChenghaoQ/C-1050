#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 6
#define COL 4
#define MAX 25
void initialSeats(char flight[][COL],int count)
void displayMenu()
void printFlightMap(char flight[][COL])
int loginMatch(char string1[],char string2[])
int getTotalRevenue(char f1[][COL],char f2[][COL],char f3[][COL]);
void flightMenus()
void seatReservation(char flight[][COL]);
void printMessage(char name[],char num[]);

int main(void)
{
	srand(time(NULL));
	char fligh_1[ROW][COL],fligh_2[ROW][COL],fligh_3[ROW][COL],strings[];
	int cost Matrix[ROW][COL]={{300,200,200,300},
	 			   {300,200,200,300},
	    			   {300,200,200,300},
	   			   {300,200,200,300},
	    			   {300,200,200,300},
	     			   {300,200,200,300}}
	do{
		displayMenus()
		printf("Choose an option: ");
		scanf("%d",&option)
		if (option < 1 || option > 3);
			printf("\nWrong option! Choose a right option again\n");
	}while (option < 1 || option >3);
		
	switch(option){
		
		case 1:





		case 2:





		case 3:
			break;
}


void initialSeats(char flight[][COL],int count)
{
	int i,j;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			flight[i][j]= "O";
		}
	}
	int row=rand%ROW
	int col=rand%COL
	for(i=0;i<count;i++){
		flight[row][col]="X";
	}

}	
void displayMenu()
{
	printf("********** WELCOME TO JOE'S AIRLINE BOOKING SYSTEM **********\n");
	printf("\n1.) Admin Log-in\n 2.)Reserve a seat\n 3.) Exit\n")
}
void printFlightMap(char flight[][COL])
	int i,j;
	for(i=0;i<ROW;i++){
		for(j=0;i<COL;j++){
			printf("%2c ",flight[i][j]);
		}
		printf("\n");
	}
int loginMatch(char string1[],char string2[])
{	int i=0;
	for(i=0;i<MAX;i++){
		if (string1[i] == "\0" && string2[i] == "\O"){
			return 1;
		}
		else if(string1[i] =="\O"){
			return 0;
		}
		else if(string2[i] =="\O"){
			return 0;
		}
		else if(string1[i] != string2[i]){
			return 0;
		}
	}	
}			
int getTotalRevenue(char f1[][COL],char f2[][COL],char f3[][COL]);
void flightMenus()
{
	pirntf("\n 1.)COU ---> MIA\n 2.) COU ----> BNA \n 3.) COU ----> LAS\n");
}
void seatReservation(char flight[][COL]);
	printFlightMap()
	int row,col;
	do{
		printf("\nEnter the row number:");
		scanf("%d",&row);
		while(row<0 || row>5){
			printf("\nSeat Rows are between 0 and 5.");
			printf("Try again.Which seat row do you want?:");
			scanf("%d",&row);
		printf("Enter the column number: ");
		while(col<0 ||col >5){
			printf("\nSeat columns are between 0 and 3.");
			printf("Try again. Which seat column do you want?:");			
			scanf("%d",&col);
		scanf("%d",&col);
		if(flight[row][col]=="X"){
			printf("Sorry!! Someone has reserved that seat. Please Try Again.");
		}
	}while(flight[row][col]=="X");

	if(flight[row][col] == "O"){
		flight[row][col]="X";
	}
	printFlightMap()
	printf("\nYour requested seat has been reserved");
void printMessage(char name[],char num[]);

