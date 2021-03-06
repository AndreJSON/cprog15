#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "kattistime.h"
#ifndef DATE_HPP
#define DATE_HPP
#define protected public //WHEN TESTING ONLY!!!

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
	* There are unfortunately a bunch of constraints to the lab-task that prevents this abstract class from being written in a general and highly extensible way.
	*/
	class Date {
	protected:
		virtual void calculate_date() const;
		mutable Calculated_Date cd;
		const static int fjd = 1721060; //1st of January year 0 in the Gregorian calendar 12:00 expressed in julian days.
		int ejd; //Early Julian Day.
		static constexpr int month_lengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		virtual bool is_leap_year(int) const = 0;
		virtual unsigned int days_in_month(int, int) const = 0;
		unsigned int days_in_year(int) const;
		int early_julian_day() const;
		virtual void subtract_year(int);
		virtual void subtract_month(int);
	public:
		Date();
		Date(int e);
		Date(const Date&);
		virtual Date& operator++() = 0;
		virtual Date& operator--() = 0;
		virtual Date& operator+=(const int&) = 0;
		virtual Date& operator-=(const int&) = 0;
		bool operator==(const Date&) const;
		bool operator!=(const Date&) const;
		bool operator<(const Date&) const;
		bool operator<=(const Date&) const;
		bool operator>(const Date&) const;
		bool operator>=(const Date&) const;
		Date& operator=(const Date&);
		int operator-(const Date&) const;
		virtual ~Date();
		int year() const;
		unsigned int month() const;
		unsigned int day() const;
		unsigned int week_day() const;
		unsigned int days_per_week() const;
		unsigned int days_this_month() const;
		std::string week_day_name() const;
		std::string month_name() const;
		virtual void add_year(int);
		virtual void add_month(int);
		int mod_julian_day() const;
		friend std::ostream& operator<< (std::ostream& os, const Date& d) {
			return os <<  d.year() << "-" << d.month() << "-" << d.day();
		}
	};
}

#endif /*DATE_HPP */