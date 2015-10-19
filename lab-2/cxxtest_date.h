#include "date.hpp"
#include "julian.hpp"
#include "kattistime.h"

using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite {
public:

	void test1 () { //Not really a test, just writing out todays date. Check manually if this is indeeed todays date.
		time_t t;
		time(&t);
		set_k_time(t);
		Julian j;
		std::cout << " Today's Julian date is: " << j << " ";
	}

	void test2 () { //Testing all implemented funtions on a date.
		time_t t = 1445243911;
		set_k_time(t);
		Julian j;
		TS_ASSERT_EQUALS(j.early_julian_day(), 2457315);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 57315);
		TS_ASSERT_EQUALS(j.week_day(), 1);
		TS_ASSERT_EQUALS(j.week_day_name(), "Monday");
	}

	void test3 () {
		time_t t = 1445243911 - 86400;
		set_k_time(t);
		Julian j;
		TS_ASSERT_EQUALS(j.early_julian_day(), 2457314);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 57314);
		TS_ASSERT_EQUALS(j.week_day(), 7);
		TS_ASSERT_EQUALS(j.week_day_name(), "Sunday");
	}

	void test4 () {
		time_t t = 0;
		set_k_time(t);
		Julian j;
		TS_ASSERT_EQUALS(j.early_julian_day(), 2440588);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 40588);
		TS_ASSERT_EQUALS(j.week_day(), 4);
		TS_ASSERT_EQUALS(j.week_day_name(), "Thursday");
	}
};