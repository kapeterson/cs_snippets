#include <iostream>
#include <stdlib.h>
#include <stdio.h>

	
int ARRAY_SIZE = 25;



void merge(int list[], int low, int mid, int high){
	int i, j, k, temp[high];
	i = low;
	k = low;
	j = mid+1;
	
	while ( i < mid && j <=high ) {
		if ( list[i] < list[j] ) {
			temp[k] = list[i];
			i++;
		} else{
			temp[k] = list[j];
			j++;
		}
		k++;	
	}

	while ( i < mid ) {
		temp[k] = list[i];
		i++;
		k++;
	}		

	while ( j <= high ) {
		temp[k] = list[j];
		k++;
		j++;

	}

	for ( i = low; i < k; i++)
		list[i] = temp[i];
}

void mergesort(int list[], int low, int high){
	int mid;
//	std::cout << "weeee";
//	printf("Mergesort low = %d and high = %d", low, high);
	if ( low < high ) {

	//	printf("OK\n");
		mid=(low+high)/2;
		mergesort(list, low, mid);
		mergesort(list, mid+1, high);
		merge(list, low, mid, high);		
	} else {
	} 

	return;
}

int main () {

	int numbers[ARRAY_SIZE];
	for ( int i = 0; i < ARRAY_SIZE; i++){
		numbers[i] = ( rand() % 50 ) + 1;
	}
	

	for ( int i = 0; i < ARRAY_SIZE; i++){
		printf("%d, ", numbers[i]);

	}

	printf("\n");
	
	mergesort(numbers, 0, ARRAY_SIZE-1);

	printf("We printin yo\n\n");

        for ( int i = 0; i < ARRAY_SIZE; i++){
                printf("%d, ", numbers[i]);

        }
	printf("\n\n\n");
	return 0;
}
