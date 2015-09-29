#include <stdexcept>
#include <iostream>

template <typename T>
class Vector {
private:
	void resize (size_t const&);
	size_t backSize, frontSize;
	T* array;

public:
	explicit Vector ();
	explicit Vector (size_t);
	explicit Vector (size_t, T const&);
	Vector (std::initializer_list<T>);
	Vector (Vector const&);
	Vector (Vector&&) noexcept;
	~Vector ();
	Vector& operator= (Vector const&);
	Vector& operator= (Vector&&);
	T operator[] (size_t const&) const;
	T& operator[] (size_t const&);
	void reset ();
	size_t size () const;
};

//Default constructor. Makes room for 10 elements.
template <typename T>
Vector<T>::Vector () {
	frontSize = 0;
	backSize = 10;
	array = (T*)malloc(sizeof(T) * backSize);
}

//Constructor taking a size parameter.
template <typename T>
Vector<T>::Vector (size_t size) {
	frontSize = size;
	backSize = size;
	array = (T*)malloc(sizeof(T) * backSize);
}

//Constructor taking a size parameter and a value.
template <typename T>
Vector<T>::Vector (size_t size, T const& value) {
	frontSize = size;
	backSize = size;
	array = (T*)malloc(sizeof(T) * backSize);
	for (auto i = 0; i < frontSize; i++) {
		array[i] = value;
	}
}

//Constructor taking an initializer_list.
template <typename T>
Vector<T>::Vector (std::initializer_list<T> il) {
	frontSize = il.size();
	backSize = frontSize;
	array = (T*)malloc(sizeof(T) * backSize);
	auto i = 0;
	for (auto n = il.begin(); n != il.end(); n++) {
		array[i++] = *n;
	}
}

//Destructor.
template <typename T>
Vector<T>::~Vector () {
	free(array);
}

//Operator [] overload (get value).
template <typename T>
T Vector<T>::operator[] (size_t const& index) const {
	if (index < frontSize) {
		return array[index];
	} else {
		throw std::out_of_range("index out of bounds error.");
	}
}

//Operator [] overload (set value).
template <typename T>
T& Vector<T>::operator[] (size_t const& index) {
	if (index < frontSize) {
		return array[index];
	} else {
		throw std::out_of_range("index out of bounds error.");
	} 
}

//Resets all elements in the publicly seen part of the vector to be zero initialized.
template <typename T>
void Vector<T>::reset () {
	for (auto i = 0; i < frontSize; i++) {
		array[i] = (T)0;
	}
}

//Gives the size of the publicly seen vector.
template <typename T>
size_t Vector<T>::size () const {
	return frontSize;
}


//Called internally to increase the size of the vector enough to fit the index into it.
/*template <typename T>
void Vector<T>::resize(size_t const& index) {
	if (index >= backSize) { //allocate double the space of index.
		T* tmp = (T*)malloc(sizeof(T) * (index<<1)); //Might break if you try elements to a huge index (bigger the size of size_t).
		
	} else { //index must have been smaller than backSize but greater than frontSize.
		frontSize = index;
	}
}*/