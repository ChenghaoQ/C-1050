#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//You want the age to be greater than the floor
//but less than the ceiling for it to be a match
#define TARGETCEILING 100
#define TARGETFLOOR 80

//Match this year
#define TARGETYEAR 2005

int inRange(char* string);
int inYear(char* string);

int main(void)
{
	//Technically an okay way to initialize strings, but is not 
	//good practice unless you have predetermined strings like here. 
	char a[] = "NAME:John | AGE:83 | DATE:12/13/2014";
	char b[] = "NAME:Sebastion | AGE:4 | DATE:8/2/2005";
	char c[] = "NAME:Steven | AGE:81 | DATE:9/9/2010";
	char d[] = "NAME:Bob | AGE:99 | DATE:3/14/2005";

	//This is me being fancy.
	char* ptr[4]; 
	ptr[0] = a;
	ptr[1] = b;
	ptr[2] = c;
	ptr[3] = d;

	//I am continuing to be fancy.
	int i;
	for(i = 0; i < 4; i++)
	{

		//Look at the output to make sure you are doing things right. 
		//If the output matches what you know to be the correct output,
		//then you're done. 
		printf("String %d ", i+1);
		inRange(ptr[i]) == 1 ? printf("has age.\n") : printf("does not have age.\n");
		printf("String %d ", i+1);
		inYear(ptr[i]) == 1 ? printf("has year.\n") : printf("does not have year.\n");

		printf("\n");
	}

	//For the ones who want more, you can test for strings that 
	//don't match the pattern. They should be denoted as bugs in the data.
	//char e[] = "NAME:joe DATE: 2/2/2014 AGE:30"
	//char f[] = "NAMEasdfyewjrfyokjnxcbvuigerdgf"
	//char g[] = ""
	//char h[] = "NAME:34 DATE:AGE joe:30"

	return 0;
}

//For the following two functinons, test to see if the string 
//contains target values based on the defines at the top of this program.
//You are welcome to use any method you wish (don't shortcut it though).
//There are infinite ways to do this, some messy, some not so messy.

//Even though I say not to shortcut it, you should abuse the fact that
//you know the patterns in the string. That is not shortcutting. For our
//purposes, you can assume there are no outliers to the patterns 
//(but you can try to account for that).


//This function is for the age value in the string.  
//Return the following:
//	1 if the string does have an age in the target range
//	0 if it does not. 
int inRange(char* string)
{
	int i=0,length=strlen(string),age;
	char agestr[3]={'\0'};
	while(i<length)
	{
		if(*(string+i)=='A')
		{
			if(*(string+i+1)=='G')
			{
				if(*(string+i+2)=='E')
				{
					if(*(string+i+3)==':')
					{
						if(*(string+i+4)<=57 && *(string+i+4)>=48&&*(string+i+5)>=48 && *(string+i+5)<=57)
						{
							agestr[0]=*(string+i+4);
							agestr[1]=*(string+i+5);
							if(*(string+i+4)>=48 && *(string+i+6)<=57)
							{
								agestr[2]=*(string+i+6);
							}
							break;
						}
					}
				}
			}
		}
		
							
		i++;
	}
	age=atoi(agestr);
	if(age>TARGETFLOOR && age<TARGETCEILING)
		return 1;
	
	return 0;
}

//This is for the year in the date. 
//Return the following:
//	1 if the string does have the date in the target year
//	0 if it does not. 
int inYear(char* string)
{
	int i,j=0,length=strlen(string),yearnum;
	char year[5]={'\0'};
	for(i=0;i<length;i++)
	{
		if(*(string+i)=='/')
		{
			i++;
			while(j<4)
			{
				if(*(string+i+j)<48 ||*(string+i+j)>57 )
				{

					break;	
				}
				year[j]=*(string+i+j);			
				j++;		
				if(j==4)
				{
					i=length;
				}			

			}
			
		}

	}
	yearnum=atoi(year);
	if(yearnum==TARGETYEAR)
		return 1;
	return 0;
}
