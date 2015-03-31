#include <stdio.h>
#include "msg.h"


int main(int argc, char **argv){
	
	

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

    /* Creare client handle for calling MESSAGEPROG on the server
     * designated on the command line.  We tell the RPC package
     * to use the tcp protocol when contacting the server.
     */    
    clnt = clnt_create(server, MESSAGEPROG, PRINTMESSAGEVERS, "tcp");
    if (clnt == NULL) {
        /*
         * Couldn't establish connection with server.
         * Print error message and die.
         */
        clnt_pcreateerror(server);
        exit(1);
    }
    
    /* 
     * Call the remote procedure "printmessage" on the server.
     */     
    result = printmessage_1(&message, clnt);
    if (result == NULL) {
        /*
         * An error occurred while calling the server.
         * Print error message and die
         */
        clnt_perror(clnt, server);
        exit(1);
    }
    /*
     * Okay, we successfully called the remote procedure
     */
    if (*result == 0) {
        /*
         * Server was unable to print our message.
         * Print error message and die.
         */
        fprintf(stderr, "%s: %s couldn't print your message\n",
        argv[0], server);
        exit(1);
    }

	printf("Bye\n");
	return 0;
}
