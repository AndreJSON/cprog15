#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include "kattistime.h"
#include <map>
#pragma once
//#define private public //DURING TESTING ONLY!!!!!!!!!!!!!

namespace lab2 {

	template <class T>
	class Calendar {
	private:
		T *dp;
		std::map<T*, std::vector<std::string>> event_map;
	public:
		template <class T2>
		Calendar(const Calendar<T2> &c) {
			dp = new T(c.view_date_component());
		}
		Calendar(const Calendar<T> &c) {
			dp = new T(c.view_date_component());
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
		friend std::ostream& operator << (std::ostream &os, const Calendar<T> &c) {
			os << "BEGIN:VCALENDAR" << std::endl;
			os << "VERSION:2.0" << std::endl;
			os << "PRODID:???????" << std::endl;
			os << "BEGIN:VEVENT" << std::endl;
			os << "DTSTART:19960401T120000" << std::endl;
			os << "DESCRIPTION:" << std::endl;
			os << "END:VEVENT" << std::endl;
			os << "END:VCALENDAR";
			return os;
		}
	};

	template <class T>
	Calendar<T>::Calendar() {
		dp = new T();
	}

	template <class T>
	Calendar<T>::~Calendar() {
		delete dp;
	}

	template <class T>
	const Date& Calendar<T>::view_date_component() const {
		return *dp;
	}

	template <class T>
	bool Calendar<T>::set_date(int year, int month, int day) {
		dp = new T(year, month, day);
		return false; //Change this to accurately reflect the aility to set the date.
	}

	template <class T>
	bool Calendar<T>::add_event(std::string desc) {
		try {
			T *tmp = new T(*dp);
			/*if(event_map.find(tmp)) {
				event_map[tmp].push_back(desc);
			}*/
		}
		catch(...) {
			return false;
		}
		return true;
	}
}