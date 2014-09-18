#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

class AnimalObject {

	protected:
	std::string animalname;
	int speed;
	public:
	 AnimalObject(std::string name);
	 std::string getName(){
		return animalname;
	}

	int getSpeed(){
		return speed;
	}	 
};

#endif
