#include <iostream>
#include <stdio.h>
#include <thread>
#include <mutex>

using namespace std;

mutex t_mutex;

void doWork(){
	t_mutex.lock();
	cout << "did it\n\n\n";
	t_mutex.unlock();

}


int main(int argc, char* argv[]){
	
	printf("hello\n");	
	
	thread t1(doWork);

	t1.join();
	return 0;

}
