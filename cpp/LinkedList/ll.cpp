#include <iostream>


class Node {
	private:
	int value;
	Node *next;
	
	public:
	Node(int val);
	void setNext(Node *node);
	Node* getNext();
	int getVal();
};

int Node::getVal(){
	return value;
}

Node::Node(int val){
	value = val;
	next = NULL;
}

void Node::setNext(Node *node){
	next = node;
}

Node* Node::getNext(){
	return next;
}

class LinkedList {
	private:
	Node *head;
	Node *tail;

	int count;
	public:
	LinkedList();
	int getCount();
	void add(int value);
	Node* getNode(int pos);
	void print();
};

void LinkedList::print(){
	std::cout << "Printing " << std::endl;
	Node *tNode = head;
	while ( tNode != NULL){
		std::cout << "Node value is " << tNode->getVal() << std::endl;
		tNode = tNode->getNext();
	}
}
void LinkedList::add(int value){
	
	Node *newNode = new Node(value);
	if ( 	head == NULL ){
		std::cout << "Just set the frst node to val " << newNode->getVal() << std::endl; 
		head = newNode;
		tail = newNode;
		count++;
	} else {
		count++;
		(tail)->setNext(newNode);
		tail = newNode;
		
	}

}
LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
	count = 0;
}

int LinkedList::getCount(){
	return count;
}

Node* LinkedList::getNode(int pos){
	return (head+pos);
}
int main(){

	std::cout << "Hell othere dolly\n";
        Node mynode(2);	
	LinkedList mylist;
	std::cout << "The initial sizeof the list is " << mylist.getCount() << std::endl;
	mylist.add(1);
	mylist.add(7);
	mylist.add(6);
	std::cout << "Now the size is " << mylist.getCount() << std::endl;
	Node *tNode = mylist.getNode(2);
	std::cout << "The value of it is " << tNode->getVal() << std::endl;
	mylist.print();
	return 0;

	
}
