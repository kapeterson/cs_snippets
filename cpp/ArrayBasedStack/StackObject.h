
class StackObject {

	private:
		int *stack;
		int size;
		int head;
		int currentSize;
	public:
		StackObject(int size);
		~StackObject();

		bool push(int item);
		int pop();
		int getStackSize();
};
