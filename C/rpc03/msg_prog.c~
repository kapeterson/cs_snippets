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
	printf("We good\n");
	//printf("K brah called with data type %d\n", arg1.val);
	printf("Da data in da struct is \n------------\n%s\n", (char *)arg1.data.data_val);
	FILE *ofile;
	ofile=fopen("tempout.txt", "wb");
	
	if ( ofile == NULL ) {
	
		printf("Unable to open outputfile\n");
		exit(44);
	}
	fwrite(arg1.data.data_val, 1, arg1.data.data_len, ofile);
	fclose(ofile);
	return (&result);

}