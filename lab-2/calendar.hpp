#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include "kattistime.h"
#pragma once

namespace lab2 {

	template <class T>
	struct event{
		std::string description;
		T d;
		event() {
		}
	};

	template <class T>
	class Calendar {
	private:
		T d;
		event<T> e;
	public:
		template <class T2>
		Calendar(const Calendar<T2> &c) {
			d = c.view_date_component();
		}
		Calendar();
		~Calendar();
		const Date& view_date_component() const;
		bool set_date(int, int, int);
		bool add_event(std::string);
		bool add_event(std::string, int);
		bool add_event(std::string, int, int);
		bool add_event(std::string, int, int, int);
		bool remove_event(std::string);
		bool remove_event(std::string, int);
		bool remove_event(std::string, int, int);
		bool remove_event(std::string, int, int, int);
		friend std::ostream& operator << (std::ostream &os, Calendar<T> &c) {
			os << "BEGIN:VCALENDAR" << std::endl;
			os << "VERSION:2.0" << std::endl;
			os << "PRODID:???????" << std::endl;
			os << "BEGIN:VEVENT" << std::endl;
			os << "DTSTART:19960401T120000" << std::endl;
			os << "DESCRIPTION:" << c.e.description << std::endl;
			os << "END:VEVENT" << std::endl;
			os << "END:VCALENDAR";
			return os;
		}
	};

	template <class T>
	Calendar<T>::Calendar() {
	}

	template <class T>
	Calendar<T>::~Calendar() {
	}

	template <class T>
	const Date& Calendar<T>::view_date_component() const {
		return d;
	}
}