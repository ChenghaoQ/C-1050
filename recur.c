#include <stdio.h>
long factorial ( long number);

int main()
{ 
	int i;
	
	for ( i= 0; i <=10; i++){
		printf("%2d! = %ld\n",i,factorial(1));
		}
	return 0;
}


