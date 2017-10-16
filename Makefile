#
# Makefile to build and run termSnake
# Michael Dandrea
# Last Updated: 10/16/2017
#

# Variables
GPP     = g++
CFLAGS  = -g -std=c++11 #-static
LINKS	= -lncurses
RM      = rm -f
BINNAME = termSnake

# Default build condition
default: all

all: build

# build depends upon main.cpp, then runs the command:
# 	g++ -g -std=c++11 -o levelsort
build: main.cpp
	$(GPP) $(CFLAGS) -o $(BINNAME) main.cpp $(LINKS)

run: build
	./$(BINNAME)

clean veryclean:
	$(RM) $(BINNAME)
