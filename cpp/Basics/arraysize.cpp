#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int vals[] = { 1, 2, 3, 4, 5};
	const char mystring[] = "mystringhere";

	cout << "Size of int is " << sizeof(vals) << "\n";



	int cur = 0;	
	char tchar = mystring[cur];
	while ( tchar != '\0' ){
		cout << tchar << "\n";
		cur++;
		tchar =  mystring[cur];
	}
	return 0;
}
