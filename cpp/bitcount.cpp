#include <iostream>

int main(){

	int testint = 12;
	int bitcount = 0;
	int mask = 0x01;

	for(int i = 0; i < 32; i++){
		if ( mask & testint )
		    bitcount++;

		mask = mask << 1;
	}

	std::cout << "Number of set bits " << bitcount << std::endl;
}
