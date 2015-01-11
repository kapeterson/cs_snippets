#include <stdio.h>
#include <unistd.h>
#include <string.h>



void printUsage(){
	printf("Usage: argest [ -a <inputfile> ] [-b <outputfile> ]\n\n");
	return;
}
int main(int argc, char **argv){



	int c;
	
	char *input = NULL;
	char *output = NULL;

	while ( (c=getopt(argc, argv, ":a:b:")) != -1){
		switch (c){

			case 'a':
				//printf("We got an A = %s\n", optarg);
				input = optarg;
				break;
			case 'b':
				//printf("We got a B\n");
				output = optarg;
				break;
			case '?':
				printUsage();
				return 1;
			
				
			default:
				printf("used the deafult\n");
				break;
				
		}
		//printf ("getopt: %s\n", optarg);
	}

	if ( input == NULL || output == NULL ){
		printf("\nERROR: Input and output file must be specified\n\n");
		printUsage();
		
		return 1;
	}

	printf("Input file is : %s\n", input);
	printf("Output file is : %s\n", output);
	printf("\n\n\n");
	return 0;
}
