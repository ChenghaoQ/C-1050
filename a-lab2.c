//Name: Chenghao Qian
//lab/A
#include<stdio.h>
#include<stdlib.h>

typedef struct t_
{
	int ID;
	int ticketsSold;
	int totalTickets;
	float ticketPrice;
	int numDays;
}Record;
Record* ReadRecords(char* filename);
Record BestPercentageSold(Record* records);
Record BestDailyProfit(Record* records);
Record EarliestSellout(Record* records);




Record* ReadRecords(char* filename)
{
	Record *reco;
	reco = malloc(sizeof(Record)*300);
	int i = 0;
	FILE* ofPtr;
	if((ofPtr = fopen(filename,"r"))==NULL)
	{
		return NULL;
	}
	else
	{
		while(fscanf(ofPtr,"%d%d%d%f%d",&reco[i].ID,&reco[i].ticketsSold,&reco[i].totalTickets,&reco[i].ticketPrice,&reco[i].numDays)!=EOF)
		{
			i++;
		}
	}
	if(i<124){
		return NULL; ///////////////////////////////////////
	}
	fclose(ofPtr);
	return reco;
}

Record BestPercentageSold(Record* records)
{
	float highpercent=records[0].ticketsSold/records[0].totalTickets,perc;
	int markdown;
	int i=0;
	
	while(i<125)
	{
		perc=(float)records[i].ticketsSold/(float)records[i].totalTickets;
		
		if(highpercent<perc)
		{
			markdown=i;
			highpercent=perc;
		}
		i++;
	}
	return records[markdown];
}


Record BestDailyProfit(Record * records)
{
	float highprofit=(float)(records[0].ticketsSold*records[0].ticketPrice)/(float)records[0].numDays,perpro;
	int markdown;
	int i=0;
	while(i<125)
	{
		
		perpro=(float)(records[i].ticketsSold*records[i].ticketPrice)/(float)records[i].numDays;
		
		if(highprofit<perpro)
		{
		
			markdown=i;
			highprofit=(float)(records[i].ticketsSold*records[i].ticketPrice)/(float)records[i].numDays;			
		}
		i++;
	}
	

	return records[markdown];
}

Record EarliestSellout(Record* records)
{
	float soldavg,timeleft,shortest=10000.00;
	int i,rest,hold;
	while(i<124)
	{
		soldavg=(float)records[i].ticketsSold/(float)records[i].numDays;
		rest=records[i].totalTickets-records[i].ticketsSold;
		timeleft=(float)rest/(float)soldavg;
		printf("%f %f\n",shortest,timeleft);
		if(timeleft<shortest)
		{
			shortest=timeleft;
			hold=i;
		}
		i++;
	}	
	return records[hold];
}


int main(int argc, char **argv)
{
	Record *records,bestper,bestprofit,early;
	

	if(argc>2|| argc<2)
	{
		printf("Incorrect number of arguments\n");
	}
	
	records= malloc(sizeof(Record)*200);

	if(ReadRecords(*(argv+1))!=NULL)
	{
		records=ReadRecords(*(argv+1));
	}
	else{
		printf("Something wrong with file, please check\n");
	}
	bestper=BestPercentageSold(records);
	bestprofit=BestDailyProfit(records);
	early=EarliestSellout(records);
	printf("\nBest Percentage Sold: %d\n",bestper.ID);
	printf("\nBest Daily Profit: %d\n",bestprofit.ID); 
	printf("\nThe earliest sellout: %d\n",early.ID);
	free(records);
	return 0;
}
	
	






















