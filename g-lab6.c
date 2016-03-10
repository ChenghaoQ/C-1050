//Name: Chenghao Qian
//Pawprint: cqnp3
//Lab code:Ebullient
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
int check_error(int);
void initialize_array(int[],int);
void print_array(int[],int);
int max(int[],int);
int smallest_number(int[],int);
float mean(int[],int);
int number_count(int[],int,int);
int common_numbers(int[],int[],int);
//int bonus(int[]);
int main()
{
	srand(time(NULL));
	int size,array1[SIZE],array2[SIZE];
	int num;
	printf("Enter the size of the input:");
	scanf("%d",&size);
	while(check_error(size)==0){
		printf("\nInvalid input enter the size of the input again:");
		scanf("%d",&size);
	}
	
	initialize_array(array1,size);
	printf("\nThe first input array\n");
	print_array(array1,size);
	printf("\nThe maximum number is present at the index location %d in the array",max(array1,size));
	printf("\nThe minimum number is present at the index location %d in the array",smallest_number(array1,size));
	printf("\n\nAverage of numbers in the first array is %.2f\n",mean(array1,size));


	initialize_array(array2,size);
	printf("\nThe second input array\n");
	print_array(array2,size);
	printf("\nThe maximum number is present at the index location %d in the array",max(array2,size));
	printf("\nThe minimum number is present at the index location %d in the array",smallest_number(array2,size));
	printf("\n\nAverage of numbers in the second array is %.2f\n",mean(array2,size));

	printf("\nEnter a number:");
	scanf("%d",&num);

	printf("\nThe count of number %d in the first array is %d\n",num,number_count(array1,size,num));
	printf("\nThe count of number %d in the second array is %d\n",num,number_count(array2,size,num));
	printf("\nThe number of common numbers in the two arrays: %d\n",common_numbers(array1,array2,size));

/*	printf("Bonus part***\n");
	printf("\nArray before sorting\n");
	print_array(array1,size);
	printf("\n");
	print_array(array2,size);
	printf("\nArray after sorting\m");
	print_array(bounus(array1),size);
	printf("\n");
	print_array(bounus(array2),size);
	printf("\n");*/
	return 0;
}

int check_error(int size)
{
	if (size>=1 && size <= 100){
			return 1;
	}
	else{ 
		return 0;	
	}
}

void initialize_array(int array[],int size)
{	int i;
	for(i=0;i<size;i++){
		array[i]=rand()%10;
	}
}
void print_array(int array[],int size)
{	int j;
	for(j = 0;j<size;j++){
		printf("%d",array[j]);
		}
}
int max(int array[],int size)
{	int i,temp=0,ii;
	for(i=0;i<size;i++){
		if (array[i]>temp){
			temp = array[i];
			ii=i;
		}
	}
	return ii;
}

int smallest_number(int array[],int size)
{	int j,temp=10,jj;
	for(j=0;j<size;j++){
		if(array[j]<temp){
			temp=array[j];
			jj=j;
		}
	}
	return jj;
}
float mean(int array[],int size)
{	int i,sum=0;
	for (i=0;i<size;i++){
		sum += array[i];
	}
	return (float)sum/(float)size;
}
		
int number_count(int array[],int size, int number)
{
	int i,frequence=0;
	for (i=0;i<size;i++){
		if(array[i]==number){
			frequence++;
		}
	}
	return frequence;
}


int common_numbers(int array1[],int array2[],int size)
{	
	int i,j,k=0,common=0;
	for(k=0;k<10;k++){
		while(i<size){
			while(j<size){
				if(array1[i]==array2[j]&&array1[i]==k){
						common++;
						k++;
				j++;}
			j=0;
		i++;}
		i=0;	
		}
	}
	return common;
}

/*void bonus(int array[])
{
	int hold,i;
	for (i=0;i<SIZE - 1;i++){
		if(array[i]>array[i+1]{
			hold = array[i];
			a[i]=array[i+1];
			a[i+1]=hold;
		}
	}	
	return array[]
}
*/





























