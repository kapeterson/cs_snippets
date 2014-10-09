#include <iostream>
#include "AnimalObject.h"
#include "MonkeyObject.h"

void printRun(AnimalObject *animal){

	animal->run();
}
int main(){
	AnimalObject myanimal;
       myanimal.run();	

	MonkeyObject mymonkey;
	mymonkey.run();

	printRun(&mymonkey);
	return 0;
}
