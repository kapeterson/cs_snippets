#include <stdio.h>
#include <string.h>


int main(int argc, const char* argv[]){

	printf("W ok \n");

	char buff[15];
	int pass = 0;
	int b = 2;
	printf("Location of char is %p\n", buff);
	printf("Location of pass is %p\n", &pass);
	printf("location of    b is %p\n", &b);
	printf("Originally pass = %d\n",pass);
	printf("Please enter password : \n");
	gets(buff);

	printf("Password entered is %s\n",buff);
	printf("Now pass is %d\n", pass);

}
