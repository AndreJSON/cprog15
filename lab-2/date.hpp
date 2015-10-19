#include <string>
#include <vector>
#include <iostream>
#include "kattistime.h"
#ifndef DATE_HPP
#define DATE_HPP


/*
* Dates from the first of march year 0 are ok.
*/
namespace lab2 {
	class Date {
	private:
		int fjd = 1721060; //first julian day covered by this calendar, 1st of January year 0 in the Gregorian calendar.
	protected:
		int ejd; //Early Julian Day.
		std::vector<std::string> week_day_names = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
		std::vector<std::string> month_names = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		std::vector<int> month_lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	public:
		Date();
		~Date();
		virtual int year() const = 0;
		virtual unsigned int month() const = 0;
		virtual unsigned int day() const = 0;
		virtual unsigned int week_day() const;
		virtual unsigned int days_per_week() const = 0;
		virtual unsigned int days_this_month() const = 0;	
		virtual std::string week_day_name() const;			//Shouldn't be overridden unless there is good reason to.
		virtual std::string month_name() const;				//Shouldn't be overridden unless there is good reason to.
		virtual void add_year(int) = 0;
		virtual void add_month(int) = 0;
		int mod_julian_day() const;
		int early_julian_day() const;
	};
}

#endif /*DATE_HPP */