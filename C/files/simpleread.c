#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// Read one character at a time

int main(){
	char key;
	int fdesc = open("testfile.txt", O_RDWR);
	printf ("File desc is %d\n", fdesc);
	while ( sizeof(char) == read(fdesc, &key, sizeof(char) )) {
		printf("%c",key);
	}
	return 0;
}
