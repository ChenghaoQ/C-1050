#include<stdio.h>
#include<stdlib.h>
typedef struct Student
{
	int ID;
	float GPA;
	int creditHoursRemaining;
}Student;

Student readFile(char *filename);
int closestToGraduate(Student* students);






Student readFile(char* filename)
{
	
	Student s,*sPtr;
	
	sPtr = malloc(sizeof(Student)*100);
	static FILE* ofPtr;
	if ((ofPtr = fopen(filename,"r"))==NULL)
	{
		//return 0;
	}
	else
	{
		fscanf(ofPtr,"%d%f%d",&s.ID,&s.GPA,&s.creditHoursRemaining);
	
	}
	fclose(ofPtr);
	sPtr=&s;
	printf("%d %f %d",sPtr->ID,sPtr->GPA,sPtr->creditHoursRemaining);
	return s;
}


int closestToGraduate(Student* students)
{
	



	return 0;
}

int main(int argc,char **argv)
{
	Student *students/*s*/;
	int i;
	
	if (argc<3||argc>3)
	{
		printf("Incorrect number of arguments\n(inputfile,outputfile, lines to read\n");
		return 1;
	}

	int count = atoi(*(argv+2));
	students = malloc(sizeof(Student)* count+1);

	readFile(*(argv+1));
	printf("\n");
	readFile(*(argv+1));

	return 0;
}



	



