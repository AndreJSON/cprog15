#include "date.hpp"
#include "gregorian.hpp"
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

	void test1G () { //Testing a bunch of years with the leap year function.
		Gregorian g;
		TS_ASSERT_EQUALS(g.is_leap_year(0), true);
		TS_ASSERT_EQUALS(g.is_leap_year(1), false);
		TS_ASSERT_EQUALS(g.is_leap_year(4), true);
		TS_ASSERT_EQUALS(g.is_leap_year(100), false);
		TS_ASSERT_EQUALS(g.is_leap_year(104), true);
		TS_ASSERT_EQUALS(g.is_leap_year(105), false);
		TS_ASSERT_EQUALS(g.is_leap_year(400), true);
		TS_ASSERT_EQUALS(g.is_leap_year(500), false);
		TS_ASSERT_EQUALS(g.is_leap_year(501), false);
		TS_ASSERT_EQUALS(g.is_leap_year(2000), true);
		TS_ASSERT_EQUALS(g.is_leap_year(2016), true);
		TS_ASSERT_EQUALS(g.is_leap_year(2400), true);
		TS_ASSERT_EQUALS(g.is_leap_year(2600), false);
	}

	void test1J () { //Testing a bunch of years with the leap year function.
		Julian j;
		TS_ASSERT_EQUALS(j.is_leap_year(1), false);
		TS_ASSERT_EQUALS(j.is_leap_year(4), true);
		TS_ASSERT_EQUALS(j.is_leap_year(100), true);
		TS_ASSERT_EQUALS(j.is_leap_year(104), true);
		TS_ASSERT_EQUALS(j.is_leap_year(105), false);
		TS_ASSERT_EQUALS(j.is_leap_year(400), true);
		TS_ASSERT_EQUALS(j.is_leap_year(500), true);
		TS_ASSERT_EQUALS(j.is_leap_year(501), false);
		TS_ASSERT_EQUALS(j.is_leap_year(2000), true);
		TS_ASSERT_EQUALS(j.is_leap_year(2016), true);
		TS_ASSERT_EQUALS(j.is_leap_year(2400), true);
		TS_ASSERT_EQUALS(j.is_leap_year(2600), true);
	}

	void test2G () { //Testing days_in_month for Gregorian.
		unsigned int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		Gregorian g;
		for (auto i = 0; i < 12; i++)
			TS_ASSERT_EQUALS(g.days_in_month(i+1,2015), days[i]);
		for (auto i = 0; i < 12; i++)
			TS_ASSERT_EQUALS(g.days_in_month(i+1,1999), days[i]);
		for (auto i = 0; i < 12; i++)
			TS_ASSERT_EQUALS(g.days_in_month(i+1,2001), days[i]);

		TS_ASSERT_EQUALS(g.days_in_month(2,2000), 29);
		TS_ASSERT_EQUALS(g.days_in_month(2,1900), 28);
	}

	void test2J () { //Testing days_in_month for Gregorian.
		unsigned int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		Julian j;
		for (auto i = 0; i < 12; i++)
			TS_ASSERT_EQUALS(j.days_in_month(i+1,2015), days[i]);
		for (auto i = 0; i < 12; i++)
			TS_ASSERT_EQUALS(j.days_in_month(i+1,1999), days[i]);
		for (auto i = 0; i < 12; i++)
			TS_ASSERT_EQUALS(j.days_in_month(i+1,2001), days[i]);

		TS_ASSERT_EQUALS(j.days_in_month(2,2000), 29);
		TS_ASSERT_EQUALS(j.days_in_month(2,1900), 29);
	}

	void test3G () { //Testing days_in_year for Gregorian.
		Gregorian g;
		TS_ASSERT_EQUALS(g.days_in_year(0),366);
		TS_ASSERT_EQUALS(g.days_in_year(1),365);
		TS_ASSERT_EQUALS(g.days_in_year(4),366);
		TS_ASSERT_EQUALS(g.days_in_year(100),365);
		TS_ASSERT_EQUALS(g.days_in_year(400),366);
		TS_ASSERT_EQUALS(g.days_in_year(2500),365);
	}

	void test3J () { //Testing days_in_year for Gregorian.
		Julian j;
		TS_ASSERT_EQUALS(j.days_in_year(1),365);
		TS_ASSERT_EQUALS(j.days_in_year(4),366);
		TS_ASSERT_EQUALS(j.days_in_year(100),366);
		TS_ASSERT_EQUALS(j.days_in_year(400),366);
		TS_ASSERT_EQUALS(j.days_in_year(2500),366);
	}

	void test4 () { //Testing the increment and decrement operators.
		time_t t = 0;
		set_k_time(t);
		Gregorian g;
		Date* d = (Date*)&g;
		unsigned int m = g.mod_julian_day();

		//g++
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		g++;
		m++;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		TS_ASSERT_EQUALS((g++).mod_julian_day(), m);
		m++;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);

		//++g
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		++g;
		++m;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		++m;
		TS_ASSERT_EQUALS((++g).mod_julian_day(), m);
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		m++;
		TS_ASSERT_EQUALS((++(*d)).mod_julian_day(), m);
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);

		//g--
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		g--;
		m--;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		TS_ASSERT_EQUALS((g--).mod_julian_day(), m);
		m--;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);

		//--g
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		--g;
		--m;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		--m;
		TS_ASSERT_EQUALS((--g).mod_julian_day(), m);
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		m--;
		TS_ASSERT_EQUALS((--(*d)).mod_julian_day(), m);
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
	}

	void test5 () { //Testing the -= and += operators.
		time_t t = 0;
		set_k_time(t);
		Gregorian g;
		Date& d = g;
		unsigned int m = g.mod_julian_day();

		//+=
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		m+=1;
		g+=1;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		m+=999;
		g+=999;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		d+=33;
		m+=33;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);

		//-=
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		m-=1;
		g-=1;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		m-=999;
		g-=999;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
		d-=33;
		m-=33;
		TS_ASSERT_EQUALS(g.mod_julian_day(), m);
	}

	void test6G () { //Testing the year, month & day class-member functions in Gregorian.
		Gregorian* g;
		time_t t;

		t = 1445243911;
		set_k_time(t);
		g = new Gregorian();
		TS_ASSERT_EQUALS((*g).year(), 2015);
		delete g;

		t = 1445243911 - 86400;
		set_k_time(t);
		g = new Gregorian();
		TS_ASSERT_EQUALS((*g).year(), 2015);
		delete g;

		t = 0;
		set_k_time(t);
		g = new Gregorian();
		TS_ASSERT_EQUALS((*g).year(), 1970);
		TS_ASSERT_EQUALS((*g).month(), 1);
		TS_ASSERT_EQUALS((*g).day(), 1);
		TS_ASSERT_EQUALS((*g).mod_julian_day(), 40587);
		delete g;

		t = 1445243911 + 7000 * 86400;
		set_k_time(t);
		g = new Gregorian();
		TS_ASSERT_EQUALS((*g).year(), 2034);
		delete g;
	}

	void test6J () { //Testing the year, month & day class-member functions in Julian.
		Julian* j;
		time_t t;

		t = 1445243911;
		set_k_time(t);
		j = new Julian();
		TS_ASSERT_EQUALS((*j).year(), 2015);
		delete j;

		t = 1445243911 - 86400;
		set_k_time(t);
		j = new Julian();
		TS_ASSERT_EQUALS((*j).year(), 2015);
		delete j;

		t = 0;
		set_k_time(t);
		j = new Julian();
		TS_ASSERT_EQUALS((*j).year(), 1969);
		TS_ASSERT_EQUALS((*j).month(), 12);
		TS_ASSERT_EQUALS((*j).day(), 19);
		delete j;

		t = 1445243911 + 7000 * 86400;
		set_k_time(t);
		j = new Julian();
		TS_ASSERT_EQUALS((*j).year(), 2034);
		delete j;
	}

	//Needs further testing when more operators are implemented.
	void test7 () { //Testing add_year in Gregorian.
		time_t t = 0;
		set_k_time(t);
		Gregorian g;
		int y = 1970;
		unsigned int m = 1;
		unsigned int d = 1;

		g.add_year(0);
		TS_ASSERT_EQUALS(g.year(), y);
		TS_ASSERT_EQUALS(g.month(), m);
		TS_ASSERT_EQUALS(g.day(), d);

		g.add_year(1);
		y++;
		TS_ASSERT_EQUALS(g.year(), y);
		TS_ASSERT_EQUALS(g.month(), m);
		TS_ASSERT_EQUALS(g.day(), d);

		g.add_year(100);
		y+=100;
		TS_ASSERT_EQUALS(g.year(), y);
		TS_ASSERT_EQUALS(g.month(), m);
		TS_ASSERT_EQUALS(g.day(), d);
	}

	//Needs further testing when more operators are implemented.
	void test8 () { //Testing add_month in Gregorian.
		time_t t = 0;
		set_k_time(t);
		Gregorian g;
		int y = 1970;
		unsigned int m = 1;
		unsigned int d = 1;

		g.add_month(0);
		TS_ASSERT_EQUALS(g.year(), y);
		TS_ASSERT_EQUALS(g.month(), m);
		TS_ASSERT_EQUALS(g.day(), d);

		g.add_month(1);
		m++;
		TS_ASSERT_EQUALS(g.year(), y);
		TS_ASSERT_EQUALS(g.month(), m);
		TS_ASSERT_EQUALS(g.day(), d);

		g.add_month(13);
		y++;
		m++;
		TS_ASSERT_EQUALS(g.year(), y);
		TS_ASSERT_EQUALS(g.month(), m);
		TS_ASSERT_EQUALS(g.day(), d);

		g.add_month(121);
		y+=10;
		m++;
		TS_ASSERT_EQUALS(g.year(), y);
		TS_ASSERT_EQUALS(g.month(), m);
		TS_ASSERT_EQUALS(g.day(), d);
	}

	void test9 () { //Testing operator-(Gregorian)
		time_t t = 0;
		set_k_time(t);
		Gregorian j1, j2;

		TS_ASSERT_EQUALS(j1-j2, 0);
		j1++;
		TS_ASSERT_EQUALS(j1-j2, 1);
		j1-=2;
		TS_ASSERT_EQUALS(j1-j2, -1);
		j1+=501;
		TS_ASSERT_EQUALS(j1-j2, 500);
	}

	void test10 () { //Testing relational operators.
		time_t t = 0;
		set_k_time(t);
		Gregorian j1, j2;

		//==
		TS_ASSERT_EQUALS(j1==j2, true); //start with both of them equal to make things easier.
		j1++;
		TS_ASSERT_EQUALS(j1==j2, false);
		j2++;
		TS_ASSERT_EQUALS(j1==j2, true);

		//!=
		TS_ASSERT_EQUALS(j1==j2, true); //start with both of them equal to make things easier.
		TS_ASSERT_EQUALS(j1!=j2, false);
		j1++;
		TS_ASSERT_EQUALS(j1!=j2, true);
		j2++;
		TS_ASSERT_EQUALS(j1!=j2, false);

		//<
		TS_ASSERT_EQUALS(j1==j2, true); //start with both of them equal to make things easier.
		TS_ASSERT_EQUALS(j1<j2, false);
		j1--;
		TS_ASSERT_EQUALS(j1<j2, true);
		j2--;
		TS_ASSERT_EQUALS(j1<j2, false);

		//<=
		TS_ASSERT_EQUALS(j1==j2, true); //start with both of them equal to make things easier.
		TS_ASSERT_EQUALS(j1<=j2, true);
		j1--;
		TS_ASSERT_EQUALS(j1<=j2, true);
		j1+=2;
		TS_ASSERT_EQUALS(j1<=j2, false);
		j1--;

		//>
		TS_ASSERT_EQUALS(j1==j2, true); //start with both of them equal to make things easier.
		TS_ASSERT_EQUALS(j1>j2, false);
		j1++;
		TS_ASSERT_EQUALS(j1>j2, true);
		j1--;
		TS_ASSERT_EQUALS(j1>j2, false);

		//>=
		TS_ASSERT_EQUALS(j1==j2, true); //start with both of them equal to make things easier.
		TS_ASSERT_EQUALS(j1>=j2, true);
		j1--;
		TS_ASSERT_EQUALS(j1>=j2, false);
		j1+=2;
		TS_ASSERT_EQUALS(j1>=j2, true);
		j1--;
	}

	void test11 () { //Testing operator=
		time_t t = 0;
		set_k_time(t);
		Gregorian j1, j2, j3;

		TS_ASSERT_EQUALS(j1==j2, true);
		j1++;
		TS_ASSERT_EQUALS(j1==j2, false);
		j1=j3;
		TS_ASSERT_EQUALS(j1==j2, true);
		j2++;
		TS_ASSERT_EQUALS(j1==j3, true);
	}

	void testX1 () { //Testing all implemented funtions on a date.
		time_t t = 1445243911;
		set_k_time(t);
		Gregorian g;
		TS_ASSERT_EQUALS(g.early_julian_day(), 2457315);
		TS_ASSERT_EQUALS(g.mod_julian_day(), 57314);
		TS_ASSERT_EQUALS(g.week_day(), 1);
		TS_ASSERT_EQUALS(g.week_day_name(), "Monday");
		TS_ASSERT_EQUALS(g.year(), 2015);
		TS_ASSERT_EQUALS(g.month(), 10);
		TS_ASSERT_EQUALS(g.day(), 19);
	}

	void testX2 () { //Testing all implemented funtions on a date.
		time_t t = 1445243911 - 86400;
		set_k_time(t);
		Gregorian g;
		TS_ASSERT_EQUALS(g.early_julian_day(), 2457314);
		TS_ASSERT_EQUALS(g.mod_julian_day(), 57313);
		TS_ASSERT_EQUALS(g.week_day(), 7);
		TS_ASSERT_EQUALS(g.week_day_name(), "Sunday");
		TS_ASSERT_EQUALS(g.year(), 2015);
	}

	void testX3 () { //Testing all implemented funtions on a date.
		time_t t = 0;
		set_k_time(t);
		Gregorian g;
		TS_ASSERT_EQUALS(g.early_julian_day(), 2440588);
		TS_ASSERT_EQUALS(g.mod_julian_day(), 40587);
		TS_ASSERT_EQUALS(g.week_day(), 4);
		TS_ASSERT_EQUALS(g.week_day_name(), "Thursday");
		TS_ASSERT_EQUALS(g.year(), 1970);
	}

	void testX4 () { //Testing all implemented funtions on a date.
		time_t t = 1445243911 + 7000 * 86400;
		set_k_time(t);
		Gregorian g;
		TS_ASSERT_EQUALS(g.early_julian_day(), 2464315);
		TS_ASSERT_EQUALS(g.mod_julian_day(), 64314);
		TS_ASSERT_EQUALS(g.week_day(), 1);
		TS_ASSERT_EQUALS(g.week_day_name(), "Monday");
		TS_ASSERT_EQUALS(g.year(), 2034);
	}

	void testX5 () {
		time_t t = 1446724701;
		set_k_time(t);
		Gregorian g;
		//TS_ASSERT_EQUALS(g.early_julian_day(), 2457315);
		TS_ASSERT_EQUALS(g.mod_julian_day(), 57331);
		TS_ASSERT_EQUALS(g.week_day(), 4);
		TS_ASSERT_EQUALS(g.week_day_name(), "Thursday");
		TS_ASSERT_EQUALS(g.year(), 2015);
		TS_ASSERT_EQUALS(g.month(), 11);
		TS_ASSERT_EQUALS(g.day(), 5);
	}

	void testX6 () { //Testing some way back dates.
		time_t t = 1446724701;
		set_k_time(t);
		Gregorian g;
		Julian j;
		
		g.ejd -= 57331;
		j.ejd -= 57331;
		TS_ASSERT_EQUALS(g.mod_julian_day(), 0);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 0);
		TS_ASSERT_EQUALS(g.year(), 1858);
		TS_ASSERT_EQUALS(j.year(), 1858);
		TS_ASSERT_EQUALS(g.month(), 11);
		TS_ASSERT_EQUALS(j.month(), 11);
		TS_ASSERT_EQUALS(g.day(), 17);
		TS_ASSERT_EQUALS(j.day(), 5);
		TS_ASSERT_EQUALS(g.ejd, g.cd.ejd);
		TS_ASSERT_EQUALS(j.ejd, j.cd.ejd);

		g.ejd -= 200000;
		j.ejd -= 200000;
		TS_ASSERT_EQUALS(g.mod_julian_day(), -200000);
		TS_ASSERT_EQUALS(j.mod_julian_day(), -200000);
		TS_ASSERT_EQUALS(g.year(), 1311);
		TS_ASSERT_EQUALS(j.year(), 1311);
		TS_ASSERT_EQUALS(g.month(), 4);
		TS_ASSERT_EQUALS(j.month(), 4);
		TS_ASSERT_EQUALS(g.day(), 19);
		TS_ASSERT_EQUALS(j.day(), 11);
		TS_ASSERT_EQUALS(g.ejd, g.cd.ejd);
		TS_ASSERT_EQUALS(j.ejd, j.cd.ejd);
	}

	void testTodaysDate () { //Not really a test, just writing out todays date. Check manually if this is indeeed todays date.
		time_t t;
		time(&t);
		set_k_time(t);
		Gregorian g;
		Julian j;
		std::cout  << std::endl << std::endl;
		std::cout << " Today's Gregorian date is: " << g << " with modified julian day: " << g.mod_julian_day();
		std::cout << std::endl;
		std::cout << " Today's Julian date is: " << j << " with modified julian day: " << g.mod_julian_day();
		std::cout << std::endl << std::endl;
	}
};