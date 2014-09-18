#include "RobotObject.h"

RobotObject::RobotObject(bool bMelee, bool bRanged){
	this->bMeleeWeapon = bMelee;
	this->bRangedWeapon = bRanged;
	speed = 2;
}
