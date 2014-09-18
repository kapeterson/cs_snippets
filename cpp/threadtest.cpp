#include <iostream>
#include <thread>

void threadWork(){
	cout << "hello from thread \n";
}

int main(){
	std::thread mythread(threadWork);
	mythread.join();
	
	return 0;
	
}