#include "julian.hpp"


unsigned int lab2::Julian::month() const {
	return 0;
}

unsigned int lab2::Julian::day() const {
	return 0;
}

unsigned int lab2::Julian::days_per_week() const {
	return 7;
}

unsigned int lab2::Julian::days_this_month() const {
	return 0;
}

bool lab2::Julian::is_leap_year(int year) const {
	if(year%400 == 0)
		return true;
	if(year%100 == 0)
		return false;
	if(year%4 == 0)
		return true;
	else
		return false;
}

void lab2::Julian::add_year(int n) {
	std::cout << n << std::endl;
}

void lab2::Julian::add_month(int n) {
	std::cout << n << std::endl;
}