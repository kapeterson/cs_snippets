#include <iostream>
#include "Node.h"

Node::Node(int val){
	value = val;
	next = NULL;
}

int Node::getValue(){
	return value;
}

void Node::setNext(Node *node){
	next = node;
}

Node* Node::getNext(){
	return next;
}
