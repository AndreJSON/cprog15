#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include "kattistime.h"

#pragma once

namespace lab2 {
	template <class T>
	class Calendar {
	private:
		T d;
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