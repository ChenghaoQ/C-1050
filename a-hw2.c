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
int processOldestOrder(Order** firstOrder);
void freeList(Order* list);
int getPriority();


int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage: ./a.out <filename>\n");
		return -2;
	}

	Order** lists = importLists(argv[1]);
	if(lists == NULL)
	{
		printf("Error reading from %s.\n", argv[1]);
		return -1;
	}

	while(1)
	{
		printf("1: print a list\n");
		printf("2: change an order's priority\n");
		printf("3: process oldest order\n");
		printf("4: quit\n>");
		int selection;
		scanf("%d", &selection);
		while(selection < 1 || selection > 4)
		{
			printf("Invalid selection, choose again:\n>");
			scanf("%d", &selection);
		}
	
		if(selection == 1)
		{
			printf("Which list do you want to print out?\n");
			int priority = getPriority();
			printList(lists[priority - 1]);
			
		}
		else if(selection == 2)
		{
			printf("What is the ID of the order to be changed?\n>");
			int ID;
			scanf("%d", &ID);
			printf("What was the ID's old priority?\n");
			int priority = getPriority();

			printf("What is the ID's new priority?\n");
			int newPriority = getPriority();

			int ret = updateOrder(ID, &lists[priority - 1], &lists[newPriority - 1]);		
			if(ret != ID)
			{
				printf("Error updating order no. %d.\n", ID);
			}
			else
			{
				printf("Order no. %d updated successfully.\n", ID);
			}
		}
		else if(selection == 3)
		{
			printf("Which priority list do you want to process from?\n");
			int priority = getPriority();
			int ret = processOldestOrder(&lists[priority - 1]);
			if(ret != 0)
			{
				printf("Error processing from list %d. Is it empty?\n", priority);
			}
			else
			{
				printf("list %d processed successfully.\n", priority);
			}
		}
		else break;
	}

	int i;
	for(i = 0; i < 4; i++)
	{
		freeList(lists[i]);
	}

	free(lists);
	return 0;
}

Order** importLists(char* filename)
{
	
	//orders=malloc(sizeof(*order)*4);
	Order **selection=NULL;//*nextday=NULL,*business=NULL,*standard=NULL,*longterm=NULL,*selection=NULL;
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
					selection=&*(orders+0);
					break;
				case 2:
					selection=&*(orders+1);
					break;
				case 3:
					selection=&*(orders+2);
					break;
				case 4:
					selection=&*(orders+3);
					break;
			}

			Order *new;
			new = malloc(sizeof(Order));
			printf("New orders\n");
			if(new!=NULL)
			{
				new->ID=x1;
				new->daysInQueue=y1;
				previous = NULL;
				current = *selection;//set current = head

				while(current!=NULL)
				{
					previous = current;
					current = current->nextOrder;
				}
				if(previous ==NULL)
				{
					new->nextOrder =* selection;
					*selection=new;
				}
				else
				{
					previous->nextOrder = new;
					new->nextOrder=NULL;/////
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
	if(firstOrder==NULL)
	{
		printf("Currently there is no orders\n");
	}
	else
	{
		while(firstOrder !=NULL)
		{
			printf("Order No. %d: %d days in queue.\n",firstOrder->ID,firstOrder->daysInQueue);
			firstOrder = firstOrder->nextOrder;
		}
		printf("\n\n");
	}
}


int updateOrder(int ID, Order ** oldList, Order** newList)
{
	Order *previous,*current,*temp=NULL;
	current=*oldList;
	if(current->ID==ID)
	{
		temp=current;
		current=current->nextOrder;
		*oldList=current;
	}
	while(current!=NULL)
	{
		previous=current;
		if(current->ID==ID)
		{
			temp = current;
			current=current->nextOrder;
			previous->nextOrder=current;
			break;
		}
		current=current->nextOrder;
	}
	if(temp == NULL)
	{
		printf("Sorry we cannot find that ID\n");
		if(ID==0)
			return 0;
		else
			return 1;
	}
	



	//Add to newlist
	previous=NULL;
	current=*newList;
	while(current !=NULL)
	{
		previous =current;
		current = current->nextOrder;
	}
	if(previous == NULL)
	{
		temp->nextOrder = *newList;
		*newList = temp;
	}
	else
	{
		previous->nextOrder = temp;
		temp->nextOrder = NULL;
	}
	return temp->ID;
}
int processOldestOrder(Order** firstOrder)
{
	int oldest;
	Order *current,*previous=NULL,*temp,*temprev=NULL;
	current=*firstOrder;
	oldest=current->daysInQueue;
	while(current)
	{
		previous=current;
		if(current->daysInQueue>oldest)
		{
			temprev=previous;
			temp=current;
		}
		current=current->nextOrder;
	}
	if(temprev==NULL)
	{
		printf("-------------------");
	}
	else
	{
		temprev->nextOrder=temp->nextOrder;
		free(temp);
	}
	return 0;
}
void freeList(Order* list)
{
	Order * temp =NULL;
	while(list)
	{
		temp = list->nextOrder;
		free(list);
		list=temp;
	}

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
