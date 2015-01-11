#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define PERM 0666
int main(int argc, char *argv[]){

	char fname[] = "newfile.txt";
	char a[] = "testthissuff dude what yall\n";
	int newfile;
	int writeerror;

	//printf("OK file = %s\n\n", fname);
	
	char inputFile[100];
	printf("Enter name of the new file to write to: ");
	fgets(inputFile, 100, stdin);
	printf("The file name input from user is %s\n", inputFile);

	inputFile[strlen(inputFile) -1] = '\0';

	newfile = open(inputFile, O_RDWR | O_CREAT, PERM);
	if ( newfile  == -1 ) {
		printf("OH NOES!!\n");
		return 5;
	}	

	int i = 0;
	while ( i < 5 ) {
	writeerror = write(newfile, a, sizeof(a));

	if ( writeerror   != sizeof(a) ) {
		printf ("Errror writing to file yo: %d \n", writeerror);
	}
	i++;
	}

	printf("Result of closing file = %d\n\n:", close(newfile));

	return 0;
}
