.DEFAULT_GOAL := u_int_vector
all: u_int_vector runner

u_int_vector:
	@echo " "
	g++ -std=c++11 -o u_int_vector.o -c u_int_vector.cpp
	@echo "-------- u_int_vector built --------"
	@echo " "

runner: u_int_vector
	@echo " "
	cxxtestgen --error-printer -o runner.cpp cxxtest_u_int_vector.h
	g++ -std=c++11 -o runner.out runner.cpp u_int_vector.o
	@echo "-------- runner built --------"
	@echo " "