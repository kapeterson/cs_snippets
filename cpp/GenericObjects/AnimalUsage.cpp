#include <iostream>
#include "AnimalObject.h"
#include "EnemyObject.h"
#include "MonkeyObject.h"

int main(){
	std::cout << "Hello\n";
	AnimalObject thisAnimal = AnimalObject("monkey");
	thisAnimal = MonkeyObject();
	EnemyObject theEnemy = EnemyObject("Hunter");
 	AnimalObject nextAnimal("lion");	
	std::cout << "Animal name is " << thisAnimal.getName() << std::endl;
	std::cout << "Animal " << thisAnimal.getName() << " has enemy " << theEnemy.getName() << std::endl;
	return 0;
}
