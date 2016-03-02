//Name: Chenghao Qian
//Pawprint: cqnp3
//Lab code:Drive into the exit of highway

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
void displayMenu(void);
int generateNumber(void);
int errorCheck(int);
int checkGuess(int,int);
void printResult(int, int);
void loadArray(int, int array[]);
void printArray(int,int array[]);
int main(void)
{	
	srand(time(NULL));
	int choice,answer;
	int again,times=0,correct=0;
	float rate;
	do{
	answer = generateNumber();
		
	displayMenu();
	printf("\nEnter your guess: ");
	scanf("%d",&choice);
	while (errorCheck(choice)==0){
		printf("Hey enter only 0 or 1 as your guess: ");
		scanf("%d",&choice);
		errorCheck(choice);
		}
	if (checkGuess(choice,answer)==1){
		correct++;
	}
	printResult(checkGuess(choice,answer),answer);
	times++;
	printf("Do you want to play again? Hit 1 to continue 0 to exit: ");
	scanf("%d",&again);}while(again == 1);
		
	rate = ((float)times/(float)correct)*100;
	printf("\nYour played the game %d times and got the correct guess %d times\n",times,correct);
	printf("Your accuracy is %.2f %%",rate);
	printf("\nThank you for playing the game!\n");
	
	printf("\n***BOUNUS***\n");
	int array[SIZE];
	int num;
	printf("\nEnter a number:");
	scanf("%d",&num);
	loadArray(num,array);
	printf("\nYour First Array full of random number is :");
	printArray(num,array);
	printf("\n");
	return 0;

}
int generateNumber(void)
{
	return rand()%2;
}

void displayMenu(void)
{
	printf("PLEASE MAKE A GUESS\n\n0 ---->HEADS\n\n1 ----> TAILS\n\nHit 0 or 1\n");
}	

int errorCheck(int option)
{
	if (option ==1 || option == 0) 
		return 1;
	else
		return 0;
}
int checkGuess(int guess, int answer)
{
	if (guess == answer){
		return 1;
	}
	else
		return 0;
}
void printResult(int result,int answer)
{	

	if (result == 1 && answer == 1) {
		printf("Your guess was a HEAD and it was correct, it matched!!\nCongrats!\n");
	}
	else if (result ==1 && answer == 0){
		printf("Your guess was a TAIL and it was correct, it matched!!\nCongrats!\n");
	}
	else if (result ==0 && answer == 1){
		printf("Your guess was a TAIL and it did not match!\nTough Luck!!\n");
	}
	else {
		printf("Your guess was a HEAD and it dit not match!\nTough Luck!!\n");
	}
}	
	
void  loadArray(int num,int array[])

{	int i;
	for(i = 0;i<num;i++){
		array[i] = rand()%10;
		}
}
void printArray(int num,int array[])
{	int j;
	for (j = 0;j<num;j++){
		printf("%d ",array[j]);
		}
}


































