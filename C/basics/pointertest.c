#include <stdio.h>

int main(int argc, char** arv){
	int x;
	int *p;
	p = &x;
	x = 4;
	printf("Value of p is %d \n", *p);  
}
