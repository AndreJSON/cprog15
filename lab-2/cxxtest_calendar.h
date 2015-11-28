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
		TS_ASSERT_EQUALS(c.add_event("Event 1"), true);
		TS_ASSERT_EQUALS(c.add_event("Event 1"), false);
		TS_ASSERT_EQUALS(c.add_event("Event 2"), true);
	}

	void testPrint () {
		Calendar<Gregorian> gc;
		gc.add_event("Event 1");
		gc.add_event("Event 1");
		gc.add_event("Event 2");
		std::cout << std::endl << gc << std::endl;
	}
};