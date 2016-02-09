//Name:Chenghao Qian
//Pawprint: cqnp3


#include<stdio.h>
int main(void)
{
        int first,second,sum,product;

        printf("Enter the first Number:\n");
        scanf("%d",&first);

        if(first<0) {
                printf("No negative number please!\n");
                printf("Enter a new value:\n");
                scanf("%d",&first);
        }

        printf("Enter the second number:\n");
        scanf("%d",&second);

        if(second<0) {
                printf("No negative number please!\n");
                printf("Enter a new value:\n");
                scanf("%d",&second);
        }

        sum = first + second;
        product = first * second;

        printf("\nADDITION");
        printf("\nThe sum of %d and %d is %d",first,second,sum);

        printf("\nMUTIPLICATION");
        printf("\nThe prodcut of %d and %d is %d\n",first,second,product);

        return 0;
}
       
