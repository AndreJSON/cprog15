#include "date.hpp"
#include "julian.hpp"
#include "kattistime.h"

using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite {
public:

	void test1 () {
		Julian d;
		std::cout << d.mod_julian_day() << std::endl;
	}
};