#include "u_int_vector.h"

//Regular constructor.
UIntVector::UIntVector (size_t size) {
	frontSize = size;
	backSize = size;
	array = (unsigned int*)malloc(sizeof(unsigned int) * size);
	reset();
}

//Copy constructor.
UIntVector::UIntVector (UIntVector const& v) {
	frontSize = v.frontSize;
	backSize = v.backSize;
	array = (unsigned int*)malloc(sizeof(unsigned int) * v.backSize);
	for (auto i = 0; i < v.backSize; i++) {
		array[i] = v.array[i];
	}
}

//Move constructor.
UIntVector::UIntVector (UIntVector&& v) noexcept {
	frontSize = v.frontSize;
	backSize = v.backSize;
	array = (unsigned int*)malloc(sizeof(unsigned int) * v.backSize);
	for (auto i = 0; i < v.backSize; i++) {
		array[i] = v.array[i];
	}
}

//Destructor.
UIntVector::~UIntVector () {
	free(array);
}

//Copy-assignment operator.
UIntVector& UIntVector::operator= (UIntVector const& v) {
	if (&v == this) //If the user has tried to assign the UIntVector to itself.
		return *this;
	frontSize = v.frontSize;
	backSize = v.backSize;
	free(array); //Free the old space before we create any new.
	array = (unsigned int*)malloc(sizeof(unsigned int) * v.backSize);
	for (auto i = 0; i < v.backSize; i++) {
		array[i] = v.array[i];
	}
	return *this;
}

//Move-assignment operator.
UIntVector& UIntVector::operator= (UIntVector&& v) {
	if (&v == this) //If the user has tried to move the UIntVector to itself.
		return *this;
	frontSize = v.frontSize;
	backSize = v.backSize;
	free(array); //Free the old space before we create any new.
	array = (unsigned int*)malloc(sizeof(unsigned int) * v.backSize);
	for (auto i = 0; i < v.backSize; i++) {
		array[i] = v.array[i];
	}
	return *this;
}

//Operator [] overload (get value).
unsigned int UIntVector::operator[] (size_t const& index) const {
	if (index < frontSize) {
		return array[index];
	} else {
		throw std::out_of_range("index out of bounds error.");
	}
}

//Operator [] overload (set value).
unsigned int& UIntVector::operator[] (size_t const& index) { //May be wrong. I just guessed my way to this.
	if (index < frontSize) {
		return array[index];
	} else {
		throw std::out_of_range("index out of bounds error.");
	} 
}

//Resets all elements in the publicly seen part of the vector to 0.
void UIntVector::reset () {
	for (auto i = 0; i < frontSize; i++) {
		array[i] = (unsigned int)0;
	}
}

//Gives the size of the publicly seen vector.
size_t UIntVector::size () const {
	return frontSize;
}