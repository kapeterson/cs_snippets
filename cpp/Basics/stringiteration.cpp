#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){

	string istring = "hellotheredolly";
	const char* mystring = "dooooo";	
	
	for( int i = 0; i < istring.size(); i++)
		cout << istring.at(i) << "\n";

	printf("Hello there folks\n");	
	return 0;

} 
