.DEFAULT_GOAL := runner

runner: kth_cprog_template_container.hpp
	@echo " "
	cxxtestgen --error-printer -o runner.cpp cxxtest_template_vector.h
	g++ -std=c++11 -Wall -Wextra -o runner.out runner.cpp
	@echo "-------- runner built --------"
	@echo " "