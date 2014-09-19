#include <iostream>


int main(){
	int *pInt;
	int v = 4;
	pInt = &v;
	std::cout << "Value at the pionter is " << *pInt << std::endl;
	*pInt = 77;
	std::cout << "Value is now " << *pInt << std::endl;
}


