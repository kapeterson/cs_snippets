#include <stdio.h>
#include "msg.h"


int * printmsg_1_svc(char * msg, struct svc_req *req){
	
		static int result = 1;
		printf("We good brah %s\n", msg);
		return (&result);
}

int * squareit_1_svc(int arg1, struct svc_req *req){
	
		static int result;
		result = arg1 * arg1;
		return (&result);
}

int * printdata_1_svc(ldata arg1, struct svc_req *req){
	
	static int result = 1;
	
	printf("K brah called with data type %d\n", arg1.val);
	return (&result);
}