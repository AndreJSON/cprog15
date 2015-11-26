.DEFAULT_GOAL := calendar_runner

runner: gregorian julian kattistime
	cxxtestgen --error-printer -o runner.cpp cxxtest_date.h
	g++ -std=c++11 -Wall -Wextra -o runner.out runner.cpp kattistime.o date.o gregorian.o julian.o
	@echo "..........runner was successfully compiled!"
	@echo ""

kattistime:
	g++ -std=c++11 -Wall -Wextra -c kattistime.cpp -o kattistime.o
	@echo "..........kattistime was successfully compiled!"
	@echo ""

date: kattistime
	g++ -std=c++11 -Wall -Wextra -c date.cpp -o date.o
	@echo "..........date was successfully compiled!"
	@echo ""

gregorian: date
	g++ -std=c++11 -Wall -Wextra -c gregorian.cpp -o gregorian.o
	@echo "..........gregorian was successfully compiled!"
	@echo ""

julian: date
	g++ -std=c++11 -Wall -Wextra -c julian.cpp -o julian.o
	@echo "..........julian was successfully compiled!"
	@echo ""

calendar: calendar.hpp calendar.cpp julian gregorian date kattistime
	g++ -std=c++11 -Wall -Wextra -o calendar.o -c calendar.cpp
	@echo "..........calendar was successfully compiled!"
	@echo ""

calendar_runner: calendar cxxtest_calendar.h
	cxxtestgen --error-printer -o calendar_runner.cpp cxxtest_calendar.h
	g++ -std=c++11 -Wall -Wextra -o calendar_runner.out calendar_runner.cpp kattistime.o date.o gregorian.o julian.o calendar.o
	@echo "..........calendar_runner was successfully compiled!"
	@echo ""

clean:
	rm -f *.o *.out