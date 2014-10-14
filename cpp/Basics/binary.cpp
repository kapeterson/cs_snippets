#include <iostream>


using namespace std;

int main(){

	int bytemask = 0xFF;	
	char maxval = 0x01;
	int newval = (~maxval & bytemask);
	cout << "The not value is " << (int)newval << "\n";
 	int val2 = 0x03;
	cout << "XOR val2 = " << (( ^val2) & bytemask) << "\n";		
	return 0;
}
