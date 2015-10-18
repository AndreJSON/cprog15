.DEFAULT_GOAL := runner

runner: julian
	cxxtestgen --error-printer -o runner.cpp cxxtest_date.h
	g++ -std=c++11 -Wall -Wextra -o runner.out runner.cpp
	@echo "..........Runner was successfully compiled!"
	@echo ""

kattistime:
	g++ -std=c++11 -Wall -Wextra -c kattistime.cpp
	@echo "..........Kattistime was successfully compiled!"
	@echo ""

date: kattistime
	g++ -std=c++11 -Wall -Wextra -c date.cpp -o date.o
	@echo "..........Date was successfully compiled!"
	@echo ""

julian: date
	g++ -std=c++11 -Wall -Wextra -c julian.cpp -o julian.o
	@echo "..........Julian was successfully compiled!"
	@echo ""