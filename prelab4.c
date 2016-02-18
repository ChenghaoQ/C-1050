#include<stdio.h>
int num,result;

int checkError(int);
int checkEven(int);
int main()
{
//	int num,result;

	printf("Enter a positive number:");
	scanf("%d",&num);
	checkError(num);
	checkEven(num);
	return 0;
}
int checkError(int x)
{
	while (num < 0) {
	printf("\nError!Enter a positive number only:");
	scanf("%d",&num);
	}
	return 0 ; 
}
int checkEven(int y) 
{
	result=num%2;
	if (result == 0) {
		printf("\n%d is an Even number\n",num);
	}
	else	{
		printf("\n%d is an Odd number\n",num);
	}
return 0 ;

}
