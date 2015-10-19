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
		TS_ASSERT_EQUALS(j.year(), 2015);
	}

	void test3 () {
		time_t t = 1445243911 - 86400;
		set_k_time(t);
		Julian j;
		TS_ASSERT_EQUALS(j.early_julian_day(), 2457314);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 57314);
		TS_ASSERT_EQUALS(j.week_day(), 7);
		TS_ASSERT_EQUALS(j.week_day_name(), "Sunday");
		TS_ASSERT_EQUALS(j.year(), 2015);
	}

	void test4 () {
		time_t t = 0;
		set_k_time(t);
		Julian j;
		TS_ASSERT_EQUALS(j.early_julian_day(), 2440588);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 40588);
		TS_ASSERT_EQUALS(j.week_day(), 4);
		TS_ASSERT_EQUALS(j.week_day_name(), "Thursday");
		TS_ASSERT_EQUALS(j.year(), 1970);
	}

	void test5 () {
		time_t t = 1445243911 + 7000 * 86400;
		set_k_time(t);
		Julian j;
		TS_ASSERT_EQUALS(j.early_julian_day(), 2464315);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 64315);
		TS_ASSERT_EQUALS(j.week_day(), 1);
		TS_ASSERT_EQUALS(j.week_day_name(), "Monday");
		TS_ASSERT_EQUALS(j.year(), 2034);
	}

	void testX () {
		Julian j;
		TS_ASSERT_EQUALS(j.is_leap_year(0), true);
		TS_ASSERT_EQUALS(j.is_leap_year(1), false);
		TS_ASSERT_EQUALS(j.is_leap_year(4), true);
		TS_ASSERT_EQUALS(j.is_leap_year(100), false);
		TS_ASSERT_EQUALS(j.is_leap_year(104), true);
		TS_ASSERT_EQUALS(j.is_leap_year(105), false);
		TS_ASSERT_EQUALS(j.is_leap_year(400), true);
		TS_ASSERT_EQUALS(j.is_leap_year(500), false);
		TS_ASSERT_EQUALS(j.is_leap_year(501), false);
		TS_ASSERT_EQUALS(j.is_leap_year(2000), true);
		TS_ASSERT_EQUALS(j.is_leap_year(2016), true);
		TS_ASSERT_EQUALS(j.is_leap_year(2400), true);
		TS_ASSERT_EQUALS(j.is_leap_year(2600), false);
	}
};