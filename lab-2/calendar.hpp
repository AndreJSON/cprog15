#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include "kattistime.h"
#include <map>
#include <set>
#pragma once

namespace lab2 {

	template <class T>
	class Calendar {
	private:
		T *dp;
		std::map<T, std::set<std::string>*> event_map;
	public:
		template <class T2>
		Calendar(const Calendar<T2> &c) {
			for (auto i = c.view_event_map().begin(); i != c.view_event_map().end(); i++) {
				T tmp(i->first);
				event_map[tmp] = new std::set<std::string>();
				for(auto desc = i->second->begin(); desc != i->second->end(); desc++) {
					event_map[tmp]->insert(*desc);
				}
			}
			dp = new T(c.view_date_component());
		}
		Calendar(const Calendar<T> &c) {
			for (auto i = c.view_event_map().begin(); i != c.view_event_map().end(); i++) {
				event_map[i->first] = new std::set<std::string>();
				for(auto desc = i->second->begin(); desc != i->second->end(); desc++) {
					event_map[i->first]->insert(*desc);
				}
			}
			dp = new T(c.view_date_component());
		}
		Calendar();
		~Calendar();

		const Date& view_date_component() const;
		const std::map<T, std::set<std::string>*>& view_event_map() const;
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
			for (auto i = c.event_map.begin(); i != c.event_map.end(); i++) {
				for(auto desc = i->second->begin(); desc != i->second->end(); desc++) {
					os << "BEGIN:VEVENT" << std::endl;
					os << "DTSTART:" << i->first.year() << i->first.month() << i->first.day() << "T120000" << std::endl;
					os << "SUMMARY:" << *desc << std::endl;
					os << "DESCRIPTION:" << *desc << std::endl;
					os << "END:VEVENT" << std::endl;
				}
			}
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
		for(auto i = event_map.begin(); i != event_map.end(); i++) {
			delete i->second;
		}
		delete dp;
	}

	template <class T>
	const Date& Calendar<T>::view_date_component() const {
		return *dp;
	}

	template <class T>
	const std::map<T, std::set<std::string>*>& Calendar<T>::view_event_map() const {
		return event_map;
	}

	template <class T>
	bool Calendar<T>::set_date(int year, int month, int day) {
		dp = new T(year, month, day);
		return false; //Change this to accurately reflect the ability to set the date.
	}

	template <class T>
	bool Calendar<T>::add_event(std::string desc) {
		return add_event(desc, dp->day(), dp->month(), dp->year());
	}

	template <class T>
	bool Calendar<T>::add_event(std::string desc, int day) {
		return add_event(desc, day, dp->month(), dp->year());
	}

	template <class T>
	bool Calendar<T>::add_event(std::string desc, int day, int month) {
		return add_event(desc, day, month, dp->year());
	}

	template <class T>
	bool Calendar<T>::add_event(std::string desc, int day, int month, int year) {
		try {
			T tmp(year, month, day);
			if(event_map.find(tmp) != event_map.end()) {
				return (event_map[tmp]->insert(desc)).second;
			}
			else {
				event_map[tmp] = new std::set<std::string>();
				event_map[tmp]->insert(desc);
			}
		}
		catch(...) {
			return false;
		}
		return true;
	}

	template <class T>
	bool Calendar<T>::remove_event(std::string desc) {
		return remove_event(desc, dp->day(), dp->month(), dp->year());
	}

	template <class T>
	bool Calendar<T>::remove_event(std::string desc, int day) {
		return remove_event(desc, day, dp->month(), dp->year());
	}

	template <class T>
	bool Calendar<T>::remove_event(std::string desc, int day, int month) {
		return remove_event(desc, day, month, dp->year());
	}

	template <class T>
	bool Calendar<T>::remove_event(std::string desc, int day, int month, int year) {
		try {
			T tmp(year, month, day);
			if(event_map.find(tmp) != event_map.end()) {
				if(event_map[tmp]->erase(desc) == 0) {
					return false;
				}
			}
		}
		catch(...) {
			return false;
		}
		return true;
	}
}