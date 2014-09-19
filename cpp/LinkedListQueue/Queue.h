#include "Node.h"
class Queue {
	private:
		Node *head;
		Node *tail;
		int size;
	public:
		Queue();
		void addNode(int value);
		int pop();
};
