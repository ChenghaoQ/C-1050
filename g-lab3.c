//Name:Chenghao
//Pawprint: cqnp3
//Labcode:Tigers Den

#include<stdio.h>
#include<math.h>

int main(void)
{
	int yr,select;
	float chk=0.01,sav=0.03,fix=0.07;
	double amtci,intearned;
	float amt;

	do {
	
		printf("Bank account type\n\n(1) Checking\n(2) Saving\n(3) Fixed Deposit\nPlease make a selection: ");
		scanf("%d",&select);
		
		if (select!= 1 && select !=2 && select != 3) {
			printf("Incorrect choice, please make a choice again"); 
	
	}
	
	}while(select != 1 && select !=2 && select != 3);

	printf("Enter a year: ");
	scanf("%d",&yr);
	
	while (yr<1 || yr > 10) {
		printf("Incorrect value, year should be between 1-10\nEnter a year:  ");
		scanf("%d",&yr);
	}

	printf("\nEnter a amount: ");
	scanf("%f",&amt);
	while (amt <0) {
		printf(" \nIncorrect value, enter the amount again:  ");
		scanf("%f",&amt);
	}


	switch(select) {
		case 1: 
			amtci= amt * pow(1.0+chk,yr);
			intearned = amtci - amt;
			break;
		case 2: 
			amtci = amt * pow(1.0+sav,yr);
			intearned = amtci - amt;
			break;
		case 3:
			amtci = amt * pow(1.0+fix,yr);
			intearned = amtci - amt;
			break;

	}

	printf("\nTotal amount after %d years is $ %.2f",yr,amtci);
	printf("\nTotal interest earned on the amount $%.2f is $%.2f\n",amt,intearned);
	

	float number,result=1;
	int exp,i;
	printf("\n\nBonus part\nEnter a number:");
	scanf("%f",&number);
	printf("\nEnter an exponent:");
	scanf("%d",&exp);
	
	if (exp > 0) {
		
		for(i=0;i<exp;i++) {
			result = result * number;
		}
	}
	else if (exp == 0){
			result = 1;
		}
	else
	{
		for( i = 0;i>exp;i--) {
			result = result / number;
		}
	}

	
	

	printf("pow(%.2f,%d) = %f\n",number,exp,result);



	return 0;

}
		

	

	
