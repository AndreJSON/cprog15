#include "date.hpp"
#include "julian.hpp"
#include "kattistime.h"

using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite {
public:

	void test1 () {
		time_t tp;
		time(&tp);
		set_k_time(tp);
		Julian d;
		std::cout << d.early_julian_day() << std::endl;
	}
};