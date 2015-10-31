#include "date.hpp"
#ifndef JULIAN_HPP
#define JULIAN_HPP

namespace lab2 {
	class Julian : public Date {
	public:
		unsigned int days_in_month(int, int) const override;
		bool is_leap_year(int) const override;
		void add_year(int) override;
		void add_month(int) override;
		friend std::ostream& operator<< (std::ostream& os, const Julian& j) {
			return os <<  j.year() << "-" << j.month() << "-" << j.day();
		}
	};
}

#endif /* JULIAN_HPP */