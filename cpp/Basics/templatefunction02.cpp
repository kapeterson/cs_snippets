#include <iostream>


template <typename T>
void typedfunction(T arg){
	std::cout << "Typed function called " << arg << std::endl;;
}
void myfunction(){
	
	std::cout << "Function called " << std::endl;
}
int main(){
	
	myfunction();
	typedfunction<int>(5);

	double mydouble = 1.005;
	typedfunction<double>(mydouble);
	typedfunction<std::string>("name");
	return 0;

}
