###############################################################################
# -->Makefile<--
###############################################################################

###############################################################################
#
# Programmer :  Christine Wang
# Assignment :  Assignment 2
#
# Instructor :  Clayton Price
# Course     :  CS5201
# Semester   :  Spring 2015
#
###############################################################################

###############################################################################
# This makefile will build an executable for the assignment.
###############################################################################

.PHONY: all clean

CXX = /usr/bin/g++
CXXFLAGS = -g -Wall -W -pedantic-errors 

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

OBJECTS = $(SOURCES:%.cpp=%.o)

default: driver

%.o: %.cpp
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

driver: $(OBJECTS)
	@echo "Building $@"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@
	@echo ""
	@echo "Everything worked :-) "
	@echo ""

clean:
	-@rm -f core
	-@rm -f driver
	-@rm -f $(OBJECTS)

depend: $(SOURCES) $(HEADERS)
	@echo "Generating dependencies"
	@$(CXX) -MM *.cpp > $@


-include depend