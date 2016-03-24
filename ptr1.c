#include<stdio.h>

int main(void)
{
	int a;
	int *aPtr;
	
	a =7;
	aPtr=&a;

	printf("The address of a is %p\n"
		"The value of aPtr is %p", &a,aPtr);

	printf("\n\nThe calue of a is %d"
		"\nThe value of *aPtr is %d",a,*aPtr);	
	printf("\nShowing that * and & are complement of"
		"each other \n&*aptr =%p"
		"\n*&aPtr =%p\n",&*aPtr,*&aPtr);
	return 0;
}
		
