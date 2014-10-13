#include <iostream>
#include <stdio.h>
#include <stdlib.h>



int ARRAY_SIZE = 8;



void quicksort(int list[], int left, int right){

	int i = left, j = right;
	int tmp;
	int pivot = list[(left + right) /2];

	/* partition */
	while ( i <= j ) {

		while ( list[i] < pivot ) {
			i++;


		}
	
		while ( list[j] > pivot){
			j--;
		}

		if ( i < j ) {
			printf("Pivot = %d  i = %d j = %d \n", pivot, i, j);
			tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;
			i++;
			j--;
		}
	}

	/* recursion */
	if ( left < j ) 
		quicksort(list, left, j);
	if ( i < right ) 
		quicksort(list, i, right );	
}


void printlist(int list[]){
	for ( int i = 0; i < ARRAY_SIZE; i++)
		printf("%d, ", list[i]);

	printf("\n");
}
int main (){

	int numbers[ARRAY_SIZE];

	for ( int i = 0 ; i < ARRAY_SIZE; i ++){
		numbers[i] = (rand() % 50 );
	}

	printlist(numbers);
	printf("\n\n");
	quicksort(numbers, 0, (ARRAY_SIZE-1));
	printlist(numbers);
	return 0;
}
