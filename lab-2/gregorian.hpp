#include "date.hpp"
#include <stdexcept>
#ifndef GREGORIAN_HPP
#define GREGORIAN_HPP
#define protected public //WHEN TESTING ONLY!!!

namespace lab2 {
	class Gregorian : public Date {
	protected:
		unsigned int days_in_month(int, int) const override;
		bool is_leap_year(int) const override;
		void subtract_month(int) override;
		void subtract_year(int) override;
	public:
		Gregorian();
		Gregorian(int e);
		Gregorian(int y, int m, int d);
		Gregorian(const Date&);
		~Gregorian();
		Gregorian& operator++() override;
		Gregorian& operator--() override;
		Gregorian operator++(int);
		Gregorian operator--(int);
		Gregorian& operator+=(const int&) override;
		Gregorian& operator-=(const int&) override;
		void add_year(int) override;
		void add_month(int) override;
		friend std::ostream& operator<< (std::ostream& os, const Gregorian& j) {
			return os <<  j.year() << "-" << j.month() << "-" << j.day();
		}
	};
}

#endif /* GREGORIAN_HPP */