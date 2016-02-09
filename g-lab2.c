//Name: Chenghao Qian
//Pawprint: cqnp3
//Labcode:Clydesdale

#include<stdio.h>

int main(void)
{
	int first,second;
	int sum,dif,pro;
	float div;
	
	printf("Enter the first number:");
	scanf("%d",&first);
	
	while(first<0) {
		printf(" Enter a non-negative number:");
		scanf("%d",&first);
	}
	printf("\nEnter the second number:");
	scanf("%d",&second);

	while(second<0) {
                printf(" Enter a non-negative number:");
                scanf("%d",&second);
	}

	sum = first + second;

	printf("\nADDITION\nThe sum of %d and %d is %d\n.",first,second,sum);

	dif = first - second;

	printf("\nSUBTRACTION\nThe difference between %d and %d is %d\n.",first,second,dif);

	pro = first * second;

	printf("\nMULTIPLICATION\nThe product of %d and %d is %d\n.",first,second,pro);
	printf("\nDIVISION\n");
	
	

	while(second == 0) {
		
		printf("\nCannot divide by zero!\nEnter a new number:");
		scanf("%d",&second);
	}
	
	 div = (float)first / (float)second;

         printf("%d divided by %d is %.2f\n.",first,second,div);


	
	if(first>second) {
		printf("\n%d is the bigger number",first);
	}
	else if(first == second) {
		printf("\nThe two numbers are equal to each other");
	}
	else {
		printf("\n%d is the bigger number",second);
	}
		
	if(first%2 == 0) {
		printf("\n%d is an even number",first);
	}
	else {
		printf("\n%d is an odd number",first);
	}
	
	if(second%2 == 0) {
                printf("\n%d is an even number\n",second);
        }
        else {
                printf("\n%d is an odd number\n",second);

	}
	return 0;

}




















