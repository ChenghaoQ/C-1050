#include<stdio.h>
//Regularly we did
/*int cubeByValue(int n);

int main(void)
{
	int number = 5;
	printf("The original value of number is %d",number);
	number = cubeByValue(number);

	printf("\nThe new value of number is %d\n,number");
	return 0;
}

int cubeByvalue(int n)
{
	return n*n*n;
}*/
//But...
void cubeByRefernce( int *nPtr);
int main()
{
	int number =5;
	printf("The original value of umber is %d",number);
	cubeByReference(&number);
	printf("\nThe new value of number is %d\n",number);
	return 0;
}
void cubeByReference( int *nPtr)
{
	*nPtr= *nPtr * *nPtr * *nPtr;
}
