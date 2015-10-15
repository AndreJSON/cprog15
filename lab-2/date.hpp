#include <string>

namespace lab2 {
	class Date {
	public:
		virtual int year() = 0;
		virtual unsigned int month() = 0;
		virtual unsigned int day() = 0;
		virtual unsigned int week_day() = 0;
		virtual unsigned int days_per_week() = 0;
		virtual unsigned int days_this_month() = 0;
		virtual std::string week_day_name() = 0;
		virtual std::string month_name() = 0;
		virtual void add_year(int) = 0;
		virtual void add_month(int) = 0;
		virtual int mod_julian_day() = 0;
	};
}