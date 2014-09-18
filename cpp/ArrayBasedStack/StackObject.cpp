#include <iostream>
#include "StackObject.h"

StackObject::StackObject(int sz){
	head = -1;
	size = sz;
	stack = new int[size];
	currentSize = 0;
	
}

StackObject::~StackObject(){
	std::cout << "Destructing Array Based Statck\n";
	delete stack;
}


// increment the head and push the item there... item now points to the last item
// on the stack
bool StackObject::push(int itemtopush){
	if ( head < size ) {
		head++;
		stack[head] = itemtopush;

		//std::cout << "head  is now " << head << std::endl;		
		return true;
	} else {
		return false;
	}	
}

// remove the head
int StackObject::pop(){
	int res = -1;
	//std::cout << "\thead is " << head << std::endl;
	if ( head >= 0 && head < size){
		//std::cout << "val is " << stack[head] << std::endl;
		res = stack[head];
		head--;
		//std::cout << "head is now " << head << std::endl;

	} 
	//std::cout << " returning " << res << std::endl;
	return res;
}

int StackObject::getStackSize(){
	return (head+1);
}
