#include <iostream>
#include "StackObject.h"
using namespace std;


void CreateDummyStack(){
	StackObject stack = StackObject(6);
	for ( int i = 0; i < 3; i++){
		bool res = stack.push(i);
		std::cout << "Pushed item " << i << "  with a result of " << i << "\n";
	}

	int ssize = stack.getStackSize();

	
	std::cout << "\n------\nStack size is " << ssize << "\n";
	for ( int j = 0; j < ssize; j++) {
		int val = stack.pop();
		if ( val >= 0)
			cout << "Popped item " << j << " with value " << val << endl;
		else
			cout << "Could not pop " << std::endl;

	}
}
int main(){
	std::cout << "Hello thar\n";
	StackObject mystack = StackObject(5);
	CreateDummyStack();
	return 0;
}
