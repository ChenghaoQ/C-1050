#include <stdio.h>
#include <stdlib.h>

typedef struct bt_{
	int value;
	struct bt_ *right;
	struct bt_ *left;
}BST;

BST* insert(BST* root,int value);
void printTree(BST* root);
void displayBST(BST* root,int depth);
void padding(char toPrint, int numTimes);
int search(BST* root,int value);
BST* findNearest(BST* root,int value);

int main(int argc,char* argv[])
{
	FILE *fp;
	if(argc!=2)
	{
		printf("Incorrect number of command line argument\n");
	}
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("unable to open the file\n");
	}


	BST* root = NULL;
	int value;
	int key;
	int mark;
	while(fscanf(fp,"%d",&value)!=EOF)
	{
		root = insert(root,value);
	}
	printTree(root);
	printf("Enter a number to search for in the tree:");
	scanf("%d",&key);
	mark = search(root,key);
	if(mark == 1)(
	{
		printf("%d was found\n",key);
	}
	if(mark == 0)
	{
		printf("%d was not found\n",key);
	}
	int find;
	printf("Enter a number to search for in the tree:");
	scanf("%d",&find);
	findNearest(root,find);
	return 0;
}

BST* insert(BST* root, int value)
{
	BST* p = (BST *)malloc(sizeof(BST));
	p->value = value;
	p->left = NULL;
	p->right = NULL;
	if(root == NULL)
	{
		root=p;
	}
	else
	{
		if(value<root->value)
		{
			root->left=insert(root->left,value);
		}
		if(value>root->value)
		{
			root->right=insert(root->right,value);
		}
	}
	return root;
}

int search(BST* root, int value)
{
	if(root == NULL)
	{
		return 0;
	}
	if(value == root->value)
	{
		return 1;
	}
	else
	{
		if(value<root->value)
		{
			return search(root->left,value);
		}
		if(value>root->value)
		{
			return search(root->right,value);
		}
	}
}

BST* findNearest(BST* root,int value)
{
	if(value == root->value)
	{
		printf("the nearest number to %d is %d\n",value,root->value);
		return root;
	}
	if(value<root->value&&root->left==NULL)
	{
		printf("the nearest number to %d is %d\n",value,root->value);
		return root;
	}
	else if(value>root->value&&root->right==NULL)
		{
			printf("the nearest number to %d is %d\n",value,root->value);
		return root;
		}
	else
	{
		if(value<root->value)
		{
			root->left = findNearest(root->left,value);
		}
		if(value>root->value)
		{
			root->right = findNearest(root->right,value);
		}
	}	
}

void printTree(BST* root)
{
	displayBST(root, 0);
}

void displayBST(BST* root, int depth)
{
	if (root == NULL)
	{
		padding(' ', depth);
		printf("-\n");
		return;
	}

	displayBST(root->right, depth+4);
	padding(' ', depth);
	printf("%d\n", root->value);
	displayBST(root->left, depth+4);
}

void padding(char toPrint, int numTimes)
{
	int i;
	for (i = 0; i < numTimes; i++)
		printf("%c", toPrint);
}


