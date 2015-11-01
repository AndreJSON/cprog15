#include "date.hpp"
#include "julian.hpp"
#include "kattistime.h"

using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite {
public:

	void testInitTime () { //Initializing kattistime.
		time_t t;
		time(&t);
		set_k_time(t);
	}

	void test1 () { //Testing a bunch of years with the leap year function.
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

	void test2 () { //Testing days_in_month for Julian.
		unsigned int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		Julian j;
		for (auto i = 0; i < 12; i++)
			TS_ASSERT_EQUALS(j.days_in_month(i+1,2015), days[i]);
		for (auto i = 0; i < 12; i++)
			TS_ASSERT_EQUALS(j.days_in_month(i+1,1999), days[i]);
		for (auto i = 0; i < 12; i++)
			TS_ASSERT_EQUALS(j.days_in_month(i+1,2001), days[i]);

		TS_ASSERT_EQUALS(j.days_in_month(2,2000), 29);
		TS_ASSERT_EQUALS(j.days_in_month(2,1900), 28);
	}

	void test3 () { //Testing days_in_year for Julian.
		Julian j;
		TS_ASSERT_EQUALS(j.days_in_year(0),366);
		TS_ASSERT_EQUALS(j.days_in_year(1),365);
		TS_ASSERT_EQUALS(j.days_in_year(4),366);
		TS_ASSERT_EQUALS(j.days_in_year(100),365);
		TS_ASSERT_EQUALS(j.days_in_year(400),366);
		TS_ASSERT_EQUALS(j.days_in_year(2500),365);
	}

	void test4 () { //Testing the year class-member function in Julian.
		Julian j;
		time_t t;
		t = 1445243911;
		set_k_time(t);
		TS_ASSERT_EQUALS(j.year(), 2015);
		t = 1445243911 - 86400;
		set_k_time(t);
		TS_ASSERT_EQUALS(j.year(), 2015);
		t = 0;
		set_k_time(t);
		TS_ASSERT_EQUALS(j.year(), 1970);
		t = 1445243911 + 7000 * 86400;
		set_k_time(t);
		TS_ASSERT_EQUALS(j.year(), 2034);
	}

	void testX1 () { //Testing all implemented funtions on a date.
		time_t t = 1445243911;
		set_k_time(t);
		Julian j;
		TS_ASSERT_EQUALS(j.early_julian_day(), 2457315);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 57315);
		TS_ASSERT_EQUALS(j.week_day(), 1);
		TS_ASSERT_EQUALS(j.week_day_name(), "Monday");
		TS_ASSERT_EQUALS(j.year(), 2015);
	}

	void testX2 () { //Testing all implemented funtions on a date.
		time_t t = 1445243911 - 86400;
		set_k_time(t);
		Julian j;
		TS_ASSERT_EQUALS(j.early_julian_day(), 2457314);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 57314);
		TS_ASSERT_EQUALS(j.week_day(), 7);
		TS_ASSERT_EQUALS(j.week_day_name(), "Sunday");
		TS_ASSERT_EQUALS(j.year(), 2015);
	}

	void testX3 () { //Testing all implemented funtions on a date.
		time_t t = 0;
		set_k_time(t);
		Julian j;
		TS_ASSERT_EQUALS(j.early_julian_day(), 2440588);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 40588);
		TS_ASSERT_EQUALS(j.week_day(), 4);
		TS_ASSERT_EQUALS(j.week_day_name(), "Thursday");
		TS_ASSERT_EQUALS(j.year(), 1970);
	}

	void testX4 () { //Testing all implemented funtions on a date.
		time_t t = 1445243911 + 7000 * 86400;
		set_k_time(t);
		Julian j;
		TS_ASSERT_EQUALS(j.early_julian_day(), 2464315);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 64315);
		TS_ASSERT_EQUALS(j.week_day(), 1);
		TS_ASSERT_EQUALS(j.week_day_name(), "Monday");
		TS_ASSERT_EQUALS(j.year(), 2034);
	}

	void testTodaysDate () { //Not really a test, just writing out todays date. Check manually if this is indeeed todays date.
		time_t t;
		time(&t);
		set_k_time(t);
		Julian j;
		std::cout << " Today's Julian date is: " << j << " ";
	}
};