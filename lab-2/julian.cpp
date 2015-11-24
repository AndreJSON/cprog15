#include "julian.hpp"

void lab2::Julian::calculate_date() const {
	cd.ejd = fjd - 2; //-2 because of the 2 day offset between julian and gregorian at year 1.
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

lab2::Julian::Julian() : Date() {
}

lab2::Julian::Julian(int e) : Date(e){
}

lab2::Julian::Julian(int y, int m, int d) {
	unsigned const yc = y;
	unsigned const mc = m;
	unsigned const dc = d;
	if((y == 0 && m <= 2) || y < 1 || y > 3000 || m > 12 || m < 1 || d < 1 || (int)days_in_month(m, y) < d)
		std::invalid_argument("Not a valid date");

	ejd = fjd;
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
	//Correct off-by-a-little problems.
	add_year(yc-year());
	add_month(mc-month());
	ejd+=(dc-day()); 
}

lab2::Julian::Julian(const Date& d) : Date(d) {
}

lab2::Julian::~Julian() {
}

lab2::Julian& lab2::Julian::operator++() {
	if(ejd < 2998560) //year 3500.
		ejd++;
	else
		throw std::out_of_range("Invalid Date");
	return *this;
}

lab2::Julian& lab2::Julian::operator--() {
	if(ejd > (fjd+60)) //year 0 a little after march 1.
		ejd--;
	else
		throw std::out_of_range("Invalid Date");
	return *this;
}

lab2::Julian lab2::Julian::operator++(int) {
	Julian tmp((*this).ejd);
	++(*this);
	return tmp;
}

lab2::Julian lab2::Julian::operator--(int) {
	Julian tmp((*this).ejd);
	--(*this);
	return tmp;
}

lab2::Julian& lab2::Julian::operator+=(const int& i) {
	if(ejd+i < 2998560) //year 3500.
		ejd+=i;
	else
		throw std::out_of_range("Invalid Date");
	return *this;
}

lab2::Julian& lab2::Julian::operator-=(const int& i) {
	if(ejd-i > (fjd+60)) //year 0 a little after march 1.
		ejd-=i;
	else
		throw std::out_of_range("Invalid Date");
	return *this;
}

unsigned int lab2::Julian::days_in_month(int month, int year) const {
	return month_lengths[month-1] + ((month == 2 && is_leap_year(year))? 1:0);
}

bool lab2::Julian::is_leap_year(int year) const {
	if(year%4 == 0)
		return true;
	else
		return false;
}