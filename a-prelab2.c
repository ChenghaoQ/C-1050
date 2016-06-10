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
	FILE ofPtr;
	if ((ofPtr = fopen(filename,"r"))==NULL)
	{
		return 0;
	}
	else
	{
		/*------------------------------*/
	}
}


int closestToGraduate(Student* students)
{
	



	return 0;
}

int main(argc.**argv)
{
	Student students,*s;
	m




