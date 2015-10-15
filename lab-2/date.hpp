#include <string>

namespace lab2 {
	class Date {
	protected:
		int ejd; //Early Julian Day.
		std::string day_names[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
		std::string month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		//virtual int is_leap_year(some type) = 0; not fully sure what should be passed here. I will settle that later.
	public:
		virtual Date () = 0;
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