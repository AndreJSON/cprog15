#include "kth_cprog_simple_container.hpp"

//Regular constructor.
UIntVector::UIntVector (size_t size) {
	frontSize = size;
	backSize = size;
	array = (unsigned int*)malloc(sizeof(unsigned int) * size);
	reset();
}

//Constructor taking std::initializer_list<unsigned int>.
UIntVector::UIntVector (std::initializer_list<unsigned int> il) {
	frontSize = il.size();
	backSize = frontSize;
	array = (unsigned int*)malloc(sizeof(unsigned int) * frontSize);
	auto i = 0;
	for (auto n = il.begin(); n != il.end(); n++) {
		array[i] = *n;
		i++;
	}
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
	std::swap(array,v.array);
	//reset the moved-from container.
	v.frontSize = 0;
	v.backSize = 0;
	free(v.array);
	v.array = nullptr;
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
	std::swap(array, v.array);
	//reset the moved-from container.
	v.frontSize = 0;
	v.backSize = 0;
	free(v.array);
	v.array = nullptr;
	
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

//Called internally to increase the size of the vector enough to fit the index into it.
/*void UIntVector::resize(size_t const& index) {
	if (index >= backSize) { //allocate double the space of index.
		unsigned int * tmp = (unsigned int*)malloc(sizeof(unsigned int) * (index<<1)); //Might break if you try elements to a huge index (bigger the size of size_t).
		
	} else { //index must have been smaller than backSize but greater than frontSize.
		frontSize = index;
	}
}*/