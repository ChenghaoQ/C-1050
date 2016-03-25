//Name : Chenghao Qian
//Pawprint:cqnp3
//Labcode:St. Patrick's Day
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

int check_error(int);
void initialize_2Darray(int array[][MAX],int);
void print_2Darray(int array[][MAX],int);
int check_index(int ,int);
int find_columnmax(int array[][MAX],int,int);
float calculate_columnaverage(int array[][MAX],int,int);
int countZero(int array[][MAX],int);
void addN(int array[][MAX],int);
int length(char s[]);
void copy(char s[],char s1[]);
void bonus(char s[],char s1[],char s2[]);
int main()
{
	srand(time(NULL));
	int array[MAX][MAX];
	char string[MAX]={'\0'},string1[MAX]={'\0'},string2[MAX]={'\0'},string3[MAX]={'\0'};
	int size,index;

	printf("Enter the size of the array: ");
	scanf("%d",&size);
	while(check_error(size) == 0){
		printf("\n\nOut of bounds, Please enter the size again : ");
		scanf("%d",&size);
	}	
	initialize_2Darray(array,size);
	printf("\nThe 2D array is: \n");
	print_2Darray(array,size);

	printf("Enter the column 1 - %d :",size);
	scanf("%d",&index);
	while(check_index(index,size)== 0){
		printf("Enter the column 1 -%d : ",size);
		scanf("%d",&index);
	}
		
	
	printf("\n\nThe largest number present in the column %d is %d\n",index,find_columnmax(array,index,size));
	printf("\n\nThe average of the numbers in the column %d is %.2f\n",index,calculate_columnaverage(array,index,size));
	printf("\n\nThe number of Zero's in the 2-D array is %d",countZero(array,size));
	printf("\n\nNew Matrix is :\n");
	addN(array,size);
	printf("\n\nEnter a string: \n");
	scanf("%s",string);
	printf("\nLength of the string %s is %d\n",string,length(string));
	copy(string,string1);
	printf("\nThe copy of the string %s is %s",string,string1);

	printf("\n*****Bounus*******\n");
	printf("\nEnter the second string:");
	scanf("%s",string2);
	bonus(string1,string2,string3);
	printf("\nThe merged string is %s\n",string3);
	return 0;
}

int check_error(int size)
{
	if(size<1 || size>100)
		return 0;
	else 
		return 1;
}
void initialize_2Darray(int array[][MAX],int size)
{
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			array[i][j]=rand()%10;
		}
	}
}
void print_2Darray(int array[][MAX],int size)
{
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%3d",array[i][j]);
		}
		printf("\n");
	}
}

int check_index(int index,int size)
{
	if (index<=size&&index>0)
		return 1;
	else
		return 0;
}
int find_columnmax(int array[][MAX],int c,int size)
{
	int i,largest=0,d;
	d=c-1;
	for(i=0;i<size;i++){
		if(array[i][d]>largest){
			largest = array[i][d];
		}
	}
	return largest;
}
float calculate_columnaverage(int array[][MAX],int c,int size)
{
	int sum=0,i,d;
	d=c-1;
	for(i=0;i<size;i++){
		sum += array[i][d];
	}
	return (float)sum/(float)size;
}

int countZero(int array[][MAX],int size)
{
	int count=0,i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(array[i][j]==0){
				count++;
			}
		}
	}
	return count;
}

void addN(int array[][MAX],int size)
{
	int add,i,j;
	for(i=0;i<size;i++){
		add=0;
		for(j=0;j<size;j++){
			add =add +array[i][j];
		}
		array[i][size-1]=add;
		
	}
	print_2Darray(array,size);
}

			
int length(char s[])
{
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
void copy(char s[],char s1[])
{
	int i=0;
	while(s[i] !='\0'){
		s1[i]=s[i];
		i++;
	}
}
void bonus(char s1[],char s2[], char s3[])
{
	int i=0;

	while(s1[i]!= '\0'){
		s3[i]=s1[i];
		i++;
	}
	while(s2[i]!='\0'){
		s3[i]=s2[i];
		i++;
	}
}



























