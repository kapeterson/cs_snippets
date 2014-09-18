#include "RobotMonkeyObject.h"
#include <iostream>


int main(){
	std::cout << "RobotMonkey son" << std::endl;
	RobotMonkeyObject rbt = RobotMonkeyObject();
	std::cout << "RobotMOnkey speed = " << rbt.getSpeed() << std::endl;
	std::cout << "Robot Monkey has melee = " << rbt.hasMeleeWeapon() << std::endl;

	return 0;	
}
