#include <stdlib.h>
#include <stdio.h>


struct mystruct {
	int *pint;
	int myint;
	struct mystruct *next;
};

int main(int argc, char** argv) {

	printf("OK\n");
	char *response = malloc(250);
	free(response);

	struct mystruct *tstruct = malloc(sizeof(struct mystruct));
	tstruct->pint = malloc(sizeof(int));
	tstruct->myint = 5;
	tstruct->next = NULL;

	struct mystruct *tstruct2 = malloc(sizeof(struct mystruct));
	tstruct2->pint = malloc(sizeof(int));
	tstruct2->myint = 4;
	tstruct2->next = tstruct;

	free(tstruct2->pint);
	free(tstruct2);
	
	free(tstruct->pint);
	free(tstruct);

	return 0;
}
