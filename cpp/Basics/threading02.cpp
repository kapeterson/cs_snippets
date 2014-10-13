#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdlib.h>

using namespace std;


void threadWork(){
	for ( int i = 0; i < 6; i++){
		std::cout << "hello from thread " << this_thread::get_id() << " " << i << " \n";
		sleep((rand() % 5) + 1);


		}
}

int main(){
	std::thread mythread(threadWork);
	std::thread dthread(threadWork);
	
	int mysleep = ( rand() % 5 ) + 1;
	cout << "sleep is " << mysleep << "\n";
	mythread.join();
	dthread.join();
	return 0;
	
}
