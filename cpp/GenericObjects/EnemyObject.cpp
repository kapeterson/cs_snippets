#include "EnemyObject.h"

EnemyObject::EnemyObject(std::string name){
	this->name = name;	
}

std::string EnemyObject::getName(){
	return name;
}
