#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
#define MAX  100
int check_error(int);
void initialize_2Darray(int[][MAX],int);
void print_2Darray(int [][MAX],int);
int minimum(int[][MAX],int);
int check_index(int,int);

int main()
{
	srand(time(NULL));
	int size,array[SIZE][MAX],index;

	printf("Enter the size of the array:");
	scanf("%d",&size);
	while(check_error(size)==0){
		printf("\nInvalid input enter the size of the input again:");
		scanf("%d",&size);
	}
	initialize_2Darray(array,size);
	
	printf("\n\nInput array:\n");
	print_2Darray(array,size);
	printf("\n");
	printf("\nThe minimum number in this array is %d\n",minimum(array,size));
	do{
		printf("\nEnter the column 1-%d:",size);
		scanf("%d",&index);
		check_index(index,size);}
	while(check_index(index,size)==0);
		
	return 0;
}


int check_error(int size)
{
	if(size>=1 && size <=100){
		return 1;
	}
	else{
		return 0;
	}
}
void initialize_2Darray(int array[][MAX],int size)
{	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			array[i][j]=rand()%10;
		}
	}
}
int  minimum(int array[][MAX],int size)
{
	int i,j,min=10;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if (array[i][j]<min){
				min=array[i][j];
			}
		}
	}
	return min;
}
void print_2Darray(int array[][MAX],int size)
{	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%2d",array[i][j]);
		}
		printf("\n");
	}
}
int check_index(int index,int size)
{
	if (index>size || index<1){
		return 0;
	}
	else
		return 1;
}



