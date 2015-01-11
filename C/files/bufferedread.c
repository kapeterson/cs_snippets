#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// Read one character at a time

int main(){

	char buff[128];
	int r = 0;

	int fdesc = open("testfile.txt", O_RDONLY);

	printf ("File desc is %d\n", fdesc);

	while ( (r = read(fdesc, &buff, sizeof(buff)))  > 0 )  {
		printf("%s\n",buff);
	}


	close(fdesc);
	return 0;
}
