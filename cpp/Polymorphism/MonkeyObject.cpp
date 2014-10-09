#include <stdio.h>
#include "MonkeyObject.h"

MonkeyObject::MonkeyObject() 
	: AnimalObject(4) {

	speed = 66;
}	



void MonkeyObject::run() {
	
	printf("This monkey be runnin at %d steps per minute \n", this->speed);
}	
