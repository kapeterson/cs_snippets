#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


#define PERM 0666

// Read one character at a time

int main(){

	char buff[128];
	int r = 0;
	char newFileName[] = "bfile.txt";

	int fdesc = open("testfile.txt", O_RDONLY);
	
	int newHandle;

	printf ("File desc is %d\n", fdesc);


	newHandle = open(newFileName, O_RDWR | O_CREAT, PERM);
	if ( newHandle  == -1 ) {
		printf("OH NOES!!\n");
		return 5;
	}	

	while ( (r = read(fdesc, &buff, sizeof(buff)))  > 0 )  {
		printf("%s\n",buff);
		write(newHandle, buff, r);
	}

	close(newHandle);
	close(fdesc);
	return 0;
}
