//Chunyang Zhan
//ID 14195522
//Pawprint:czfd6
//lab9
//April 8, 2014
#include "bst.h"
bst *createBST(int a[], int size);
void sort(int a[], int size);
bst *createMinBST(int a[], int start, int end);

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("usage: %s <input_filename>\n", argv[0]);
		return 0;
	}
	
	FILE *in = fopen(argv[1], "r");
	if (in == NULL) return 0;
	
	int i, size;
	fscanf(in, "%d", &size);
	int *array = malloc(size * sizeof(int));
	
	for (i=0; i<size; i++)
		fscanf(in, "%d", &array[i]);
	
	
	//printf("Creating Binary Search Tree...");
	bst *root = NULL;
	root = createBST(array,size);
	//for (i=0; i<size; i++)
	//	root = insert(root, array[i]);
	printTree(root);
	
	//print in-order tree traversal
	printf("In-Order traversal: "); 
	printInorder(root);
	printf("\n"); 
	printf("Pre-Order traversal: ");
	printPreorder(root);
	printf("\n");
	printf("Post-Order traversal: ");
	printPostorder(root);
	printf("\n");
	sort(array,size);
	for(i = 0;i<size;i++)
	{
		printf("%d",array[i]);
	}
	int start = 0;
	int end = size - 1;
	root = createMinBST(array,start,end);
	printTree(root);
	return 0;
}

bst *createBST(int a[], int size)
{
	int i;
	printf("Creating Binary Search Tree...");
	bst *root = NULL; 
        for (i=0; i<size; i++)
        root = insert(root, a[i]);
	return root;
}

void sort(int a[], int size)
{
	int lh, rh, i, temp;
	for(lh = 0;lh<size;lh++)
	{
		rh = lh;
		for(i = lh;i<size;i++)
		{
			if(a[i]<a[rh])
			{
				rh = i;
			}
		}
		temp = a[lh];
		a[lh] = a[rh];
		a[rh] = temp;
	}
}

bst *createMinBST(int a[], int start,int end)
{	
	if(end< start)
	{
		return NULL;
	}
	bst *root=(bst *)malloc(sizeof(bst));
	int middle = (start+end)/2;
	root->val = a[middle];
	root->left = NULL;
	root->right = NULL;
	if(start <= end)
	{
		root->left = createMinBST(a,start,middle-1);
		root->right = createMinBST(a,middle+1,end);
	}
	return root;
}					
