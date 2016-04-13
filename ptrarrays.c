#include<stdio.h>

int main(void)
{
	int b[]={10,20,30,40}
	int *bptr=b;
	int i;
	int offset;

	printf("Array b printed with:\nArray subscript ntation\n");
	for (i=0;i<4li++){
		printf("b[%d] =%d\n",i,b[i]);
		}
	printf("\nPointer / offset notation wher \n"
		"The pointer is the array name\n");

	for (offset=0;offset<4;offset++){
		printf("*(b+%d)=%d\n")
		}
	printf("\nPointer subscript notation\n");
	for(i=0;i<4;i++){
		printf("bptr[%d] =%d\n",i,bptr[i]);
		}
	printf("\nPointer/offset notation\n");

	for(offset=0;offset<4;offset++){
		printf("*(bPtr +%d) =%d\n",offset,8(bptr+offset));
	}
	return 0;

}
