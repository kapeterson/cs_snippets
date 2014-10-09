#include <iostream>
#include <fstream>


using namespace std;

int main(){
	

	ofstream myfile;
	myfile.open("test.txt");
	myfile << "this is a test\n";
	myfile.close();
	return 0;
}
