#include <iostream>


int main(){
	

	int n = 10;
	int first = 0;
	int second = 1;
	int next = 1;

	for( int i = 0; i < n; i++){
		if ( i <= 1 ) 
			next = i;
		
		else {
			next = first + second;
			first = second;
			second = next;
		}
		std::cout << next << std::endl;
	}
	return 0;
}
