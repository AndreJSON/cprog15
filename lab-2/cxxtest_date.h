#include "date.cpp"
#include "julian.cpp"
#include "kattistime.cpp"

using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite {
public:

	void test1 () {
		Julian d;
		std::cout << d.mod_julian_day() << std::endl;
	}
};