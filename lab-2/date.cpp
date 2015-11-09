#include "date.hpp"


void lab2::Date::calculate_date() const {
	cd.ejd = fjd;
	cd.year = 0;
	cd.day = cd.month = 1;
	while(true) {
		if(cd.ejd + (int)days_in_year(cd.year) <= ejd) {
			cd.ejd += (int)days_in_year(cd.year);
			cd.year++;
		} else
			break;
	}
	while(true) {
		if(cd.ejd + (int)days_in_month(cd.month, cd.year) <= ejd) {
			cd.ejd += (int)days_in_month(cd.month, cd.year);
			cd.month++;
		} else
			break;
	}
	cd.day += ejd - cd.ejd;
	cd.ejd += cd.day - 1;
}

lab2::Date::Date() {
	time_t my_time;
	k_time(&my_time);
	struct tm *t = gmtime(&my_time);
    int year  = t->tm_year + 1900;
    int month = t->tm_mon;
    int day   = t->tm_mday;

    if( (year == 0 && month <= 2) || year < 0 || year > 3000 || month > 12 || month < 1 || day < 1) //Never checks if day is too large for month, but if the years are right the gmtime shouldnt be wrong.
		std::invalid_argument("Not a valid date");

	ejd = fjd;
	while(year >= 400) {
		year -= 400;
		ejd += 97 * 366 + 303 * 365;
	}
	while(year >= 100) {
		year -= 100;
		ejd += 24 * 366 + 76 * 365;
	}
	while(year >= 4) {
		year -= 4;
		ejd +=  366 + 3 * 365;
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


lab2::Date::Date(int e) {
	ejd = e;
}

lab2::Date::Date(const Date& d) {
	ejd = d.ejd;
}

lab2::Date::~Date() {
}

bool lab2::Date::operator==(const Date& d) const {
	return ejd == d.ejd;
}

bool lab2::Date::operator!=(const Date& d) const {
	return ejd !=  d.ejd;
}

bool lab2::Date::operator<(const Date& d) const {
	return ejd < d.ejd;
}

bool lab2::Date::operator<=(const Date& d) const {
	return ejd <= d.ejd;
}

bool lab2::Date::operator>(const Date& d) const {
	return ejd > d.ejd;
}

bool lab2::Date::operator>=(const Date& d) const {
	return ejd >= d.ejd;
}

lab2::Date& lab2::Date::operator=(const Date& d) {
	ejd = d.ejd;
	return *this;
}

int lab2::Date::operator-(const Date& d) const{
	return ejd-d.ejd;
}

int lab2::Date::year() const {
	if(cd.ejd != ejd)
		calculate_date();
	return cd.year;
}

unsigned int lab2::Date::month() const {
	if(cd.ejd != ejd)
		calculate_date();
	return cd.month;
}

unsigned int lab2::Date::day() const {
	if(cd.ejd != ejd)
		calculate_date();
	return cd.day;
}

unsigned int lab2::Date::week_day() const {
	return (ejd - fjd + 5) % days_per_week() + 1; //5 is added because fjd is a saturday. 1 is added because the specification call for 1..n indexing of the days.
}

unsigned int lab2::Date::days_per_week() const {
	return 7;
}

unsigned int lab2::Date::days_this_month() const {
	return days_in_month(month(), year());
}

unsigned int lab2::Date::days_in_year(int year) const {
	return 365 + (is_leap_year(year)? 1:0);
}

std::string lab2::Date::week_day_name() const {
	return week_day_names[week_day()-1];
}

std::string lab2::Date::month_name() const {
	return month_names[month()-1];
}

int lab2::Date::mod_julian_day() const {
	return ejd - 2400001;
}

int lab2::Date::early_julian_day() const {
	return ejd;
}