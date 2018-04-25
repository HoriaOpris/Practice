CXX = gcc
CXXFLAGS = -Wall -g -std=c99

build: main.o incomplete.o
	$(CXX) $(CXXFLAGS) -o main main.o incomplete.o
	
main.o: main.c
	$(CXX) $(CXXFLAGS) -c main.c
	
incomplete.o: incomplete.c
	$(CXX) $(CXXFLAGS) -c incomplete.c	
	