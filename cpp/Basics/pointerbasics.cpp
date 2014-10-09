#include <iostream>
#include <cstdio>

int main(){
	int *pInt;
	int *qInt = new int;
	int v = 4;
	int w = 66;

	pInt = &v;
	*qInt = 44;
	std::cout << "Value at the pionter is " << *pInt << std::endl;
	*pInt = 77;
	std::cout << "Value is now " << *pInt << std::endl;

	std::cout << "qInt is " << *qInt << "\n";
	printf("hello %p\n", qInt);

	delete qInt;
	return 0;
}



