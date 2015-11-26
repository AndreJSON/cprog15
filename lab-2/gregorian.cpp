#include "gregorian.hpp"

lab2::Gregorian::Gregorian() : Date() {
}

lab2::Gregorian::Gregorian(int e) : Date(e){
}

lab2::Gregorian::Gregorian(int y, int m, int d) {
	unsigned const yc = y;
	unsigned const mc = m;
	unsigned const dc = d;
	if((y == 0 && m <= 2) || y < 0 || y > 3000 || m > 12 || m < 1 || d < 1 || (int)days_in_month(mc, yc) < d || (d == 29 && m == 2 && is_leap_year(y) == 0)) {
		throw std::invalid_argument("Not a valid date");
	}
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
		ejd += month_lengths[m-2];
		m--;
	}
	//Correct off-by-a-little problems.
	add_year(yc-year());
	add_month(mc-month());
	ejd+=(dc-day());
}

lab2::Gregorian::Gregorian(const Date& d) : Date(d) {
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
	return month_lengths[month-1] + ((month == 2 && is_leap_year(year))? 1:0);
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