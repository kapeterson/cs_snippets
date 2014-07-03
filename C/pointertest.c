#include <stdio.h>

void doit();

int main(){
	int x = 500;
	int *p = &x;

	printf("hello there\n");
	printf("Value of x through the pointer is %d \n", *p);
}



