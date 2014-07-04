#include <stdio.h>
#include <stdlib.h>

/* 
 *
 *
 *
 *
 *
 *
 */
int main(int argc, char** arv){
        
        printf("malloc test\n");

	int* a = malloc(2 * sizeof(int));
	int* b = malloc(2 * sizeof(int));
	printf("Location of a %p\n",a);
	printf("location of b %p\n",b);
	*a = 5;
	*b = *a;
		
	free(a);
	*b = 6;
	a = b;
	printf("location of a %p\n",a);
	printf("value of a is %d\n",*a);
        printf("now allocate more for c\n");
	int* c = malloc(sizeof(int));
	printf("location of c %p\n",c);
	free(c);
	free(a);	
	
}

