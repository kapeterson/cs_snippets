class Node {
	
	private:
	int value;
	Node *next;

	public:
	
	Node(int val);
	int getValue();	
	Node* getNext();
	void setNext(Node *node);

};
