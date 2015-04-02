#include <stdio.h>
#include "msg.h"

int main ( int argc, char **argv){

	CLIENT *clnt;
	int *result;
	char *server;
	char *message;
 
	if (argc != 3) {
		fprintf(stderr, "usage: %s host message\n", argv[0]);
		exit(1);
	}


	server = argv[1];
	message = argv[2];
	printf("SERVER = %s  MSG = %s\n", server, message);

	clnt = clnt_create(server, MESSAGEPROG, PRINTMESSAGEVERS, "tcp");
    if (clnt == NULL) {

        clnt_pcreateerror(server);
        exit(1);
    }
    
    result = printmsg_1(message, clnt);
    if (result == NULL) {
        clnt_perror(clnt, server);
        exit(1);
    }

    if (*result == 0) {

        fprintf(stderr, "%s: %s couldn't print your message\n",
        argv[0], server);
        exit(1);
    }

	int *doublev = squareit_1(5, clnt);
	
	ldata myval;
	myval.val =11;
	myval.size = 22;
	
	char *tstring = "This is the file data";
	
	//myval.data.data_len = strlen(tstring);
	//myval.data.data_val = tstring;
	
	
	FILE *infile;
	infile = fopen("inputfile.txt", "r");
	
	if ( infile == NULL ) {
		printf("Unable to open file brah\n");
		exit(56);
	}
	fseek(infile, 0L, SEEK_END);
	int flen = ftell(infile);
	printf("Len is %d\n", flen);
	fseek(infile, 0L, SEEK_SET);
	myval.data.data_val = (char *)malloc(flen);
	myval.data.data_len = flen;
	
	if ( myval.data.data_val == NULL ) {
		printf("ERROR mallocing data_val\n");
		exit(55);
	}
	
	fread(myval.data.data_val, sizeof(char), flen, infile);
	
	fclose(infile);
	int *d2 = printdata_1(myval, clnt);


	printf("Bye double value is %d\n", *doublev);
	return 0;
	return 0;
}