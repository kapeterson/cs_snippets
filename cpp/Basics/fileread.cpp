#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;


int main(){
	string line;
  	ifstream myfile("test1.txt");
	while ( getline(myfile, line)){

		cout << line << "\n";	
	}
	return 0;
}
