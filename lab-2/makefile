.DEFAULT_GOAL := runner

runner: gregorian julian kattistime
	cxxtestgen --error-printer -o runner.cpp cxxtest_date.h
	g++ -std=c++11 -Wall -Wextra -o runner.out runner.cpp kattistime.o date.o gregorian.o julian.o
	@echo "..........Runner was successfully compiled!"
	@echo ""

kattistime:
	g++ -std=c++11 -Wall -Wextra -c kattistime.cpp -o kattistime.o
	@echo "..........Kattistime was successfully compiled!"
	@echo ""

date: kattistime
	g++ -std=c++11 -Wall -Wextra -c date.cpp -o date.o
	@echo "..........Date was successfully compiled!"
	@echo ""

gregorian: date
	g++ -std=c++11 -Wall -Wextra -c gregorian.cpp -o gregorian.o
	@echo "..........gregorian was successfully compiled!"
	@echo ""

julian: date
	g++ -std=c++11 -Wall -Wextra -c julian.cpp -o julian.o
	@echo "..........julian was successfully compiled!"
	@echo ""

clean:
	rm -f *.o *.out