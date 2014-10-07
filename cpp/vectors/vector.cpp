#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	std::cout << "Hello\n";
	std::vector<int> tvect(3,100);
	std::vector<int>::iterator it;

	tvect.push_back(12);
	tvect.push_back(55);


	for(it = tvect.begin(); it < tvect.end();it++){
		std::cout << *it << "\n";
	}	

	std::string mystring = "hello";
	
	std::vector<std::string> myvect(3, "test");
	myvect.push_back("testitson");	

	std::cout << "weeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeE";	
	
	std::cout << "The size is " << myvect.size() << "\n";	

	for ( int tt = 0; tt < myvect.size(); ++tt){
		cout << "String: " << myvect.at(tt) << "\n";
	}

	for ( std::vector<std::string>::iterator tt = myvect.begin(); tt < myvect.end(); ++tt){
		cout << "S: " << *tt << "\n";
	}


	vector<char> cVect(3,'a');
	cVect.push_back('z');

	for ( std::vector<char>::iterator tt = cVect.begin(); tt < cVect.end(); ++tt){
		cout << "Char: " << *tt << "\n";
	}
	return 0;
}
