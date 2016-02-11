#include<stdio.h>
void sue(void);
int fred=10;  /*fred is global variable because it is outside of any functions*/

int main(void)
{
        printf("\n%d\n",fred);
        sue();
        printf("\n%d\n",fred);
        fred += 1;
        printf("\n%d\n",fred);
        return 0;
}
void sue(void)
{	printf("%d",fred);
	int sue = 14;
		{
			int sue =17;
			printf("%d",sue);/* this sue in the curly braces is the local variable so it would print 17 other than 14*/
		}
	printf("%d",sue); /* this sue is outside so this one is on the same level with sue = 14, so print 14*/
	fred =5;
	printf("\n%d\n",fred);

	
}
