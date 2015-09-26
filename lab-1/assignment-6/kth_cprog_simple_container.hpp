#include <stdexcept>
#include <iostream>


class UIntVector {
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

private:
	//void resize (size_t const&);
	size_t backSize, frontSize;
	unsigned int* array;
};