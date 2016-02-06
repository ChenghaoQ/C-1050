#include <stdio.h>
        
int main(void)
{
	float time;
	int distance,speed;

	printf("\nPlease enter the speed in miles/hr:");
	scanf("%d",&speed);
	
	if(speed<0)
		printf("\n Please Enter a postive number again:");
		scanf("%d",&speed);
	
	printf("Please enter the distace in miles:");
	scanf("%d",&distance);
	
	if(distance<0)
		printf("\n Please Enter a postive number again:");
		scanf("%d",&distance);

	time= ((float)distance*1600.00/(float)speed/3600.00);

	printf(" The flight time is %.2f second\n",time);

	return 0;
}
