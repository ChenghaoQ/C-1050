#include <stdio.h>

int main(void)
{
	int miles;/*total miles driven per day*/
	int gasCost;/*cost per gallon of gasoline*/
	int mpg;/*average miles per gallon*/
	int parkFee;/*parking fees per day*/
	int tolls;/*tolls per day*/
	int total;/*total cost*/

	printf("Please enter the total miles driven per day:");
	scanf("%d",&miles);

	
	printf("please enter the cost per gallon of gasoline:");
	scanf("%d",&gasCost);

	printf("please enter average miles per gallon:");
	scanf("%d",&mpg);

	printf("plasse enter the parking fess per day:");
	scanf("%d",&parkFee);

	printf("please enter the tolls per day:");
	scanf("%d",&tolls);

	printf("please enter the tolls per day:");
	scanf("%d",&tolls);
	
	total = tolls + parkFee + (miles/mpg)*gasCost;

	printf("Your daily cost of driving to work is $%d\n",total);
	
	return 0;
}

