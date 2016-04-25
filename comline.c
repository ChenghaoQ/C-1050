#include<stdio.h>


int main(int argc, char *argv[])
{
	int account;
	char name[30];
	double balance;
	int count;
	FILE *cfPtr;

	if(argc < 4 || argc>4)
	{
		printf("Incorrect number of arguments\n");
		return 1;
	}

	count= atoi(argv[1]);
	if((cfPtr = fopen(argv[2],"w"))==NULL)
	{
		printf("File could not be opened\n");
		return 2;
	}
	
	printf("Enter the account,name,and balance.\n");
	
	int i=0;
	for(i=0;i<count;i++)
	{
		printf("? ");
		scanf("%d%s%lf",&account,name,balance);
		fprintf(cfPtr,"%d%s%.2f\n",account,name,balance);
	}
	fclose(cfPtr);
	printf("\n%s\n",argv[3]);
	return 0;
}


