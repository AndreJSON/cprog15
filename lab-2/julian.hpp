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
		Julian(int y, int m, int s);
		Julian(const Date&);
		~Julian();
		Julian& operator++() override;
		Julian& operator--() override;
		Julian operator++(int);
		Julian operator--(int);
		Julian& operator+=(const int&) override;
		Julian& operator-=(const int&) override;
	};
}

#endif /* JULIAN_HPP */