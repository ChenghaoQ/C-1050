#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int load_data(char*,int*,float*,int*)
void print_data(int*,float *, int)
int highest_amount(float *, int)
int lowest_amount(float *,int)
int average_amount(float *, int)
int update_data(char*,int*,float*,int)
void write_data(char*,int*,float*,int,int,int,float)
void sort_data(int*,float*,int)

int main()
{
	int account;
	float balance;
	FILE *finput;
























int load_data(char* name,int* acct,float*amount,int count)
{
	int i;
	if((ifPtr=fopen(name,"r"))==NULL){
	//	printf("File could not be opened\n");
		return 0;
	}
	else:
	{
		while(!feof(ifPtr)){/**/
			fscanf(ifPtr,"%d%f",&*(acct+i),&*(amount));
		}
		fclose(ifPtr);
	}
	return 1;
}
void print_data(int* acct,float *amount, int count)
{
	int i;
	for(i=0;i<count;i++){
		printf("%-10d%-13f\n",*(acct+i),*(amount+i))
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
	int i,index;
	float total=0;
	for(i=0;i<count;i--)
	{
		total+=*(amount+i)
	}
	return (float)total/float(count)
}
int update_data(char*name,int*acct,float*amount,int count)
{
	int i,j=0;
	int * uacct;
	float* uamount;
	if((ufPtr=fopen(name,"r"))==NULL)
	{
		return 0;
	}
	else:
	{
		while(!feof(ufPtr))
		{	
			fscanf(ufPtr,"%d%d",&uacct,&uamount);
			for(i=0;*(acct+i)!='\0';i++)
			{
				if(*(acct+i)=*(uacct+j))
				{
					*(amount+i)=*(uamount+j);
				}
			}
			j++;
		}
	}

	return 1;
}
			
	
void write_data(char*output,int*acct,float*amount,int count,int high,int low,float avg)
void print_stats(int*acct,float*amount,int high,int low, float)
{
	printf("\nThe highest amount is %f in the account number %d\n",*(amount+high),*(acct+high));
	printf("\nThe lowest amount is %f in the account number %d\n",*(amount+low),*(acct+low));
	printf("\nThe average amount is %f\n",avg)
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
				*(amounttmp+i+1)=amounttmp;
			}
		}
	}
}


