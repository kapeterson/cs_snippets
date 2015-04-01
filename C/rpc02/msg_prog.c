#include <stdio.h>
#include "msg.h"


int * printmsg_1_svc(char * msg, struct svc_req *req){
	
		static int result = 1;
		printf("We good brah %s\n", msg);
		return (&result);
}