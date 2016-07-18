//Chenghao Qian
#include <stdio.h>
#include <stdlib.h>

//Your structure. 
typedef struct n_
{
	int num;
	struct n_* left;
	struct n_* right;
} Node;

//Your prototypes
Node* addNodeToTree(Node* root, int x);
void printTree(Node* root);
int calcPrint(Node* root, int is_left, int offset, int depth, char s[20][255]);
void freeTree(Node* root);
void printSortedList(Node* root);
Node* removeLeaves(Node* root);
Node* flipTree(Node* root);
//Your main
int main(void)
{
	//this clears the screen. Useful!
	system("clear");	
	//Keeps track of the root of the tree at all times.
	Node* root = NULL;
	int selection;
	while(1)
	{
		printf("1: add a node\n2:remove leaves\n3:flip tree\n-1:quit\n>");
		scanf("%d",&selection);
		if(selection==-1) 
			break;
		switch(selection)
		{
			case 1:
				printf("Add a node (-1 to quit): ");
				int x;
				scanf("%d", &x);
				root = addNodeToTree(root, x);
				break;
			case 2:
				root=removeLeaves(root);
				break;
			case 3:
				root=flipTree(root);
				break;
		}
			
			
		system("clear");	
		printTree(root);
		printSortedList(root);
		printf("\n");
	}
	
	//Free it all up
	freeTree(root);
	return 0;
}

//COMPLETE ME
Node* addNodeToTree(Node* root, int x)
{
	Node* new;
	new=malloc(sizeof(Node));
	if(new!=NULL)
	{
		new->num=x;
		new->left=NULL;
		new->right=NULL;
	}


	if(root==NULL)
	{
		root=new;
	}
	else
	{	if(x>root->num)
		{	
			free(new);
			root->right=addNodeToTree(root->right,x);
		}
		else
		{
			free(new);
			root->left=addNodeToTree(root->left,x);
		}
	}

	return root;
}

void printSortedList(Node* root)
{
	if(root!=NULL)
	{
		printSortedList(root->left);
		printf("%d ",root->num);
		printSortedList(root->right);
	}
}
//COMPLETE ME TOO 
Node* removeLeaves(Node* root)
{
	if(root!=NULL)
	{
		if(root->left == NULL && root->right ==NULL)
		{
			free(root);
			return NULL;
		}
		else
		{
			root->left=removeLeaves(root->left);
			root->right=removeLeaves(root->right);
		}
	}
	return root;
}
Node* flipTree(Node* root)
{
	Node* temp;
	if(root!=NULL)
	{
		root->left=flipTree(root->left);
		root->right=flipTree(root->right);

		temp=root->left;
		root->left=root->right;
		root->right=temp;
	
	}
	return root;
}
void freeTree(Node* root)
{
	if(root!=NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}	
}

//DON'T TOUCH UNLESS YOU WANT TO EXPERIMENT
int calcPrint(Node* root, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
    int width = 5;
	
 	if (!root) return 0;
    sprintf(b, "(%03d)", root->num);
	int left  = calcPrint(root->left,  1, offset, depth + 1, s);
    int right = calcPrint(root->right, 0, offset + left + width, depth + 1, s);

	int i;
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {
        for (i = 0; i < width + right; i++)
	       s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }

	return left + width + right;
}

//SAME AS THE FUNCTION ABOVE
void printTree(Node* root)
{
	char s[20][255];
	int i;
	for(i = 0; i < 20; i++)
		sprintf(s[i], "%80s", " ");
	
	calcPrint(root, 0, 0, 0, s);
	for(i = 0; i < 20; i++)
	{
		printf("%s\n", s[i]);
	}

}
