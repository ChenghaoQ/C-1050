#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
void loadArray(int,int array[]);
void printArray(int,int array[]);
int checkError(int);

int main()
{
	srand(time(NULL));
	int num,array1[SIZE],array2[SIZE];
	printf("Enter the size of the input: \n");
	scanf("%d",&num);
	while (checkError(num)==0){
		printf("Invaild input enter the size of the input again: \n");
		scanf("%d",&num);
	}
	loadArray(num,array1);
	printf("\nInput array 1\n");
	printArray(num,array1);
	loadArray(num,array2);
	printf("\ninput array 2\n");
	printArray(num,array2);
	printf("\n");

	return 0;
	
	
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
int checkError(int size)
{
	if (size>=1 && size <= 100){
		return 1;
	}
	else{ 
		return 0;
	}
}
 
