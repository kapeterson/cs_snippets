#include <stdio.h>
#include "msg.h"


int * printmessage_1_svc(char **msg, struct svc_req *req){

	static int result = 1;
	printf("Weeeeeeeeeeeeeeeeeeee\n");
	return (&result);
} 
