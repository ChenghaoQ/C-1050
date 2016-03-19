#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 6
#define COL 4
#define MAX 25
void initialSeats(char flight[][COL],int count);
void displayMenu();
void printFlightMap(char flight[][COL]);
int loginMatch(char string1[],char string2[]);
int getTotalRevenue(char f1[][COL],char f2[][COL],char f3[][COL]);
void flightMenu();
void seatReservation(char flight[][COL]);
void printMessage(char name[],char num[]);
int costMatrix[ROW][COL]={{300,200,200,300},
	 		  {300,200,200,300},
	      		  {300,200,200,300},
	   		  {300,200,200,300},
	    		  {300,200,200,300},
			  {300,200,200,300}};	   
int main(void)
{
	srand(time(NULL));
	int option,flight_choice;
	char flight_1[ROW][COL],flight_2[ROW][COL],flight_3[ROW][COL];
	char input_password[MAX],input_pawprint[MAX],name[MAX],flight_number[MAX];
	char adminPawprint[]="slbyb9";
	char adminPassword[]="cmp_sc1050";
	
	initialSeats(flight_1,rand()%30);
	initialSeats(flight_2,rand()%30);
	initialSeats(flight_3,rand()%30);
		do{
			displayMenu();
			printf("Choose an option: ");
			scanf("%d",&option);
			if (option != 1 && option != 2 && option != 3)
				printf("\nWrong option! Choose a right option again\n");
		}while (option !=1 && option != 2 && option != 3);
			
		switch(option){
			
			case 1:	
				do{
				printf("\nAdmin Pawprint: ");
				scanf("%s",input_pawprint);
				printf("\nAdmin Password: ");
				scanf("%s",input_password);
				if (loginMatch(adminPawprint,input_pawprint) ==0 || loginMatch(adminPassword,input_password)==0){
					printf("\nInvalid Pawpint and Password combination\n");
				}
				}while (loginMatch(adminPawprint,input_pawprint) ==0 || loginMatch(adminPassword,input_password)==0);
				printf("\nPrinting the Flight Map of flight Columbia to Miami...\n");
				printFlightMap(flight_1);
				printf("\n\nPrinting the Flight Map of flight Columbia to Nashville...\n");
				printFlightMap(flight_2);
				printf("\nPrinting the Flight Map of flight Columbia to Las Vegas...\n");
				printf("\nThe total earning from all the flights: %d \n\n ",getTotalRevenue(flight_1,flight_2,flight_3));
				break;
			case 2:
				do{
					flightMenu();
					printf("\nChooses a flight: ");
					scanf("%d",&flight_choice);
				}while(flight_choice<1 || flight_choice>3);
				printf("\nEnter your first name: ");
				scanf("%s",name);
				if (flight_choice == 1){
					flight_number[MAX]='M','I','A','1','0','5','0','\0';
					seatReservation(flight_1); 
				}
				else if(flight_choice ==2){
					flight_number[MAX]='B','N','A','1','0','5','0','\0';
					seatReservation(flight_2); 
				}

				else{
					flight_number[MAX]='L','A','S','1','0','5','0','\0';
					seatReservation(flight_3); 
				}
				printf("is this your name? %s\n",name);

				printf("\n\nCongrats %s, your flight %s is booked, Your e-ticket number is: ",name,flight_number);
				printMessage(name,flight_number);
				break;


			case 3:
				printf("\nTerminating the program ...\nThank you for using Je's Airline Booking System.") ;
				break;
		}
	return 0;
}

void initialSeats(char flight[][COL],int count)
{
	int i,j;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			flight[i][j]= 'O';
		}
	}
	int row=rand()%ROW;
	int col=rand()%COL;
	for(i=0;i<count;i++){
		flight[row][col]='X';
	}

}	
void displayMenu()
{
	printf("********** WELCOME TO JOE'S AIRLINE BOOKING SYSTEM **********\n");
	printf("\n 1.) Admin Log-in\n 2.)Reserve a seat\n 3.) Exit\n");
}
void printFlightMap(char flight[][COL])
{	int i,j;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			printf("%c ",flight[i][j]);
		}
		printf("\n");
	}
}
int loginMatch(char string1[],char string2[])
{	int i=0;
	for(i=0;i<MAX;i++){
		if (string1[i] == '\0' && string2[i] == '\0')
			return 1;
		else if(string1[i] =='\0')
			return 0;
		else if(string2[i] =='\0')
			return 0;
		else 
			continue;
	}
	return 0;

}			
int getTotalRevenue(char f1[][COL],char f2[][COL],char f3[][COL])
{	
	int i,j,total=0;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			if(f1[i][j]=='X'){
				total+=costMatrix[i][j];
			}
		}
	}
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			if(f2[i][j]=='X'){
				total+=costMatrix[i][j];
			}
		}
	}	
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			if(f3[i][j]=='X'){
				total+=costMatrix[i][j];
			}
		}
	}	
	return total;
}

void flightMenu()
{
	printf("\n 1.)COU ---> MIA\n 2.) COU ----> BNA \n 3.) COU ----> LAS\n");
}
void seatReservation(char flight[][COL])
{
	printFlightMap(flight);

	int row,col;
	do{
		printf("\nEnter the row number:");
		scanf("%d",&row);
		while(row<0 || row>5){
			printf("\nSeat Rows are between 0 and 5.");
			printf("Try again.Which seat row do you want?:");
			scanf("%d",&row);}
		printf("Enter the column number: ");
		scanf("%d",&col);
		while(col<0 ||col >5){
			printf("\nSeat columns are between 0 and 3.");
			printf("Try again. Which seat column do you want?:");			
			scanf("%d",&col);
		}
		if(flight[row][col]=='X'){
			printf("Sorry!! Someone has reserved that seat. Please Try Again.");
		}
	
	}while(flight[row][col]=='X');

	if(flight[row][col] == 'O'){
		flight[row-1][col-1]='X';
	}
	printFlightMap(flight);
	printf("\nYour requested seat has been reserved");
}
void printMessage(char name[],char num[])
{
	int i=0,j=0,msg[MAX];
	while(i<MAX){
		if(name[j] && num[j] !='\0'){
			msg[i]=name[j];
			msg[i+1]=num[j];
			j++;
			i+=2;
		}
		else if(name[j] == '\0'){
			msg[i]=num[j];
			j++;
			i++;
		}	
		else if(num[j] =='\0'){
			msg[i]=name[j];
			j++;
			i++;
		}
	}
}
