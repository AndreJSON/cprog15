#include "date.hpp"
#include <stdexcept>
#ifndef JULIAN_HPP
#define JULIAN_HPP
#define protected public //WHEN TESTING ONLY!!!

namespace lab2 {
	class Julian : public Date {
	protected:
		void calculate_date() const override;
		unsigned int days_in_month(int, int) const override;
		bool is_leap_year(int) const override;
	public:
		Julian();
		Julian(int e);
		~Julian();
		Julian& operator++() override;
		Julian& operator--() override;
		Julian operator++(int);
		Julian operator--(int);
		Julian& operator+=(const int&) override;
		Julian& operator-=(const int&) override;
		void add_year(int) override;
		void add_month(int) override;
		friend std::ostream& operator<< (std::ostream& os, const Julian& j) {
			return os <<  j.year() << "-" << j.month() << "-" << j.day();
		}
	};
}

#endif /* JULIAN_HPP */