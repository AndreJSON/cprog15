#include <stdexcept>
#include <iostream>

template <typename T>
class UIntVector {
private:
	//void resize (size_t const&);
	size_t backSize, frontSize;
	T* array;

public:
	explicit UIntVector (size_t);
	UIntVector (std::initializer_list<unsigned int>);
	UIntVector (UIntVector const&);
	UIntVector (UIntVector&&) noexcept;
	~UIntVector ();
	UIntVector& operator= (UIntVector const&);
	UIntVector& operator= (UIntVector&&);
	unsigned int operator[] (size_t const&) const;
	unsigned int& operator[] (size_t const&);
	void reset();
	size_t size() const;
};


//Constructor taking a size parameter.
template <typename T>
UIntVector<T>::UIntVector (size_t size) {
	frontSize = size;
	backSize = size;
	array = (T*)malloc(/*sizeof(T) **/ size);
	//reset();
}

//Destructor.
template <typename T>
UIntVector<T>::~UIntVector () {
	free(array);
}

//Called internally to increase the size of the vector enough to fit the index into it.
/*void UIntVector::resize(size_t const& index) {
	if (index >= backSize) { //allocate double the space of index.
		unsigned int * tmp = (unsigned int*)malloc(sizeof(unsigned int) * (index<<1)); //Might break if you try elements to a huge index (bigger the size of size_t).
		
	} else { //index must have been smaller than backSize but greater than frontSize.
		frontSize = index;
	}
}*/