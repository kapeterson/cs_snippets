
all: vector simplevector tuplevector

simplevector:
	g++ -o simplevector simplevector.cpp -std=c++11
vector:
	g++ -o vector vector.cpp

tuplevector:
	g++ -o tuplevector tuplevector.cpp -std=c++11

object:
	g++ objectvector.cpp ../GenericObjects/AnimalObject.cpp 

clean:
	rm -f *.o
	rm -f vector simplevector tuplevector
