#include <stdio.h>
#include <stdlib.h>

struct mystruct {

	int value;

};

int main(){
	printf("OK\n\n");
	struct mystruct *tstruct = (struct mystruct*)malloc(sizeof(struct mystruct));

	tstruct->value = 5;

	printf("The value is %d\n\n", tstruct->value);
	free(tstruct);
	return 0;
}
