#include <stdexcept>
#include <iostream>

template <typename T>
class Vector {
private:
	void resize ();
	size_t backSize, frontSize;
	T* array;

public:
	explicit Vector ();
	explicit Vector (size_t);
	explicit Vector (size_t, T const);
	Vector (std::initializer_list<T>);
	Vector (Vector const&);
	Vector (Vector&&) noexcept;
	~Vector ();
	Vector& operator= (Vector const&);
	Vector& operator= (Vector&&);
	T operator[] (size_t const&) const;
	T& operator[] (size_t const&);
	void push_back(T);
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
	reset();
}

//Constructor taking a size parameter and a value.
template <typename T>
Vector<T>::Vector (size_t size, T const value) {
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

//Copy constructor.
template <typename T>
Vector<T>::Vector (Vector const& v) {
	frontSize = v.frontSize;
	backSize = v.backSize;
	array = (T*)malloc(sizeof(T) * v.backSize);
	for (auto i = 0; i < v.backSize; i++) {
		array[i] = v.array[i];
	}
}

//Move constructor.
template <typename T>
Vector<T>::Vector (Vector&& v) noexcept {
	frontSize = v.frontSize;
	backSize = v.backSize;
	array = (T*)malloc(sizeof(T) * v.backSize);
	std::swap(array,v.array);
	//reset the moved-from container.
	v.frontSize = 0;
	v.backSize = 0;
	free(v.array);
	v.array = nullptr;
}

//Destructor.
template <typename T>
Vector<T>::~Vector () {
	free(array);
}

//Copy-assignment operator.
template <typename T>
Vector<T>& Vector<T>::operator= (Vector<T> const& v) {
	if (&v == this) //If the user has tried to assign the Vector to itself.
		return *this;
	frontSize = v.frontSize;
	backSize = v.backSize;
	free(array); //Free the old space before we create any new.
	array = (T*)malloc(sizeof(T) * v.backSize);
	for (auto i = 0; i < v.backSize; i++) {
		array[i] = v.array[i];
	}
	return *this;
}

//Move-assignment operator.
template <typename T>
Vector<T>& Vector<T>::operator= (Vector<T>&& v) {
	if (&v == this) //If the user has tried to move the Vector to itself.
		return *this;
	frontSize = v.frontSize;
	backSize = v.backSize;
	std::swap(array, v.array);
	//reset the moved-from container.
	v.frontSize = 0;
	v.backSize = 0;
	free(v.array);
	v.array = nullptr;
	return *this;
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

//Appends to specified element at the end of the vector.
template <typename T>
void Vector<T>::push_back (T value) {
	if (frontSize == backSize)
		resize();
	array[frontSize++] = value;
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

//Called internally to increase the size of the vector.
template <typename T>
void Vector<T>::resize() {
	backSize = backSize<<1; //Double the size.
	T* tmp = (T*)malloc(sizeof(T) * (backSize));
	for (auto i = 0; i < frontSize; i++) {
		tmp[i] = array[i];
	}
	std::swap(array,tmp);
	free(tmp);
}