# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	January 2019
# Description:	Makefile for Lab 3 Dice Game

# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += Die.o
OBJECTS += LoadedDie.o
OBJECTS += Game.o

HPPs = Die.hpp
HPPs += LoadedDie.hpp
HPPs += Game.hpp

CPPs = main.cpp
CPPs += Die.cpp
CPPs += LoadedDie.cpp
CPPs += Game.cpp

# Targets needed to bring the executable up to date
lab3: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o lab3 $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

Die.o: Die.hpp

LoadedDie.o: LoadedDie.hpp

Game.o: Game.hpp

# Clean-up operations
clean:
	rm lab3 *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./lab3

zip:
	zip -D Lab3_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt
