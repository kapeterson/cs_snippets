#include <iostream>
#include <stdio.h>


using namespace std;

int main(){
	typedef unsigned char byte;
	byte myword = 0x01;
	byte myword2 = 0xFE;
	printf("The word is %d\n", (int)myword);	
	byte res;
	res  = myword ^ myword2;
	printf("The XOR val is %d\n", (int)res);
	return 0;
} 
