#include "julian.hpp"


lab2::Julian::~Julian (){
}

unsigned int lab2::Julian::days_in_month(int month, int year) const {
	return month_lengths.at(month-1) + ((month == 2 && is_leap_year(year))? 1:0);
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
	if(month() > m) {
		ejd--;
		return;
	}
	if(month() < m) {
		ejd++;
		return;
	}
	if(day() > d) {
		ejd--;
		return;
	}
	if(day() > d) {
		ejd++;
		return;
	}
	std::cerr << "IF THIS PRINTS, SOMETHING HAS GONE TERRIBLY WRONG IN ADD_YEAR";
	return;
}

void lab2::Julian::add_month(int n) {
	unsigned int d = day();
	unsigned int m = month();
	if (n > 12) {
		add_year(n - (n%12));
		n = n%12;
	}
	while((m+n)%12 != month()) {
		ejd+=27;
	}
	if(days_in_month(month(), year()) >= d) {
		ejd += (int)d - (int)day();
	} else {
		ejd += std::min( (int)days_in_month(month(), year()) - (int)day(), (int)d - (int)day() );
	}
}