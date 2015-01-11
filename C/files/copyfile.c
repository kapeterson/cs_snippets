#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define PERM 0666
int main(int argc, char *argv[]){


	char a[] = "This is s atest\n";
	int sourceHandle;
	int newHandle;
	int writeerror;


	//printf("OK file = %s\n\n", fname);
	
	char sourceFileName[100];
	char newFileName[100];

	printf("Enter name of the source file: ");
	fgets(sourceFileName, 100, stdin);


	printf("Enter the name of the new file: ");
	fgets(newFileName, 100, stdin);

	

	sourceFileName[strlen(sourceFileName) -1] = '\0';
	

	newFileName[strlen(newFileName) -1] = '\0';

	printf("Source file: %s\n", sourceFileName);
	printf("New file: %s\n", newFileName);
	
	printf("Creating file %s\n", newFileName);

	newHandle = open(newFileName, O_RDWR | O_CREAT, PERM);
	if ( newHandle  == -1 ) {
		printf("OH NOES!!\n");
		return 5;
	}	

	int i = 0;
	while ( i < 5 ) {
	writeerror = write(newHandle, a, sizeof(a));

	if ( writeerror   != sizeof(a) ) {
		printf ("Errror writing to file yo: %d \n", writeerror);
	}
	i++;
	}

	printf("Result of closing file = %d\n\n:", close(newHandle));

	return 0;
}
