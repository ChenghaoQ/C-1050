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
	//setup a root of tree
	Node* root =NULL;
	//open File
	FILE* fp= fopen(filename,"r");
	//File error message
	if(!fp)
	{
		printf("Error opening file.\n");
		return NULL;
	}
	//while loop to read lines
	while(!feof(fp))//read to the end of file,feof test if reach the end
	{
		Node* new= malloc(sizeof(Node));
		if(!new)
		{
			printf("failed to allcate memory.Ending read.\n");
			exit(1);//Quit the program, not return back to main;
		}

		//malloc space for a city name string
		new->city = malloc(sizeof(char)*MAXCITYNAME);
		//test if there is enough memory for city name string
		if(!(new->city))
		{
			printf("Failed to allocate memory.Ending read.\n");
			exit(1);
		}
		//set child's pointer default as NULL
		new->left =NULL;
		new->right = NULL;
		// line is to store the whole line as a string
		char* line = malloc(sizeof(char)*MAXLINELENGTH);
		//test memory just like cityname
		if(!line)
		{
			printf("Failed to allocate memory.Ending read.\n");
			exit(1);
		}
		//read lines to string line and test if read successfully
		if(fgets(line,MAXLINELENGTH,fp)==NULL)
		{
			//if not read successfully, test if reach the end, if not reach the end, file broke,quit program
			if(!feof(fp))
			{
				printf("File reading ended prematurely.Check for errors in the file.\n");
				exit(1);
			}
			//free the variable newly malloced as they didn't get the value
			free(new->city);
			free(line);
			free(new);
			fclose(fp);
			break;
		}

		//****** setup a new Node******
		//tmp stores the splited value  from line {zipcode,cityname,state} 
		char* tmp = strtok(line,",");//strtok split the line(whole string) into tokens ,delete "," and get zipcode as string
		new->zipCode =atoi(tmp);//atoi change tmp from str to int
		tmp=strtok(NULL,",");//tmp get city name(in order to get the next token)
		strcpy(new->city,tmp);//copy city name to new->city
		new->city[strlen(tmp)+1]='\0';//set the terminator
		tmp=strtok(NULL,",");
		strcpy(new->state,tmp);//same as city name
		new->state[2]='\0';
		//add Node to tree
		root = addNode(root,new);
		//test if file is blank, after first adding  Node to tree, root cannot be none 
		if(!root)
		{
			printf("Root of tree is still NULL!Ending read.\n");
			exit(1);
		}
		//free str line after use
		free(line);
	}
	//return the root of a tree
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
