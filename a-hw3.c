#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINELENGTH 50
#define MAXCITYNAME 30

typedef struct n_
{
	int zipCode;
	char* city;
	char state[3];
	struct n_* left;
	struct n_* right;
}Node;

Node* importTree(char* filename);
Node* addNode(Node* root,Node* newNode);
int findStateCount(Node* root,char* state);
Node* findZipCode(Node* root,int zipCode);
void freeTree(Node* root);

int main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("Usage: ./a.out <filename>\n");
		return -1;
	}
	Node *root=importTree(argv[1]);
	int select,i=0;
	while(i==0)
	{
		printf("\n1:find number in a state\n2:find a zip code\n3:exit\n>");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				{
					char state[3];
					printf("Enter the state you want to search for:");
					scanf("%s",state);
					printf("The state has %d results in the sample.\n",findStateCount(root,state));
					break;
				}
			case 2:
				{
					int zipcode;
					printf("Enter the zip code you want to find:");
					scanf("%d",&zipcode);
					Node* result = findZipCode(root,zipcode);
					if(result == NULL)
						printf("\nNo result found for %d\n",zipcode);
					else
					{
						printf("\nResult found for %d:\nCity:%s\nState:%s\n",zipcode,result->city,result->state);
					}
					break;
				}
			case 3:

				i=-1;
				break;
			default:
				printf("Invaild input,please try again\n");
				break;
		}
	}
	freeTree(root);
	
	


	return 0;
}


Node* importTree(char* filename)
{
	Node* root =NULL;
	FILE* fp= fopen(filename,"r");

	if(!fp)
	{
		printf("Error opeing file.\n");
		return NULL;
	}
	while(!feof(fp))
	{
		Node* new= malloc(sizeof(Node));
		if(!new)
		{
			printf("failed to allcate memory.Ending read.\n");
			//Quit the program, not return back to main;
			exit(1);
		}
		new->city = malloc(sizeof(char)*MAXCITYNAME);
		
		if(!(new->city))
		{
			printf("Failed to allocate memory.Ending read.\n");
			exit(1);
		}
		
		new->left =NULL;
		new->right = NULL;
		char* line = malloc(sizeof(char)*MAXLINELENGTH);
		
		if(!line)
		{
			printf("Failed to allocate memory.Ending read.\n");
			exit(1);
		}
		
		if(fgets(line,MAXLINELENGTH,fp)==NULL)
		{
			if(!feof(fp))
			{
				printf("File reading ended prematurely.Check for errors in the file.\n");
				exit(1);
			}
			free(new->city);
			free(line);
			free(new);
			fclose(fp);
			break;
		}
		char* tmp = strtok(line,",");//////
		new->zipCode =atoi(tmp);
		tmp=strtok(NULL,",");
		strcpy(new->city,tmp);
		new->city[strlen(tmp)+1]='\0';
		tmp=strtok(NULL,",");
		strcpy(new->state,tmp);
		new->state[2]='\0';
		root = addNode(root,new);
		if(!root)
		{
			printf("Root of tree is still NULL!Ending read.\n");
			exit(1);
		}
		free(line);
	}
	return root;
}

Node* addNode(Node* root,Node* newNode)
{
	if(root==NULL)
	{
		root=newNode;
	}
	else
	{
		if(newNode->zipCode>root->zipCode)
		{
			root->right=addNode(root->right,newNode);
		}
		else
		{
			root->left=addNode(root->left,newNode);
		}
	}
	return root;

}
int findStateCount(Node* root,char* state)
{
	int total=0;
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		if(strcmp(root->state,state)==0)
		{
			total=1;
		}
	}
	return total+findStateCount(root->left,state)+findStateCount(root->right,state);
}
Node* findZipCode(Node* root,int zipCode)
{
	if(root!=NULL)
	{
		if(root->zipCode==zipCode)
			return root;
		Node* left=findZipCode(root->left,zipCode);
		Node* right=findZipCode(root->right,zipCode);
		if(left!=NULL)
			return left;
		if(right!=NULL)
			return right;
	}
	return NULL;
}
void freeTree(Node* root)
{
	if(root!=NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root->city);
		free(root);
	}
}
