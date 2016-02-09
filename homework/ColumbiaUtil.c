#include<stdio.h>

int main()
{
	int choice,units,again,number,Seven,Sodd;
	int counter =0;
	float charge,due;
	float total =0.00;
	do{	
		printf("***** ELECTRICITY BILL CALCULATOR *****\n");
		printf("\n1.Residential\n2.Commercial\n3.Industrial\n");
		printf("\nChoose the type of connection: ");
		scanf("%d",&choice);

			while(choice !=1 && choice != 2 && choice != 3){
				printf("Invalid Choice!Please enter a vaild choice\n");
				printf("\n1.Residential\n2.Commercial\n3.Industrial\n");	
				printf("\nChoose the type of connection: ");
				scanf("%d",&choice);
				}
				
				printf("Enter the number of units(in kWh): ");
				scanf("%d",&units);
				while(units<=0)	{
					printf("Invalid input!Please enter a positive value: ");
					scanf("%d",&units);
					}

				switch(choice) {

					case 1:
						if(units<=300) {
							charge =(float)units*(7.50/100.00);}
						else if(units>300 && units<=750){	
							charge = (float)units*(10.00/100.00);}
						else if(units>750 && units<=1500){
							charge = (float)units*(13.50/100.00);}
						else	{
							charge = (float)units*(15.00/100.00);}	
						due = charge + 15.00;
						break;
					case 2:
						if(units<=300) {
                                                        charge =(float)units*(10.50/100.00);}
                                                else if(units>300 && units<=750){
                                                        charge = (float)units*(14.00/100.00);}
                                                else if(units>750 && units<=1500){ 
                                                        charge = (float)units*(17.50/100.00);}
                                                else    {
                                                        charge = (float)units*(20.00/100.00);}
                                                due = charge + 70.00;
						break;

					case 3:
						if(units<=300) {
                                                        charge =(float)units*(36.50/100.00);}
                                                else if(units>300 && units<=750){
                                                        charge = (float)units*(40.00/100.00);}
                                                else if(units>750 && units<=1500){ 
                                                        charge = (float)units*(45.50/100.00);}
                                                else    {
                                                        charge = (float)units*(50.00/100.00);}
                                                due = charge + 650.00;
						printf("3");
						break;
				
				}
				total += due;
				counter++;

				printf("\nTotal energy charge for the customer is:$%.2f\n",charge);
				printf("Total Bill due from this connection is:$%.2f\n",due);
				printf("Do you want to continue and calculate another bill? If yes enter 1 else 0: ");
				scanf("%d",&again);
				}while(again == 1);

				printf("\nYou calculated the bill %d times and the total amount from all the bills due is $%.2f\n",counter,total);
				printf("\nEXITING ELECTRICITY BILL CALCULATOR\n*** BONUS ***\nEnter a number: ");
				scanf("%d",&number);
				int i=0,sum;
				printf("The numbers are: ");
				for(i=0;i<=number;i++){
					printf("%d  ",i);
					sum += i;
					if (i%2==0) {
						Seven +=i;}
					else	{	
						Sodd +=i;}
				}
				printf("\nThe sum of all numbers from 0 to %d is %d",number,sum);
				printf("\nSum of Even numbers = %d",Seven);
				printf("\nSum of Odd numbers = %d\n",Sodd);
				return 0;

}
