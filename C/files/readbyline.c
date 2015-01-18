#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// Read one character at a time

int main(){
	char key;
	FILE * fp = fopen("testfile.txt", "r");
	if ( fp == NULL ) {
		printf ("ERROR Opening file\n");
		return 0;
	}
	size_t len = 0;
	ssize_t read;
	char * line = NULL;

	//printf ("File desc is %d\n", fdesc);
	while ( ( read = getline(&line, &len, fp)) != -1) {
		printf("%s",line);
	}
	fclose(fp);
	return 0;
}
