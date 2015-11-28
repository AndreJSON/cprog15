#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include "kattistime.h"
#include "calendar.hpp"

using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite {
public:

	void testInitTime () { //Initializing kattistime.
		time_t t;
		time(&t);
		set_k_time(t);
	}

	void test1 () {
		Calendar<Gregorian> cg1;
		Calendar<Julian> cj1;

		//Calendar<Gregorian> cg2(cg1);
		Calendar<Gregorian> cg3(cj1);
	}

	void test2 () {
		Calendar<Gregorian> c;
		c.add_event("Event 1");
		c.add_event("Event 2");
	}

	void testPrint () {
		Calendar<Gregorian> gc;
		std::cout << std::endl << gc;
	}
};