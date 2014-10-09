#include <iostream>

class TestClass {
	private: 
	
	int value;
		
	public:
	TestClass();
	
	int getValue();
	void setValue(int valuetoset);
};

void TestClass::setValue(int val){
	value = val;
}
TestClass::TestClass(){
	value = 5;
}

int TestClass::getValue(){
	return value;
}


int main(){
	TestClass myclass;
	std::cout << "The start value is " << myclass.getValue() << std::endl;
	myclass.setValue(100);
	std::cout << "The end value is " << myclass.getValue();

	return 0;
}