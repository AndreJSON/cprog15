#include "gregorian.hpp"

lab2::Gregorian::Gregorian() : Date() {
}

lab2::Gregorian::Gregorian(int e) : Date(e){
}

lab2::Gregorian::Gregorian(int y, int m, int d) {
	if( (y == 0 && m <= 2) || y < 0 || y > 3000 || m > 12 || m < 1 || d < 1 || (int)days_in_month(m, y) < d)
		std::invalid_argument("Not a valid date");
	ejd = fjd;
	while(y >= 400) {
		y -= 400;
		ejd += 97 * 366 + 303 * 365;
	}
	while(y >= 100) {
		y -= 100;
		ejd += 24 * 366 + 76 * 365;
	}
	while(y >= 4) {
		y -= 4;
		ejd +=  366 + 3 * 365;
	}
	while(y >= 1) {
		y --;
		ejd += 365;
	}
	while(m > 1) {
		ejd += month_lengths[m-1];
		m--;
	}
	ejd += d; //Should be -1 since first day has index 1, but since year 0 is a leap year, we also need to add 1.
}

lab2::Gregorian::~Gregorian() {
}

lab2::Gregorian& lab2::Gregorian::operator++() {
	if(ejd < 2998560) //year 3500.
		ejd++;
	else
		throw std::out_of_range("Invalid Date");
	return *this;
}

lab2::Gregorian& lab2::Gregorian::operator--() {
	if(ejd > (fjd+60)) //year 0 a little after march 1.
		ejd--;
	else
		throw std::out_of_range("Invalid Date");
	return *this;
}

lab2::Gregorian lab2::Gregorian::operator++(int) {
	Gregorian tmp((*this).ejd);
	++(*this);
	return tmp;
}

lab2::Gregorian lab2::Gregorian::operator--(int) {
	Gregorian tmp((*this).ejd);
	--(*this);
	return tmp;
}

lab2::Gregorian& lab2::Gregorian::operator+=(const int& i) {
	if(ejd+i < 2998560) //year 3500.
		ejd+=i;
	else
		throw std::out_of_range("Invalid Date");
	return *this;
}

lab2::Gregorian& lab2::Gregorian::operator-=(const int& i) {
	if(ejd-i > (fjd+60)) //year 0 a little after march 1.
		ejd-=i;
	else
		throw std::out_of_range("Invalid Date");
	return *this;
}

unsigned int lab2::Gregorian::days_in_month(int month, int year) const {
	return month_lengths.at(month-1) + ((month == 2 && is_leap_year(year))? 1:0);
}

bool lab2::Gregorian::is_leap_year(int year) const {
	if(year%400 == 0)
		return true;
	if(year%100 == 0)
		return false;
	if(year%4 == 0)
		return true;
	else
		return false;
}

void lab2::Gregorian::add_year(int n) {
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

void lab2::Gregorian::add_month(int n) {
	unsigned int d = day();
	unsigned int m = month();
	if (n > 12) {
		add_year( (n-(n%12)) /12 );
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