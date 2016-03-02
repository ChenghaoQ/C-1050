//Name:Chenghao Qian
//pawprint: cqnp3
//Lab:G
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int checkError(int);
int cube(int);
int generateNumber(void);
float division(float,float);
int main()
{	
	srand(time(NULL));
	int select,num1,num2;
	num1=generateNumber();
	num2=generateNumber();
	printf("* * * * * * Menu * * * * * *\n(1)Cube             (2)Divide\nPlease select one:");
	scanf("%d",&select);
	while(select!=1 && select !=2){
		select=checkError(select);
	}
	if (select==1){
		printf("\nCube of %d is %d\n",num1,cube(num1));
	}
	else{
		printf("Div(%d,%d)=%.2f\n",num1,num2,division(num1,num2));
	}	
	return 0;
}
int checkError(int select)
{
		printf("* * * * * * Menu * * * * * *\n(1)Cube             (2)Divide\n");
		printf("Incorrect choice! Please select 1 or 2: ");
		scanf("%d",&select);
		return select;

}
int cube(int a)
{
	return a*a*a;
}
float division(float a,float b)
{	/*while (num2==0){
		printf("Error!Cannot divided by 0!:");
		scanf("%d",num2);*/
	return a/b;
}
int generateNumber(void)
{		
	return rand()%10;
}
