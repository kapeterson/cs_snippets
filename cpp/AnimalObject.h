#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

class AnimalObject {

	protected:
	std::string animalname;

	public:
	 AnimalObject(std::string name);
	 std::string getName(){
		return animalname;
	}	 
};

#endif
