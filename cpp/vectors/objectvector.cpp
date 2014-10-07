#include <iostream>
#include "../GenericObjects/AnimalObject.h"
#include <vector>
#include <string>

using namespace std;

int main(){
	cout << "test\n";
	AnimalObject mk("monkey");
	
	vector<AnimalObject> myv;
	myv.push_back(mk);
	myv.push_back(AnimalObject("elephant"));

	myv.push_back(AnimalObject("rabbit"));

	string animallist[] = { "snake", "tiger", "lion", "fish" };

	for ( int i = 0; i < 4; ++i){
		myv.push_back(animallist[i]);
		cout << "animal " << animallist[i] << "\n";

	}	


	for ( int i = 0; i < myv.size(); ++i){
		cout << "Animal: " << ((AnimalObject)myv.at(i)).getName() << "\n";
	}



	return 0;
	
}
