#include<stdio.h>
#include<stdlib.h>


int main()
{

	int * arr,i;
	arr=malloc(sizeof(int)*10);



	for(i=0;i<10;i++)
	{
		*(arr+i)='x';
	}
	
	for(i=10;i<12;i++)
	{
		if(*(arr+i)=='x')
			printf("nothing there\n");
	
	}





	return 0;
}

