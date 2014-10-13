#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int ARRAY_SIZE = 30;


void moveToPosition(int *list){

}


void insertionSort(int *list, int size){
	
	for ( int i = 0; i < size; i++){
		printf("Checking position %d\n",i);		
		int thispos = i;
		while ( thispos > 0) {

			if ( list[thispos] < list[thispos-1] ) {
				int tempval = list[thispos];
				list[thispos] = list[thispos-1];
				list[thispos-1] = tempval;
				thispos = thispos -1;

			} else {
				break;
			}
		}
	
	}
}
int main(){

	int numbers[ARRAY_SIZE];
	for(int i = 0; i < ARRAY_SIZE; i++)
		numbers[i] = (rand() % 50 ) + 1;



	for ( int i = 0; i < ARRAY_SIZE; i++)
		printf("%d, ", numbers[i]);

	printf ("\n");

	insertionSort(numbers, ARRAY_SIZE);

	printf("\n\n");


        for ( int i = 0; i < ARRAY_SIZE; i++)
                printf("%d, ", numbers[i]);


	printf("\n\n");
	return 0;
}
