#include <stdio.h>
#include <stdlib.h>

// Simple program with malloc errors.  You can see them in valgrind with
// valgrind --tool=memcheck -v --leak-check=full --track-origins=yes ./<file>
int main(int argc, char** arv){
        
        printf("malloc test\n");

	int* a = malloc(2 * sizeof(int));
	int* b = malloc(2 * sizeof(int));
	printf("Location of a %p\n",a);
	printf("location of b %p\n",b);


	free(a);
	free(b);	
	
}

