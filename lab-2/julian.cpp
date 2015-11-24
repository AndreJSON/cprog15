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

void lab2::Julian::add_year(int n) {
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
	if(day() < d) {
		ejd++;
		return;
	}
	std::cerr << "IF THIS PRINTS, SOMETHING HAS GONE TERRIBLY WRONG IN ADD_YEAR";
	return;
}

void lab2::Julian::subtract_year(int n) {
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

void lab2::Julian::add_month(int n) {
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

void lab2::Julian::subtract_month(int n) {
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