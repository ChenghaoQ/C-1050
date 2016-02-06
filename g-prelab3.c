//Name: Chenghao Qian
//Pawprint:cqnp3
//lab: G
#include<stdio.h>

int main()
{
        int selection;
        int length,square,cube,radius;
        float circle;

        printf("Area calculation\n(1) Square\n(2) Cube\n(3) Circle");
        printf("\nPlease make a selection:");
	scanf("%d",&selection);

        while(selection !=1 && selection !=2 && selection !=3) {
		printf("Incorrect choice\n");
		scanf("%d",&selection);
		}
                switch(selection) {

                        case 1:

                                printf("Enter a positve number:\n");
                                scanf("%d",&length);
                                printf("Length of the side of square is %d",length);
                                square = length * length;
                                printf("\nArea of square is %d\n",square);
                                break;


                        case 2 :
				printf("Enter a positive number:\n");	
				scanf("%d",&length);

                                printf("Length of the side of cube is %d",length);
                                cube = length * length * 6;
                                printf("\nArea of cube is %d\n",cube);
                                break;

                        case 3 :
                                printf("Enter a positive number:\n");
                                scanf("%d",&radius);
                                printf("Radius of circle is %d",radius);
                                circle = 3.14159 *(float) radius * (float)radius;
                                printf("\nArea of the circle is %.2f\n",circle);
                                break;


                        
		}
                       

                

		 return 0;
}
