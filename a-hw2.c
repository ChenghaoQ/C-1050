#include<stdio.h>
#include<stdlib.h>

typedef struct o_
{
	int ID;
	int daysInQueue;
	struct o_* nextOrder;
}Order;

Order** importLists(char* filename);
void printList(Order* firstOrder);
int updateOrder(int ID, Order ** oldList, Order** newList);
int processOlderstOrder(Order** firstOrder);
void freeList(Order* list);
int getPriority();


int main()
{


	return 0;
}
Order** importLists(char* filename)
{
	
	//orders=malloc(sizeof(*order)*4);
	Order *selection=NULL;//*nextday=NULL,*business=NULL,*standard=NULL,*longterm=NULL,*selection=NULL;
	Order** orders;
	orders=malloc(sizeof(Order*)*4);

	int i;
	for(i=0;i<4;i++)
	{
		*(orders+i)=NULL;
	}
	
	Order *current,*previous;
	int x1,y1,z1;

	FILE * fp;
	if((fp = fopen(filename,"r"))==NULL)
	{
		return NULL;
	}
	else
	{
		while(fscanf(fp,"%d%d%d",&x1,&y1,&z1)!=EOF)
		{
			switch(z1){
				case 1:
					selection=*(orders+0);
					break;
				case 2:
					selection=*(orders+1);
					break;
				case 3:
					selection=*(orders+2);
					break;
				case 4:
					selection=*(orders+3);
					break;
			}

			Order *new;
			new = malloc(sizeof(Order));
			if(new!=NULL)
			{
				new->ID=x1;
				new->daysInQueue=y1;
				previous = NULL;
				current = selection;//set current = head

				while(current!=NULL)
				{
					previous = current;
					current = current->nextOrder;
				}
				if(previous ==NULL)
				{
					new->nextOrder = selection;
					selection=new;
				}
				else
				{
					previous->nextOrder = new;
					new->nextOrder=current;
				}
			}
			else
			{
				printf("Memory not available\n");
			}
		}





	}
	fclose(fp);
	return orders;

}
void printList(Order* firstOrder)
{


}
int updateOrder(int ID, Order ** oldList, Order** newList)
{


}
int processOlderstOrder(Order** firstOrder)
{


}
void freeList(Order* list)
{


}
int getPriority()
{
	printf("1: next day\n");
	printf("2: Business\n");
	printf("3: Standard\n");
	printf("4: Long term\n");
	int priority;
	scanf("%d",&priority);
	while(priority < 1 || priority >4)
	{
		printf("Invalid selection, choose again: \n");
		scanf("%d",&priority);
	}
	return priority;
}
