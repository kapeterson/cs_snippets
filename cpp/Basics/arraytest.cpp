#include <iostream>

using namespace std;

int main(){
	cout << "Hello\n";

	const int MAX_VAL = 5;	
	int myint[MAX_VAL];
	int myval[2];

	for ( int i = 0; i < MAX_VAL; i++)
		myint[i] = i;


	for ( int i = 0; i < MAX_VAL; i++)
		cout << "Value is " << i << "\n";

	return 0;
}
