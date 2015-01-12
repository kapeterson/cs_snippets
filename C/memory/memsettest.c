#include <stdio.h>
#include <string.h>

#define WORD_SIZE 10

int main(){

	char *word;
	int r = 0x255;

	memset(word, r, WORD_SIZE);
	word[WORD_SIZE] = '\0';

	printf("OK\n\n");
	printf("Memset result is %s\n\n bye",word);
	return 0;
}
