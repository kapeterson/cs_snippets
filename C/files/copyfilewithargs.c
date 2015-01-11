#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define PERM 0666

void printUsage(){
	printf("Usage: copyfilewithargs [ -i <inputfile> ] [-o <outputfile> ]\n\n");
	return;
}

int main(int argc, char *argv[]){

	char buffer[100];
	int chars = 0;
	
	
	char *input = NULL;
	char *output = NULL;
	int c;
	
	int sourceFile, destFile;
	
	while ( (c=getopt(argc, argv, ":i:o:")) != -1){
		switch (c){

			case 'i':
				input = optarg;
				break;
			case 'o':
				output = optarg;
				break;
			case '?':
				printUsage();
				return 1;
			
				
			default:
				printf("used the deafult\n");
				break;
				
		}
	}
	
	
	if ( input == NULL || output == NULL ){
		printf("\nERROR: Input and output file must be specified\n\n");
		printUsage();
		
		return 1;
	}
	
	printf("Using input file: %s\n", input);
	printf("Using output file: %s\n", output);
	
	
	sourceFile =  open(input, O_RDONLY);
	
	if ( sourceFile  == -1 ) {
		printf("ERROR Opening source file!!\n");
		return 5;
	}	
	
	destFile = open(output, O_RDWR | O_CREAT, PERM);
	if ( destFile  == -1 ) {
		printf("ERROR creating new file!!\n");
		return 5;
	}	

	
	while ( (chars = read(sourceFile, &buffer, sizeof(buffer)))  > 0 )  {
		//printf("%s\n",buffer);
		write(destFile, buffer, chars);
	}

	printf("Finished writing contents of %s to %s\n\n", input, output);
	close(sourceFile);
	close(destFile);
	return 0;
}
