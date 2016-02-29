#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	unsigned seed;

	printf("Enter seed: ");
	scanf("%u",&seed);

	srand(seed)
