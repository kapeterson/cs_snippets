#include <stdio.h>
#include "magickminify.h"

int main(){

	FILE *ifile = fopen("paraglider.jpg","r");
	if ( ifile == NULL ) {

	printf("ERROR: Unable to open file\n");
	exit(44);
	}

	 fseek(ifile, 0L, SEEK_END);
	int flen = ftell(ifile);
	printf("Len is %d\n", flen);

	fseek(ifile, 0L, SEEK_SET);

	char *data = (char *)malloc(flen);
	fread(data, sizeof(char), flen, ifile);
	magickminify_init();

	printf("OK\n\n");
	
	ssize_t newlen = flen / 2;
	char *wee = magickminify(data, flen, &newlen);	


	magickminify_cleanup();

	fclose(ifile);


	FILE *ofile;
	ofile = fopen("newfile.jpg", "wb");

	if ( ofile == NULL ) {
	printf("ERROR: Unable to open file\n");
	exit(45);
	}

	fwrite(wee, 1, newlen, ofile);

	free(data);
	return 0;
}
