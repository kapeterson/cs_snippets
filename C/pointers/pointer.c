#include <stdio.h>
#define ARRAY_SIZE 128

int main(){	
	int vals[ARRAY_SIZE];
	for ( int i = 0; i < ARRAY_SIZE; i++)
		vals[i] = i;

	printf("OK\n");
	printf("Val 1 is %d\n", vals[0]);



	int *x = vals;
	for ( int i = 0; i < ARRAY_SIZE; i++)
		printf("Pringing valud %d -> 0x%02x\n", i, *(x + i));	


	printf("The val is 0x%02x\n",*(x+15));
	return 0;
}
