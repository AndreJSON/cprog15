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
		g+=998;
		g++;
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
		TS_ASSERT_EQUALS((*g).ejd, 2440588);
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

		Julian j;
		y = 1969;
		m = 12;
		d = 19;
		TS_ASSERT_EQUALS(j.year(), y);
		TS_ASSERT_EQUALS(j.month(), m);
		TS_ASSERT_EQUALS(j.day(), d);

		j-= (365 * 600 + 366 * 200);
		y-= 800;
		TS_ASSERT_EQUALS(j.year(), y);
		TS_ASSERT_EQUALS(j.month(), m);
		TS_ASSERT_EQUALS(j.day(), d);

		j.add_year(1000);
		y+=1000;
		TS_ASSERT_EQUALS(j.year(), y);
		TS_ASSERT_EQUALS(j.month(), m);
		TS_ASSERT_EQUALS(j.day(), d);
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

		g-= (365 * 606 + 366 * 194);
		y-= 800;
		TS_ASSERT_EQUALS(g.year(), y);
		TS_ASSERT_EQUALS(g.month(), m);
		TS_ASSERT_EQUALS(g.day(), d);

		g.add_month(9600);
		y+= 800;
		TS_ASSERT_EQUALS(g.year(), y);
		TS_ASSERT_EQUALS(g.month(), m);
		TS_ASSERT_EQUALS(g.day(), d);

		Julian j;
		y = 1969;
		m = 12;
		d = 19;

		j-= (365 * 600 + 366 * 200);
		y-= 800;
		TS_ASSERT_EQUALS(j.year(), y);
		TS_ASSERT_EQUALS(j.month(), m);
		TS_ASSERT_EQUALS(j.day(), d);

		j.add_month(12000);
		y+= 1000;
		TS_ASSERT_EQUALS(j.year(), y);
		TS_ASSERT_EQUALS(j.month(), m);
		TS_ASSERT_EQUALS(j.day(), d);
	}

	void test9 () { //Testing operator-
		time_t t = 0;
		set_k_time(t);

		Gregorian g1, g2;
		TS_ASSERT_EQUALS(g1-g2, 0);
		g1++;
		TS_ASSERT_EQUALS(g1-g2, 1);
		g1-=2;
		TS_ASSERT_EQUALS(g1-g2, -1);
		g1+=501;
		TS_ASSERT_EQUALS(g1-g2, 500);

		Julian j1, j2;
		TS_ASSERT_EQUALS(j1-j2, 0);
		j1++;
		TS_ASSERT_EQUALS(j1-j2, 1);
		j1-=2;
		TS_ASSERT_EQUALS(j1-j2, -1);
		j1+=501;
		TS_ASSERT_EQUALS(j1-j2, 500);

		const Gregorian& g3 = g1;
		const Julian& j3 = j1;
		const Date& d1 = j1;
		const Date& d2 = g1;
		TS_ASSERT_EQUALS(d1-d2, 0);
		TS_ASSERT_EQUALS(g3-j3, 0);
		TS_ASSERT_EQUALS(d1-j1, g1-d2);
		TS_ASSERT_EQUALS(j1-j1, 0);
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

		const Gregorian j4, j5;
		TS_ASSERT_EQUALS(j4==j5, true);
		j1-=500;
		j1=j4;
		TS_ASSERT_EQUALS(j4==j1, true);
		TS_ASSERT_EQUALS(j1==j5, true);
		//j5=j2; //Should not compile 

	}

	void test12 () { //Testing the (y,m,d) constructor.
		Gregorian g1(2015, 6, 3);
		Julian j1(2015, 6, 3);
		/*TS_ASSERT_EQUALS(g1==j1, false);
		TS_ASSERT_EQUALS(g1.year(), 2015);
		TS_ASSERT_EQUALS(g1.month(), 6);
		TS_ASSERT_EQUALS(g1.day(), 3);
		TS_ASSERT_EQUALS(g1.mod_julian_day(),57176);
		TS_ASSERT_EQUALS(j1.year(), 2015);
		TS_ASSERT_EQUALS(j1.month(), 6);
		TS_ASSERT_EQUALS(j1.day(), 3);
		TS_ASSERT_EQUALS(j1.mod_julian_day(),57189);)*/
	}

	void test13 () {
		time_t t = 0;
		set_k_time(t);
		Gregorian g;
		Julian j(g);
		TS_ASSERT_EQUALS(j.mod_julian_day(), g.mod_julian_day());
		TS_ASSERT_EQUALS(j==g, true);
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

	void testSpecific1 () {
		Julian j(2140, 8, 9);
		j.add_year(18);
		j += 18;
		j.add_month(18);
		j -= 18;
		j += -18;
		TS_ASSERT_EQUALS(j.year(), 2160);
		TS_ASSERT_EQUALS(j.month(), 1);
		TS_ASSERT_EQUALS(j.day(), 22);

		j.add_year(-18);
		TS_ASSERT_EQUALS(j.year(), 2142);
		TS_ASSERT_EQUALS(j.month(), 1);
		TS_ASSERT_EQUALS(j.day(), 22);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 103444);
	}

	void testSpecific2 () {
		Julian j1(2290, 6, 6);
		TS_ASSERT_EQUALS(j1.year(), 2290);
		TS_ASSERT_EQUALS(j1.month(), 6);
		TS_ASSERT_EQUALS(j1.day(), 6);
		TS_ASSERT_EQUALS(j1.mod_julian_day(), 157636);

		Julian j2(1858, 11, 6);
		TS_ASSERT_EQUALS(j2.year(), 1858);
		TS_ASSERT_EQUALS(j2.month(), 11);
		TS_ASSERT_EQUALS(j2.day(), 6);
		TS_ASSERT_EQUALS(j2.mod_julian_day(), 1);

		Julian j3(2000, 11, 6);
		TS_ASSERT_EQUALS(j3.year(), 2000);
		TS_ASSERT_EQUALS(j3.month(), 11);
		TS_ASSERT_EQUALS(j3.day(), 6);
		TS_ASSERT_EQUALS(j3.mod_julian_day(), 51867);

		Julian j4(2000, 1, 6);
		TS_ASSERT_EQUALS(j4.year(), 2000);
		TS_ASSERT_EQUALS(j4.month(), 1);
		TS_ASSERT_EQUALS(j4.day(), 6);
		TS_ASSERT_EQUALS(j4.mod_julian_day(), 51562);

		Julian j5(4, 4, 6);
		TS_ASSERT_EQUALS(j5.year(), 4);
		TS_ASSERT_EQUALS(j5.month(), 4);
		TS_ASSERT_EQUALS(j5.day(), 6);
		TS_ASSERT_EQUALS(j5.mod_julian_day(), -677386);

		Julian j6(3, 4, 6);
		TS_ASSERT_EQUALS(j6.year(), 3);
		TS_ASSERT_EQUALS(j6.month(), 4);
		TS_ASSERT_EQUALS(j6.day(), 6);
		TS_ASSERT_EQUALS(j6.mod_julian_day(), -677752);

		Julian j7(2214, 7, 23);
		TS_ASSERT_EQUALS(j7.year(), 2214);
		TS_ASSERT_EQUALS(j7.month(), 7);
		TS_ASSERT_EQUALS(j7.day(), 23);
		TS_ASSERT_EQUALS(j7.mod_julian_day(), 129924);
	}

	void testSpecific3 () {
		time_t t = 1835352793;
		set_k_time(t);
		Julian j1;
		TS_ASSERT_EQUALS(j1.mod_julian_day(), 61829);
		TS_ASSERT_EQUALS(j1.year(), 2028);
		TS_ASSERT_EQUALS(j1.month(), 2);
		TS_ASSERT_EQUALS(j1.day(), 15);

		t -= 15 * 86400;
		set_k_time(t);
		Julian j2;
		TS_ASSERT_EQUALS(j2.mod_julian_day(), 61814);
		TS_ASSERT_EQUALS(j2.year(), 2028);
		TS_ASSERT_EQUALS(j2.month(), 1);
		TS_ASSERT_EQUALS(j2.day(), 31);

		t += 30 * 86400;
		set_k_time(t);
		Julian j3;
		TS_ASSERT_EQUALS(j3.mod_julian_day(), 61844);
		TS_ASSERT_EQUALS(j3.year(), 2028);
		TS_ASSERT_EQUALS(j3.month(), 3);
		TS_ASSERT_EQUALS(j3.day(), 1);

		t += 30 * 86400;
		set_k_time(t);
		Julian j4;
		TS_ASSERT_EQUALS(j4.mod_julian_day(), 61874);
		TS_ASSERT_EQUALS(j4.year(), 2028);
		TS_ASSERT_EQUALS(j4.month(), 3);
		TS_ASSERT_EQUALS(j4.day(), 31);

		t -= 400 * 86400;
		set_k_time(t);
		Julian j5;
		TS_ASSERT_EQUALS(j5.mod_julian_day(), 61474);
		TS_ASSERT_EQUALS(j5.year(), 2027);
		TS_ASSERT_EQUALS(j5.month(), 2);
		TS_ASSERT_EQUALS(j5.day(), 25);

		t -= 1103 * 86400;
		set_k_time(t);
		Julian j6;
		TS_ASSERT_EQUALS(j6.mod_julian_day(), 60371);
		TS_ASSERT_EQUALS(j6.year(), 2024);
		TS_ASSERT_EQUALS(j6.month(), 2);
		TS_ASSERT_EQUALS(j6.day(), 18);

		t -= 1 * 86400;
		set_k_time(t);
		Julian j7;
		TS_ASSERT_EQUALS(j7.mod_julian_day(), 60370);
		TS_ASSERT_EQUALS(j7.year(), 2024);
		TS_ASSERT_EQUALS(j7.month(), 2);
		TS_ASSERT_EQUALS(j7.day(), 17);


		t -= 1 * 86400;
		set_k_time(t);
		Julian j8;
		TS_ASSERT_EQUALS(j8.mod_julian_day(), 60369);
		TS_ASSERT_EQUALS(j8.year(), 2024);
		TS_ASSERT_EQUALS(j8.month(), 2);
		TS_ASSERT_EQUALS(j8.day(), 16);

    	t = 0;
		set_k_time(t);
		Julian j9;
		TS_ASSERT_EQUALS(j9.mod_julian_day(), 40587);
		TS_ASSERT_EQUALS(j9.year(), 1969);
		TS_ASSERT_EQUALS(j9.month(), 12);
		TS_ASSERT_EQUALS(j9.day(), 19);
	}

	void testSpecific4 () {
		Julian j(2035,1,1);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 64341);
		TS_ASSERT_EQUALS(j.year(), 2035);
		TS_ASSERT_EQUALS(j.month(), 1);
		TS_ASSERT_EQUALS(j.day(), 1);

		j.add_year(17);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 70550);
		TS_ASSERT_EQUALS(j.year(), 2052);
		TS_ASSERT_EQUALS(j.month(), 1);
		TS_ASSERT_EQUALS(j.day(), 1);

		j.add_year(-17);
		TS_ASSERT_EQUALS(j.mod_julian_day(), 64341);
		TS_ASSERT_EQUALS(j.year(), 2035);
		TS_ASSERT_EQUALS(j.month(), 1);
		TS_ASSERT_EQUALS(j.day(), 1);
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