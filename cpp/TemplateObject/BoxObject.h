

template < class T > 
class BoxObject {
	private:
		T itemList[];
		int size;
	public:
		BoxObject(int =5);

		~BoxObject();
};

