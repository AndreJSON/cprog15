#include "date.hpp"
#ifndef JULIAN_HPP
#define JULIAN_HPP

namespace lab2 {
	class Julian : public Date {
	public:
		int year() const override;
		unsigned int month() const override;
		unsigned int day() const override;
		unsigned int week_day() const override;
		unsigned int days_per_week() const override;
		unsigned int days_this_month() const override;
		void add_year(int) override;
		void add_month(int) override;
	};
}

#endif /* JULIAN_HPP */