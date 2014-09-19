#include <iostream>
#include <stdio.h>

int main(){

	int n;
	std::cout << "Enter something: ";
	scanf("%d", &n);
	std::cout << "Entered value " << n << std::endl;

	std::string mystring;
	std::cout << "enter another : " ;
	std::cin >> mystring;
	std::cout << "Entered string " << mystring << std::endl;
	return 0;

}
