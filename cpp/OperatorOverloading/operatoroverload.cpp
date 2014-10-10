#include <iostream>
#include <stdio.h>

class MyClass {

	private:
	 int age;
	public:
	MyClass(){
		age = 3;
	}

	MyClass(int theage){
		age = theage;
	}

	int getAge(){
		return age;
	}

	//MyClass operator+(const MyClass& p1){
	//	return MyClass(this->age + p1.age);
	//} 

	friend MyClass operator+(MyClass& p1, MyClass& p2);
	friend bool operator==(MyClass& comp, MyClass& comp2);


};

MyClass operator+(MyClass& p1, MyClass& p2){
	return MyClass(p1.age + p2.age);
}

    bool operator==(MyClass& comp, MyClass& comp2){
                return ( comp2.age == comp.age);
        }


int main(){
	printf("Hello there dolly\n");

	MyClass me;
	MyClass you;
	printf("My age is %d\n",me.getAge());
	you = me + you;
	printf("The new age is %d\n", you.getAge());

	MyClass oldDude(100);
	MyClass youngDude(13);
	MyClass olderDude = oldDude + youngDude;
	printf("The older dude age is %d\n", olderDude.getAge());
	me = MyClass(113);
	bool res = (olderDude == me);
	printf("The two are equal = %d\n", res);
	
	MyClass* classp = new MyClass(500);

	printf("class pointer age is %d\n",classp->getAge());
	printf("the addr of it is %p\n", classp);
	delete classp;
	return 0;	
}
