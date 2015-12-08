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

	void test1 () { //Construct calendar from other calendar.
		Calendar<Gregorian> cg1;
		Calendar<Julian> cj1;

		Calendar<Gregorian> cg2(cg1);
		Calendar<Gregorian> cg3(cj1);
	}

	void test2 () { //Simple add and remove event test.
		Calendar<Gregorian> c;
		TS_ASSERT_EQUALS(c.add_event("Event 1"), true);
		TS_ASSERT_EQUALS(c.add_event("Event 1"), false);
		TS_ASSERT_EQUALS(c.add_event("Event 2"), true);
		TS_ASSERT_EQUALS(c.remove_event("Event 1"), true);
		TS_ASSERT_EQUALS(c.remove_event("Event 1"), false);

		Calendar<Gregorian> c2(c);
		TS_ASSERT_EQUALS(c2.add_event("Event 2"), false);

		Calendar<Julian> j(c);
		TS_ASSERT_EQUALS(j.add_event("Event 2"), false);
	}

	void test3 () { // Simple set date testing.
		Calendar<Julian> j;
		TS_ASSERT_EQUALS(j.set_date(2000,1,1), true);
		TS_ASSERT_EQUALS(j.add_event("hello"), true);
		TS_ASSERT_EQUALS(j.add_event("hello", 1, 1, 2000), false);
		TS_ASSERT_EQUALS(j.remove_event("hello", 1, 1, 2000), true);

		TS_ASSERT_EQUALS(j.set_date(2001,1,1), true);
		TS_ASSERT_EQUALS(j.add_event("hello"), true);
		TS_ASSERT_EQUALS(j.add_event("hello"), false);
		TS_ASSERT_EQUALS(j.set_date(2002,1,1), true);
		TS_ASSERT_EQUALS(j.remove_event("hello"), false);
		TS_ASSERT_EQUALS(j.remove_event("hello"), false);
		TS_ASSERT_EQUALS(j.set_date(2001,1,1), true);
		TS_ASSERT_EQUALS(j.remove_event("hello"), true);

		//std::cout << std::endl << "Should be an empty calendar:" << std::endl << j << std::endl << std::endl;
	}

	void testSpecific1 () { //Test reproducing a specific problem.
		Calendar<Julian> j;
		TS_ASSERT_EQUALS(j.add_event("fizbar", 12, 8, 2015), true);
		TS_ASSERT_EQUALS(j.set_date(1900,1,1), true);
		TS_ASSERT_EQUALS(j.add_event("birbaz", 12, 10), true);
		TS_ASSERT_EQUALS(j.add_event("foobar", 12), true);
		TS_ASSERT_EQUALS(j.add_event("fizbar", -1, -1, -1), false);
		TS_ASSERT_EQUALS(j.add_event("fizbar", 0, 0, 0), false);
		TS_ASSERT_EQUALS(j.remove_event("foobar", 12, 8, 2015), false);

		Calendar<Gregorian> g(j);
		//std::cout << std::endl << j << std::endl;
	}

	void testSpecific2 () {
		Calendar<Gregorian> g;
		//std::cout << std::endl << g << std::endl;
		TS_ASSERT_EQUALS(g.set_date(2012,2,29), true);
		TS_ASSERT_EQUALS(g.add_event("pNGVXBK", 7, 2), true);
		TS_ASSERT_EQUALS(g.add_event("heru", 7, 3), true);
		TS_ASSERT_EQUALS(g.remove_event("pNGVXBK", 11, -9), false);
		TS_ASSERT_EQUALS(g.set_date(1990,2,29), false);
		//std::cout << g << std::endl;
	}

	void testSpecific3 () {
		Calendar<Gregorian> g;
		TS_ASSERT_EQUALS(g.set_date(2004, 2, 29), true);
		TS_ASSERT_EQUALS(g.add_event("asd", 29), true);
		TS_ASSERT_EQUALS(g.remove_event("asd", 1), false);
		TS_ASSERT_EQUALS(g.set_date(2003, 2, 29), false);
		std::cout << g << std::endl;
	}

	void testPrint () {
		Calendar<Gregorian> gc;
		gc.add_event("Event 1");
		gc.add_event("Event 1");
		gc.add_event("Event 2");
		//std::cout << std::endl << gc << std::endl;
	}
};