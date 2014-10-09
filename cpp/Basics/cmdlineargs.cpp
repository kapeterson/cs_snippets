#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


void printUsage(){
	printf("ERROR: Must give a parameter\n");
}

int main(int argc, char* argv[]){

	if ( argc == 1 ) {
	
		printUsage();
		exit(5);
	}

	char *val = argv[1];
	printf("OK br0 we got %d arguments %s \n",argc, val);
	
	return 0;
}
