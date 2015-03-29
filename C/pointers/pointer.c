#include <stdio.h>


int main(){	
	int vals[10];
	for ( int i = 0; i < 10; i++)
		vals[i] = i;

	printf("OK\n");
	printf("Val 1 is %d\n", vals[0]);



	int *x = vals;
	for ( int i = 0; i < 10; i++)
		printf("Pringing valud %d -> %d\n", i, *(vals + i));	
	return 0;
}
