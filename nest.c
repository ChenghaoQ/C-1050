#include<stdio.h>

int main(void)
{
	int passes = 0;
	int failures = 0;
	int students = 1;
 	int results;

	while(students <= 10) {
		printf("Enter result (1=pass, 2=fail):");
		scanf("%d",&results);
	
	if (results < 1)(results > 2); {
		printf("Error!");
	}
	else{
		students = students + 1;
		if(results == 1)
			passes ++;
		else
			failures ++;
	}
	/*if ( results ==1) {
		passes = passes + 1;
	}

	else if (results == 2){
		failures = failures + 1;
	}
	else {
		printf("Please enter 1 or 2 only!");
	}
	students = students + 1;
	}*/
	printf("Passed %d\n",passes);
	printf("Failed %d\n",failures);

	if (passes > 8 ) {
		printf("Bonus to instructor!\n");
	}
	return 0;
}
