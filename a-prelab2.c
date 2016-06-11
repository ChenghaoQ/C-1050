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
	int i=0;
	Student **students;
	//students = malloc(sizeof(Student)*100);
	FILE* ofPtr;
	if ((ofPtr = fopen(filename,"r"))==NULL)
	{
		return 0;
	}
	else
	{
		while(fscanf(ofPtr,"%d%f%d",&*(students+i))!=EOF)
		{
			i++;
		}
	
		
		fclose(ofPtr);
	}
	
	printf("%d",students[0]->ID);
	
	return *students;
}


int closestToGraduate(Student* students)
{
	



	return 0;
}

int main(int argc,char **argv)
{
	Student **students/*s*/;
	int i;
	
	if (argc<3||argc>3)
	{
		printf("Incorrect number of arguments\n(inputfile,outputfile, lines to read\n");
		return 1;
	}

	int count = atoi(*(argv+2));
	students = malloc(sizeof(int)*2*count+sizeof(float)*count);

	*students=readFile(*argv+1);
	for(i=0;*(students+i)!='\0';i++)
	{		
		printf("%d %f %d\n",*(students+i));
	}
	if(*(students+5)!=NULL)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO");
	}
	printf("%d %f %d\n",*(students));
	printf("%d %f %d\n",*(students+1));
	printf("%d %f %d\n",*(students+2));
	printf("%d %f %d\n",*(students+3));
	//printf("---%d----",students->ID);

	return 0;
}



	



