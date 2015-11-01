#include <string>
#include <vector>
#include <iostream>
#include "kattistime.h"
#ifndef DATE_HPP
#define DATE_HPP

namespace lab2 {

	struct Calculated_Date {
	public:
		Calculated_Date() {
			ejd = year = 0;
			month = day = 1;
		}
		int ejd;
		int year;
		unsigned int month;
		unsigned int day;
	};

	/*
	* Dates from the first of march year 0 are ok.
	*
	* There are unfortunately a bunch of stupid constraints to the lab-task that prevents this abstract class from being written in a general and highly extensible way.
	*/
	class Date {
	private:
		void calculate_date() const;
		mutable Calculated_Date cd;
	protected:
		int fjd = 1721060; //1st of January year 0 in the Gregorian calendar expressed in julian days.
		int ejd; //Early Julian Day.
		std::vector<std::string> week_day_names = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
		std::vector<std::string> month_names = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		std::vector<int> month_lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	public:
		Date();
		virtual ~Date();
		int year() const;
		unsigned int month() const;
		unsigned int day() const;
		unsigned int week_day() const;
		unsigned int days_per_week() const;
		unsigned int days_this_month() const;
		virtual unsigned int days_in_month(int, int) const = 0;
		unsigned int days_in_year(int) const;	
		std::string week_day_name() const;
		std::string month_name() const;
		virtual void add_year(int) = 0;
		virtual void add_month(int) = 0;
		virtual bool is_leap_year(int) const = 0;
		int mod_julian_day() const;
		int early_julian_day() const;
	};
}

#endif /*DATE_HPP */