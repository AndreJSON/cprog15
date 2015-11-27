#include "date.hpp"

constexpr int lab2::Date::month_lengths[];

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
    int month = t->tm_mon + 1;
    int day   = t->tm_mday;

    if( (year == 0 && month <= 2) || year < 0 || year > 3000 || month > 12 || month < 1 || day < 1) //Never checks if day is too large for month, but if the years are right the gmtime shouldnt be wrong.
		std::invalid_argument("Not a valid date");

	ejd = 40587 + 2400001;
	ejd += (my_time - (my_time % 86400)) / 86400;
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
	switch(week_day()) {
		case 1: return "Monday";
		case 2: return "Tuesday";
		case 3: return "Wednesday";
		case 4: return "Thursday";
		case 5: return "Friday";
		case 6: return "Saturday";
		case 7: return "Sunday";
		default: return "This should never return";
	}
}

std::string lab2::Date::month_name() const {
	switch(month()) {
		case 1: return "January";
		case 2: return "February";
		case 3: return "March";
		case 4: return "April";
		case 5: return "May";
		case 6: return "June";
		case 7: return "July";
		case 8: return "August";
		case 9: return "September";
		case 10: return "October";
		case 11: return "November";
		case 12: return "December";
		default: return "This should never return";
	}
}

int lab2::Date::mod_julian_day() const {
	return ejd - 2400001;
}

int lab2::Date::early_julian_day() const {
	return ejd;
}

void lab2::Date::add_year(int n) {
	if(n<0) {
		subtract_year(-n);
		return;
	}
	unsigned int d = day();
	unsigned int m = month();
	int y = year();
	while (n > 0) {
		ejd += days_in_year(y);
		n--;
		y++;
	}
	if(d == day())
		return;
	if(m == 2 && d == 29) {
		ejd--;
		return;
	}
	if(month() == m+1) {
		ejd--;
		return;
	}
	if(month() == m-1) {
		ejd++;
		return;
	}
	if(month() != m){
		if(month()==12)
			ejd++;
		else
			ejd--;
		return;
	}
	if(day() > d) {
		ejd--; 
		return;
	}
	if(day() < d) {
		ejd++;
		return;
	}
	std::cerr << "IF THIS PRINTS, SOMETHING HAS GONE TERRIBLY WRONG IN ADD_YEAR";
	return;
}

void lab2::Date::subtract_year(int n) {
	unsigned int d = day();
	unsigned int m = month();
	int y = year();
	while (n > 0) {
		ejd -= days_in_year(y);
		n--;
		y--;
	}
	if(d == day())
		return;
	if(m == 2 && d == 29) {
		ejd--;
		return;
	}
	if(month() == m+1) {
		ejd--;
		return;
	}
	if(month() == m-1) {
		ejd++;
		return;
	}
	if(month() != m){
		if(month()==12)
			ejd++;
		else
			ejd--;
		return;
	}
	if(day() > d) {
		ejd--; 
		return;
	}
	if(day() < d) {
		ejd++;
		return;
	}

	std::cerr << "IF THIS PRINTS, SOMETHING HAS GONE TERRIBLY WRONG IN SUBTRACT_YEAR";
	return;
}

void lab2::Date::add_month(int n) {
	if(n<0) {
		subtract_month(-n);
		return;
	}
	unsigned int d = day();
	unsigned int m = month();
	if (n >= 12) {
		add_year( (n-(n%12)) /12 );
		n = n%12;
	}
	while((m+n)%12 != (month()%12)) {
		ejd+=27;
	}
	if(days_in_month(month(), year()) >= d) {
		ejd += (int)d - (int)day();
	} else {
		ejd += std::min( (int)days_in_month(month(), year()) - (int)day(), (int)d - (int)day() );
	}
}

void lab2::Date::subtract_month(int n) {
	unsigned int d = day();
	unsigned int m = month();
	if (n >= 12) {
		subtract_year( (n-(n%12)) /12 );
		n = n%12;
	}
	while((m-n+12)%12 != (month()%12)) {
		ejd-=27;
	}
	if(days_in_month(month(), year()) >= d) {
		ejd += (int)d - (int)day();
	} else {
		ejd += std::min( (int)days_in_month(month(), year()) - (int)day(), (int)d - (int)day() );
	}
}