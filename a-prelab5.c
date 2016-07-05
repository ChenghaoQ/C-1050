#include<stdio.h>
#include<stdlib.h>

typedef struct i_
{
	int value;
	struct i_* nextItem;
}Item;
//typedef Item *It;

Item* addItem(Item** start, int toAdd);
void printList(Item* start);
void freeList(Item* start);

int main()
{
	Item* startPtr = NULL;
	
	int add;
	do{
		printf("Enter a number(-1 for exit):");
		scanf("%d",&add);
		addItem(&startPtr,add);
		printList(startPtr);
	}while(add!=-1);

	
	return 0;
}


Item* addItem(Item* *start, int toAdd)
{
	Item *new,*previous,*current;//May have problem here
	new = malloc(sizeof(Item));

	if(new != NULL)
	{
		new->value = toAdd;
		new->nextItem = NULL;
		previous = NULL;
		current = *start;
		
		while(current != NULL)
		{
			previous = current;
			current=current->nextItem;
		}
		
		if(previous ==NULL)
		{
			new->nextItem = *start;
			*start = new;
		}
		else
		{
			previous->nextItem = new;
			new->nextItem = current;
		}
	}
	else
	{
		printf("%d not added.No memory available.\n",toAdd);
	}
	return *start;
}


void printList(Item* start)
{
	if(start ==NULL)
	{
		printf("List is empty.\n\n");
	}
	else
	{

		while(start !=NULL)
		{
			printf("%d -->",start->value);
			start = start->nextItem;
		}

		printf("NULL\n\n");
	}
}


void freeList(Item* start)
{
	Item* temp = NULL;
	while(start)
	{
		temp=start->nextItem;
		free(start);
		start=temp;
	}
}

