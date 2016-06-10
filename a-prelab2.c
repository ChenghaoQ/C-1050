#include<stdio.h>
#include<stdlib.h>
Student* readFile(char *filename);
int closestToGraduate(Student* students);


typedef struct s_
{
	int ID;
	int GPA;
	int creditHoursRemaining;
}Student;










Student* readFile(char* filename)
{
	int i=0;
	FILE ofPtr;
	if ((ofPtr = fopen(filename,"r"))==NULL)
	{
		return 0;
	}
	else
	{
		while (getc(ofPtr)!=EOF)
		{
			fscanf(ofPtr,"%d%f%d",&*(students+i)->ID,&*(students+i)->GPA,&*(students+i)->creditHoursRemaining);
			i++;
		}
	
		fclose(ofPtr);
	/*------------------------------*/
	}
}


int closestToGraduate(Student* students)
{
	



	return 0;
}

int main(argc.**argv)
{
	Student *students/*s*/;
	
	if (argc<5||argc>5)
	{
		printf("Incorrect number of arguments\n(inputfile,outputfile, lines to read\n");
		return 1;
	}

	int count = atoi(*(argv+3));
	s = malloc(sizeof(int)*2*count+sizeof(float)*count);
	readFile(*(argv+1));



	



