#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int ARRAY_NUM = 20;





int selectionsort(int *list, int size ){

	for ( int i = 0; i < size; i++){
		int minposition = i;
		int minvalue = list[i];
		int thisvalue = list[i];

		for ( int j = i+1; j < size; j++){
			if ( list[j] < minvalue ) {
				minposition = j;
				minvalue = list[j];
			}

			
			if ( minvalue < list[i] ){
				int tempvalue = list[minposition];
				list[minposition] = list[i];
				list[i] = tempvalue;
			}
		}
	}
	
}


int main(){
	
	int numbers[ARRAY_NUM];
	for(int i =0; i < ARRAY_NUM;i++){
		numbers[i] = (rand() % 20) + 1;
	}	

	printf("\nPrinting random values\n");

	for ( int j = 0; j < ARRAY_NUM;j++){
		printf("%d, ", numbers[j]);
	}	


	printf("\nSelect sorting it now \n");
	selectionsort(numbers, ARRAY_NUM);


        printf("\nPrinting soprted values\n");

        for ( int j = 0; j < ARRAY_NUM;j++){
                printf("%d, ",  numbers[j]);
        }
	printf("\n");
}
