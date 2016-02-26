#include <stdio.h>
int num;
int checkError(int);
int checkEven(int);
int checkPrime(int);
int extremeDigits(int);
int smallestLargestSum(int);
int main()
{
        printf("Enter a positive number: \n");
        scanf("%d",&num);

        while (checkError(num) == 0){
                printf("Error!Enter a positive number only:");
        	scanf("%d",&num);
		checkError(num);
	}
        if (checkEven(num)== 1){
                printf("%d is an Even number\n",num);
        }
        else {
                printf("%d is an Odd number\n",num);
	}

	if (checkPrime(num)== 1)
		printf("%d is a Prime number\n",num);
	else	{
		printf("%d is a not Prime number\n",num);
	}
	
	
	printf("Sum of the product and sum of extreme digits of %d is %d\n",num,extremeDigits(num));
	printf("The sum of smallest and largest digit in %d is %d\n",num,smallestLargestSum(num));
	return 0;

}
int checkError(int x)
{
        if (num<=0)
                return 0;
        else
                return 1;
}
int checkEven(int y)
{
        if (y%2==0)
                return 1;
        else
                return 0;
}
int checkPrime(int z)
{
	int i=2,remain;
	if (z == 1)
		return 0;
	while(i<=z/2){
		remain=z%i;
		if(remain==0){
			return 0;
			break;}
		else
			i++;
		}
	if (remain!=0)
		return 1;
}



int extremeDigits(int a)
{
	int last,first,extreme;
	if (a <10){
		return a*2;
	}
	else {
		last = a%10;
		while (a>10){
			a /=10;
		}
		first = a%10;
		extreme = (first * last)+(first+last);
		return extreme;} 
}

int smallestLargestSum(int b)
{
	int sum,small=10,large=1,cd;
	do{
		cd=b%10;
		if (cd > large){
			large= cd;
		}
		if (cd <small){
			small = cd;
		}
		b= b/10;
	}while(b>1);
	sum = large + small;
	return sum;
}








