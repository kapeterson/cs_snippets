#include <iostream>

using namespace std;
void modifyMyInt(int *theval){
	cout << "The val is " << *theval << "\n";

	*theval = 555;
}

int main(){
	
	int myint = 3;
	modifyMyInt(&myint);
	cout << "The modified value is " << myint << "\n";
	return 0;
}
