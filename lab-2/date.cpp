#include "date.hpp"

lab2::Date::Date () {
	ejd = 0;
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
	return ejd - 2400001;
}