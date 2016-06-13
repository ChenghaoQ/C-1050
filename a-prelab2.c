#include<stdio.h>
#include<stdlib.h>
typedef struct Student
{
	int ID;
	float GPA;
	int creditHoursRemaining;
}Student;

Student* readFile(char *filename);
int closestToGraduate(Student* students);






Student* readFile(char* filename)
{
	
	Student *s;
	s=malloc(sizeof(Student)*300);
	int i=0;
	FILE* ofPtr;
	if ((ofPtr = fopen(filename,"r"))==NULL)
	{
		return NULL;
	}
	else
	{
		while(fscanf(ofPtr,"%d%f%d",&(*(s+i)).ID,&(s+i)->GPA,&s[i].creditHoursRemaining)!=EOF)
		{
			//Three ways to express s[i]
			//printf("%d %f %d\n",(*(s+i)).ID,(s+i)->GPA,s[i].creditHoursRemaining);
			
			i++;
			
		}
		
	}
	fclose(ofPtr);

	return s;//return a pointer of array s
}


int closestToGraduate(Student* students)
{
	int closest=(*(students+0)).creditHoursRemaining;
	int idnum=(*(students+0)).ID;
	int i;
	while((*(students+i)).ID!='\0')
	{
		if((*(students+i)).creditHoursRemaining<closest)
			closest = (*(students+i)).creditHoursRemaining;
			idnum = (*(students+i)).ID;
		
		i++;
	}


	return idnum;
}

int main(int argc,char **argv)
{
	Student *a/*s*/;
	int i;
	
	if (argc<2||argc>2)
	{
		printf("Incorrect number of arguments\n(inputfile only\n");
		return 1;
	}

	
	a = malloc(sizeof(Student)* 300+1);
	a=readFile(*(argv+1));
	
	while((*(a+i)).ID!='\0')
	{
		printf("%d %f %d\n",a[i].ID,a[i].GPA,a[i].creditHoursRemaining);
		i++;	
	}
	printf("\n\nThe student who is closest to graduate has ID#: %d",closestToGraduate(a));
	return 0;
}



	



