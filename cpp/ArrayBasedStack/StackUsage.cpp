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
	
	StackObject stack = StackObject(4);
	StackObject *pstack;
	pstack = &stack;
	
	pstack->push(1);
	pstack->push(2);
	pstack->push(1001);
	std::cout << "Popping " << pstack->pop() << std::endl;
	return 0;
}
