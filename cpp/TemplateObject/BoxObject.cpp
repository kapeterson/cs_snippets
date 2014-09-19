#include "BoxObject.h"

template <class T> BoxObject<T>::BoxObject(int init){
//	size = initsize;
	itemList = new T[10];
}

template <class T> BoxObject<T>::~BoxObject(){
	delete itemList;
}
