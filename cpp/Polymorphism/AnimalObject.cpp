#include "AnimalObject.h"
#include <stdio.h>

AnimalObject::AnimalObject(){
	this->speed = 3;
}

AnimalObject::AnimalObject(int sp){
	this->speed = sp;
}

void AnimalObject::run(){
	printf("This animal be running at %d steps per minute\n", this->speed);
}
