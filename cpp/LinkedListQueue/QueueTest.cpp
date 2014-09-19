#include <iostream>
#include "Queue.h"


int main(){
	Node node(5);
	Queue q;
	q.addNode(44);
	q.addNode(5);
	q.addNode(7);
	std::cout << "OK" << std::endl;
	std::cout << "POP: " << q.pop() << std::endl;
	std::cout << "POP: " << q.pop() << std::endl;
	return 0;
}
