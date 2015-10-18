#include "date.hpp"

lab2::Date::Date() {
	time_t my_time;
	k_time(&my_time);
	struct tm *t = gmtime(&my_time);
    int year  = t->tm_year + 1900;
    int month = t->tm_mon;
    int day   = t->tm_mday;

    //TODO: CHECK IF INPUT IS OK, ELSE ALGORITHM MIGHT CRASH.
	ejd = 1721060; //ejd for January 1st year 0 in the gregorian calendar.
	while(year >= 400) {
		year -= 400;
		ejd += 97 * 366 + 303 * 365;
	}
	while(year >= 4) {
		year -= 4;
		ejd += 365 * 3 + 366;
	}
	while(year >= 1) {
		year --;
		ejd += 365;
	}
	while(month > 0) {
		ejd += month_lengths[month-1];
		month--;
	}
	ejd += day; //Should be -1 since first day has index 1, but since year 0 is a leap year, we also need to add 1.
}

lab2::Date::~Date() {
}

std::string lab2::Date::week_day_name() const {
	return week_day_names.at(week_day()-1);
}

std::string lab2::Date::month_name() const {
	return month_names.at(month()-1);
}

int lab2::Date::mod_julian_day() const {
	return ejd - 2400000;
}

int lab2::Date::early_julian_day() const {
	return ejd;
}