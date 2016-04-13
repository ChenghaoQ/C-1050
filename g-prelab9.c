#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20


int checkStudentNum(char a[]);
int length(char a[]);

int main(int argc, char** argv) {
	
	char ID[MAX] = {'\0'};
	int checklen, checkdig;

	do {
		printf("Enter the string the Student ID:");
		scanf("%s", ID);
		checklen = length(ID);
		checkdig = checkStudentNum(ID);



		if (checklen < 6 || checklen > 8) {

		printf("Invalid student ID, ID should be of 6-8 digits\n");
		}
		else if (checkdig == 0) {

			printf("Invalid student ID, ID should have all characters as digitals\n");
		}	


	} while (checkdig == 0 || checklen < 6 || checklen > 8);

	return (EXIT_SUCCESS);
	}

int checkStudentNum(char a[]) {
	int len, i;
  	len = length(a);



      	for (i = 0; i < len; i++) {

	if (!isdigit(a[i])) {
		return 0;
	  }

	}
	  return 1;
			  }

int length(char a[]) {

      int len = 0;
	 while (a[len] != '\0') {	
	 len++;
					      }
     return len;

										      }
