#include<stdio.h>
#include<stdlib.h>
int sumOfDigits(int x);
void reverseArray(int* x,int firstIndex,int lastIndex);
int fib(int x);


int main()
{
	int i,num,*arr,f;
	printf("Give me a number:");
	scanf("%d",&num);
	printf("\nSum of digits of %d is %d",num,sumOfDigits(num));
	printf("\nGive me 5 numbers, one each line\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("You Gave me:");
	for(i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
	reverseArray(arr,0,4);
	printf("\nMagic!Now it's ");	
	for(i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nGive me a final number:");
	scanf("%d",&f);	
	printf("\nThe %drd/%dth Fibonacci number is: %d\n",f,f,fib(f));
	return 0;
}
int sumOfDigits(int x)
{	
	int y=x%10;
	if(x<10)
	{
		return x;
	}
	else
		return y+sumOfDigits(x/10);
	
}
void reverseArray(int* x, int firstIndex, int lastIndex)
{
	int tmp;
	if(firstIndex<lastIndex)
	{
		tmp=*(x+firstIndex);
		//swap the first the last(or second and second from the end)
		*(x+firstIndex)=*(x+lastIndex);
		*(x+lastIndex)=tmp;
		//loop until the if condition cannot be satisfied
		reverseArray(x,++firstIndex,--lastIndex);
	}

}
int fib(int x)
{
	if(x<=2)
	{
		return 1;
	}
	else
	{
		return fib(x-1)+fib(x-2);
	}
}
