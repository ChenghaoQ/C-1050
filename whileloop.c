#include <stdio.h>

int main(void)
{
     int counter;
     int grade;
     int total;
     int average;

     total = 0;
     counter = 1;

     while ( counter <=10) {
          printf("\nEnter grade: ");
          scanf("%d",&grade);
          total = total + grade;/* add grade to toal*/
          counter = counter + 1; /*increment counter*/
     }/*end while*/

	average = total /10;
	printf("class average is %d\n",average);
	
	return 0;
}
