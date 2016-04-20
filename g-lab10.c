//Name: Chenghao Qian
//Lab section: G

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int length(char * s);
char* copy(char *s);
int length(char* s);
char* reverse(char *s);
int compare(char *a,char *b);
char* merge(char *a,char *b);
int palindrome(char *a);
int main ()
{
	char *s, *p;
	int i,len=length(s);
	printf("Enter first string: ");
	s=malloc(sizeof(char)*(MAX));
	scanf("%s",s);
	
	
	printf("First string is %s\n Length of the string is %d\n Copy  of string is %s\nReverse of the string %s is %s\n",s,len,copy(s),s,reverse(s));
	printf("Enter a string for compare operation:");
	scanf("%s",p);
	p=malloc(sizeof(char)*length(p));
	if(compare(s,p)!=0){
		if(compare(s,p)>0){
			printf("The string %s is Bigger than %s",s,p);}
		else{
			printf("The string %s is Bigger than %s",p,s);}
	}
	char *a;
	printf("\nEnter a new string for the merge operation:");
	scanf("%s",a);
	a=malloc(sizeof(char)*length(a));
	printf("New merged string is %s",a);

	char *b;
	printf("\nEnter a new string to check for palidrome");
	scanf("%s",b);
	b=malloc(sizeof(char)*length(b));
	if(palindrome(b)==1){
		printf("%s is a palindrome");}
	else{
		printf("%s is not a palindrome");}
	
	
	//clear(p);

	return 0;

}
int length(char *s)
{
	int i=0;
	while (*(s+i)!='\0'){
		i++;
	}
	return i;
}

char* copy(char *s)
{
	char* p;
	int len=length(s),i=0;
	p=malloc(sizeof(char)*(len+1));

	for(i=0;i<len;i++){
		*(p+i)=*(s+i);
	}
	return p;
}

void clear(char *s)
{
	free(s);
}

char* reverse(char *s)
{
	char *p,len=length(s),i,j=0;
	p=malloc(sizeof(char)*len+1);
	
	for(i=len;i>0;i--){
		*(p+j)=*(s+i);
		j++;} /**/
	
	return p;
}
int compare(char *a, char *b)
{
	int i,len=length(a);
	if (len<length(b)){
		len=length(b);
	}

	for(i=0;i<len;i++){
		if(*(a+i)!=*(b+i)){
			return *(a+i)-*(b+i);}}

	return 1;
}

char* merge(char*a,char *b)
{
	char *p;
	int len=length(a)+length(b),i=0,j=0;
	p=malloc(sizeof(char)*len);

	do{
		*(p+j)=*(a+i);
		*(p+j)=*(b+i);
		j+=2;
		i++;
	}while(*(a+i)!='\0' && *(b+i)!='\0');
	while(1){
		if (*(a+i)=='\0' &&*(b+i)!='\0'){
			*(p+j)=*(b+i);
			j++;
			i++;}
		else if (*(b+i)=='\0' && *(a+i) !='\0'){
			*(p+j)= *(a+i);
			j++;
			i++;}
		else
			return p;}
	
}
	
int palindrome(char *a)
{
	if (a==reverse(a))
		return 1;
	else
		return 0;
}
	











































