#include <stdexcept>
#include <iostream>
#include <vector>

template <class T>
class Vector {
private:
	void resize ();
	size_t backSize, frontSize;
	T* array;

public:
	static_assert(std::is_move_constructible<T>::value, "type was not move constructible.");
	static_assert(std::is_move_assignable<T>::value, "type was not move assignable.");
	explicit Vector ();
	explicit Vector (size_t);
	explicit Vector (size_t, T const);
	Vector (std::initializer_list<T>);
	Vector (Vector const&);
	Vector (Vector&&) noexcept;
	~Vector ();
	Vector& operator= (Vector const&);
	Vector& operator= (Vector&&);
	T* begin ();
	T const* begin () const;
	T* end ();
	T const* end () const;
	T* find (T const&);
	T const* find(T const&) const;
	T const& operator[] (size_t) const;
	T& operator[] (size_t);
	void push_back(T);
	void insert (size_t, T);
	void erase (size_t);
	void clear ();
	void reset ();
	size_t size () const;
	size_t capacity () const;
};

//Default constructor. Makes room for 10 elements.
template <class T>
Vector<T>::Vector () {
	frontSize = 0;
	backSize = 10;
	array = new T[backSize];
}

//Constructor taking a size parameter.
template <class T>
Vector<T>::Vector (size_t size) {
	frontSize = size;
	backSize = size;
	array = new T[backSize];
	reset();
}

//Constructor taking a size parameter and a value.
template <class T>
Vector<T>::Vector (size_t size, T const value) {
	frontSize = size;
	backSize = size;
	array = new T[backSize];
	for (auto i = 0; i < frontSize; i++) {
		array[i] = value;
	}
}

//Constructor taking an initializer_list.
template <class T>
Vector<T>::Vector (std::initializer_list<T> il) {
	frontSize = il.size();
	backSize = frontSize;
	array = new T[backSize];
	auto i = 0;
	for (auto n = il.begin(); n != il.end(); n++) {
		array[i++] = *n;
	}
}

//Copy constructor.
template <class T>
Vector<T>::Vector (Vector const& v) {
	frontSize = v.frontSize;
	backSize = v.backSize;
	array = new T[v.backSize];
	for (auto i = 0; i < v.backSize; i++) {
		array[i] = v.array[i];
	}
}

//Move constructor.
template <class T>
Vector<T>::Vector (Vector&& v) noexcept {
	frontSize = v.frontSize;
	backSize = v.backSize;
	array = new T[v.backSize];
	std::swap(array, v.array);
	//reset the moved-from container.
	v.frontSize = 0;
	v.backSize = 0;
	delete[] v.array;
	v.array = nullptr;
}

//Destructor.
template <class T>
Vector<T>::~Vector () {
	delete[] array;
}

//Copy-assignment operator.
template <class T>
Vector<T>& Vector<T>::operator= (Vector<T> const& v) {
	if (&v == this) //If the user has tried to assign the Vector to itself.
		return *this;
	frontSize = v.frontSize;
	backSize = v.backSize;
	delete[] array; //Free the old space before we create any new.
	array = new T[v.backSize];
	for (auto i = 0; i < v.backSize; i++) {
		array[i] = v.array[i];
	}
	return *this;
}

//Move-assignment operator.
template <class T>
Vector<T>& Vector<T>::operator= (Vector<T>&& v) {
	if (&v == this) //If the user has tried to move the Vector to itself.
		return *this;
	frontSize = v.frontSize;
	backSize = v.backSize;
	std::swap(array, v.array);
	//reset the moved-from container.
	v.frontSize = 0;
	v.backSize = 0;
	delete[] v.array;
	v.array = nullptr;
	return *this;
}

//Pointer to the first element.
template <class T>
T* Vector<T>::begin () {
	return &array[0];
}

//Const pointer to the first element.
template <class T>
T const* Vector<T>::begin () const{
	return &array[0];
}

//Pointer to position right after the last element.
template <class T>
T* Vector<T>::end () {
	return &array[frontSize];
}

//Const pointer to position right after the last element.
template <class T>
T const* Vector<T>::end () const{
	return &array[frontSize];
}

//Returns a pointer to the first occurence of the specified value.
template <class T>
T* Vector<T>::find (T const& value) {
	for (auto i = begin(); i != end(); i++) {
		if (*i == value)
			return i;
	}
	return end();
}

//Returns a const pointer to the first occurence of the specified value.
template <class T>
T const* Vector<T>::find(T const& value) const {
	for (auto i = begin(); i != end(); i++) {
		if (*i == value)
			return i;
	}
	return end();
}

//Operator [] overload (get value).
template <class T>
T const& Vector<T>::operator[] (size_t index) const {
	if (index < frontSize) {
		return array[index];
	} else {
		throw std::out_of_range("index out of bounds error.");
	}
}

//Operator [] overload (set value).
template <class T>
T& Vector<T>::operator[] (size_t index) {
	if (index < frontSize) {
		return array[index];
	} else {
		throw std::out_of_range("index out of bounds error.");
	} 
}

//Appends to specified element at the end of the vector.
template <class T>
void Vector<T>::push_back (T value) {
	if (frontSize == backSize)
		resize();
	array[frontSize++] = value;
}

//Inserts element T and the specified index. Throws std::out_of_range if trting to place element outside of vector.
template <class T>
void Vector<T>::insert (size_t index, T value) {
	if (index > frontSize)
		throw std::out_of_range("index out of bounds error.");
	if (frontSize == backSize)
		resize();
	for (auto i = frontSize; i > index; i--) {
		array[i] = array[i-1];
	}
	frontSize++;
	array[index] = value;
}

//Erases elements at specified index.
template <class T>
void Vector<T>::erase (size_t index) {
	if (index >= frontSize)
		throw std::out_of_range("index out of bounds error.");
	for (auto i = index; i < frontSize-1; i++) {
		array[i]  = array[i+1];
	}
	frontSize--;
} 

//Clears the vector of all elements leaving it at a size of 0.
template <class T>
void Vector<T>::clear () {
	frontSize = 0;
	//backSize = 10;
	delete[] array;
	array = new T[backSize];
}

//Resets all elements in the publicly seen part of the vector to be zero initialized.
template <class T>
void Vector<T>::reset () {
	for (auto i = 0; i < frontSize; i++) {
		array[i] = T();
	}
}

//Gives the size of the publicly seen vector.
template <class T>
size_t Vector<T>::size () const {
	return frontSize;
}

//Gives the number of elements storeable in the Vector before it needs to reallocate a larger memory chunk.
template <class T>
size_t Vector<T>::capacity () const {
	return backSize;
}

//Called internally to increase the size of the vector.
template <class T>
void Vector<T>::resize() {
	backSize = backSize<<1; //Double the size.
	T* tmp = new T[backSize];
	for (auto i = 0; i < frontSize; i++) {
		tmp[i] = array[i];
	}
	std::swap(array,tmp);
	delete[] tmp;
}