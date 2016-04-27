#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int load_data(char*,int*,float*,int);
void print_data(int*,float *, int);
int highest_amount(float *, int);
int lowest_amount(float *,int);
int average_amount(float *, int);
int update_data(char*,int*,float*,int);
void write_data(char*,int*,float*,int,int,int,float);
void sort_data(int*,float*,int);
void print_stats(int*,float*,int ,int , float);

int main(int argc,char**argv)
{
	int *account;
	float *amount;

	if (argc<5||argc>5)
	{
		printf("Incorrect number of arguments\n");
		return 1;
	}

	int count = atoi(*(argv+2));
	account=malloc(sizeof(int)*count);
	amount=malloc(sizeof(int)*count);

	if(load_data(*(argv+1),account,amount,count)==0)
	{
		printf("\nUnable to open the input file\n");
		return 0;
	}
	print_data(account,amount,count);
	
	int high=highest_amount(amount,count),low=lowest_amount(amount,count);
	float avg=average_amount(amount,count);
	print_stats(account,amount,high,low,avg);
	

	printf("\n**** UPDATED WITH NEW VALUES AND SORTED in the ascending order of Account Numbers ****\n");
	if(update_data(*(argv+3),account,amount,count)==0)
	{
		printf("\nERROR!!! Unable to open the file updte.txt to perform update operation, please check\n");
		return 0;
	}
	sort_data(account,amount,count);
	print_data(account,amount,count);
	print_stats(account,amount,highest_amount(amount,count),lowest_amount(amount,count),average_amount(amount,count));

	write_data(*(argv+4),account,amount,count,highest_amount(amount,count),lowest_amount(amount,count),average_amount(amount,count));
	free(account);
	free(amount);
	
	return 0;
}




int load_data(char* name,int* acct,float*amount,int count)
{
	int i;
	FILE * ifPtr;
	if((ifPtr=fopen(name,"r"))==NULL){
	//	printf("File could not be opened\n");
		return 0;
	}
	else
	{
		for(i=0;i<count;i++)
		{
			fscanf(ifPtr,"%d%f",&*(acct+i),&*(amount+i));
		}
		fclose(ifPtr);
	}
	return 1;
}
void print_data(int* acct,float *amount, int count)
{
	int i;
	for(i=0;i<count;i++){
		printf("%-10d%-13.2f\n",*(acct+i),*(amount+i));
	}

}
	
int highest_amount(float *amount, int count)
{
	int i,index;
	float tmp=*amount;
	for(i=count;i>0;i--){
		if(tmp<*(amount+i))
		{
			index=i;
		}
	}
	return index;
}
		
int lowest_amount(float *amount,int count)
{
	int i,index;
	float tmp=*amount;
	for(i=count;i>0;i--){
		if(tmp>*(amount+i)){
			index=i;
		}
	}
	return index;
}
int average_amount(float *amount, int count)
{
	int i;
	float total=0;
	for(i=0;i<count;i++)
	{
		total+=*(amount+i);
	}
	return (float)total/(float)count;
}
int update_data(char*name,int*acct,float*amount,int count)
{
	int i,j=0;
	int * uacct;
	float* uamount;

	uacct=malloc(sizeof(int)*count);
	uamount=malloc(sizeof(int)*count);
	FILE *ufPtr;
	if((ufPtr=fopen(name,"r"))==NULL)
	{
		return 0;
	}
	else
	{
		while(!feof(ufPtr))
		{	
			fscanf(ufPtr,"%d%f",&*(uacct+j),&*(uamount+j));
			
			for(i=0;i<count;i++)
			{
				if(*(acct+i)==*(uacct+j))
				{
					*(amount+i)=*(uamount+j);
				}
			}
			j++;
		}
	}
	fclose(ufPtr);
	return 1;
}
			
	
void write_data(char*outname,int*acct,float*amount,int count,int high,int low,float avg)
{
	FILE *ofPtr;
	int i;	
	ofPtr = fopen(outname,"w");
	for(i=0;i<count;i++)
	{
		fprintf(ofPtr,"%d    %.2f\n",*(acct+i),*(amount+i));
	}
	fprintf(ofPtr,"\nThe highest amount is %.2f in the account number %d\n",*(amount+high),*(acct+high));
	fprintf(ofPtr,"\nThe lowest amount is %.2f in the account number %d\n",*(amount+low),*(acct+low));
	fprintf(ofPtr,"\nThe average amount is %.2f\n",avg);

	printf("\nOutput written to %s\nThank you for using our application\n",outname);
	fclose(ofPtr);
}
void print_stats(int*acct,float*amount,int high,int low, float avg)
{
	printf("\nThe highest amount is %.2f in the account number %d\n",*(amount+high),*(acct+high));
	printf("\nThe lowest amount is %.2f in the account number %d\n",*(amount+low),*(acct+low));
	printf("\nThe average amount is %.2f\n",avg);
}
void sort_data( int*acct, float*amount, int count)
{
	int accttmp,i,j;
	float amounttmp;

	for(j=0;*(acct+j)!='\0';j++)
	{
		for(i=0;i<count-1;i++)
		{
			if(*(acct+i)>*(acct+i+1))
			{
				accttmp=*(acct+i);
				*(acct+i)=*(acct+i+1);
				amounttmp=*(amount+i);
				*(amount+i)=*(amount+i+1);
				*(acct+i+1)=accttmp;
				*(amount+i+1)=amounttmp;
			}
		}
	}
}


