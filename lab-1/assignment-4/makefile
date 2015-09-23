.DEFAULT_GOAL := all
all: count_if_followed_by runner

count_if_followed_by:
	@echo " "
	g++ -c -o count_if_followed_by.o count_if_followed_by.cpp
	@echo "-------- count_if_followed_by.o built --------"
	@echo " "
	
runner: count_if_followed_by
	@echo " "
	cxxtestgen --error-printer -o runner.cpp testSuite1.h
	g++ -o runner.out runner.cpp count_if_followed_by.o
	@echo "-------- runner built --------"
	@echo " "