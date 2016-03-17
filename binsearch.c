#include<stdio.h>
#define SIZE 15

int binarySearch(const intb[],int searchKey, int low,int high);
void printHeader(void);
void printRow(const int[],int low ,int mid,int high);

int main(void)
{
	int a[SIZE];
	int i;
	int key;
	int result;

	for(i=0;i<SIZE;i++){
		a[i] = 2*i
	}

	printf("Enter a number between 0 and 28:");
	scanf("%d",&key);

	printheader();

	result = binarySearch(a,key,0,SIZE -1);
	
	if(result != -1){
		printf("\n%d found in array element %d\n",key,result);
	}
	else{
		printf("\n%d not found\n",key);
	}

	return 0;

int binarySearch(const int b[],int searchKey, int low , int high);
{	
	int middle;
	
	while(low<=high}{
		middle = (low + high)/2;
		printRow(b,low,middle,high);

	if (searchKey == b[middle]){
		return middle;
	}

	else if (searchKey < b[middle]){
		high = middle -1;
	}

	else{
		low = middle +1;
	}
	}
	return -1;
}

void printHeader(void)
{
	int i;
	printf("\nSubscripts:\n");

	for( i =0; i<SIZE ; i++){
		printf("%3d",i);
		if(i<low|| i >high){
			printf("	");
		else if(i ==mid){
			printf("%3d*",b[i]);
		}
		else{
			printf("%3d",b[i])};
		}
	}
	printf("\n");
}

	printf("\n");
