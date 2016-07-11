#include<stdio.h>
#include<stdlib.h>

typedef struct n_
{
	int x;
	int y;
	struct n_* nextNode;
}Node;

Node* importList(char* filename);
Node* removeNodes(Node* start, int x);
void printList(Node* start);
void freeList(Node* start);

int main(int argc,char **argv)
{

	if(argc!=2)
	{
		printf("Incorrect number of arguments\n");
		return 1;
	}
	Node* start=importList(*(argv+1));	
	printList(start);
	int value;
	do{
		printf("Enter an x value(-1 to exit):");
		scanf("%d",&value);
		removeNodes(start,value);
		printList(start);
	}while(value!=-1);
	freeList(start);	






	return 0;
}
Node* importList(char* filename)
{
	Node *head=NULL;
	Node *current,*previous;
	int x1,y1;	
	
	FILE * fp;
	if((fp = fopen(filename,"r"))==NULL)
	{
		
		return NULL;
	}
	else
	{
		while(fscanf(fp,"%d%d",&x1,&y1)!=EOF)
		{
			Node * new;
			new=malloc(sizeof(Node));
			if(new!=NULL)
			{
		//		while(fscanf(fp,"%d%d",&new->x,&new->y)!=EOF)

				new->x=x1;
				new->y=y1;//append the new->x
				//append the new->y
				previous = NULL;
				current = head;//set current = head
				
				while(current!=NULL)
				{
					previous = current;
					current=current->nextNode;
				}

				if(previous ==NULL)
				{
					new->nextNode= head; ///may have problem here
					head= new;
				}
				else
				{
					previous->nextNode = new;
					new->nextNode=current; //current == NULL
				}
			}
			else
			{
				printf("Memory not available\n");
			}
		}
	}	
	fclose(fp);	
	return head;
}




Node* removeNodes(Node* start, int x)
{
	Node *head=start,*temp,*prev;
	
	while(start!=NULL)
	{
		if(start->x==x)
		{
			temp=start;
			start=start->nextNode;
			if(prev!=NULL)
			{
				prev->nextNode=start;
				free(temp);
			}
			else if(prev==NULL)
			{
				free(temp);
			}
				
			continue;
		}
		else
		{
			prev= start;
			start=start->nextNode;
			continue;
		}

	}
	return head;
}
void printList(Node* start)
{
	if(start ==NULL)
	{
		printf("List is empty");
	}
	else
	{
		while(start != NULL)
		{
			printf("(%d,%d)-->",start->x,start->y);
			start = start->nextNode;
		}
		printf("NULL\n\n");
	}
}
void freeList(Node* start)
{
	Node * temp = NULL;
	while(start)
	{
		temp = start->nextNode;
		free(start);
		start=temp;
	}
}
