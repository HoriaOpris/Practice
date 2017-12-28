CXX = gcc
CXXFLAGS = -Wall -g -std=c99

build: main.o p16.o bigint.o isosceles.o
	$(CXX) $(CXXFLAGS) -o main main.o p16.o bigint.o isosceles.o
	
build_test: test.o p16.o bigint.o bigint_test.o
	$(CXX) $(CXXFLAGS) -o test test.o p16.o bigint.o bigint_test.o
	
main.o: main.c
	$(CXX) $(CXXFLAGS) -c main.c
	
test.o: test.c
	$(CXX) $(CXXFLAGS) -c test.c
	
p16.o: p16.c
	$(CXX) $(CXXFLAGS) -c p16.c 
	
bigint.o: utils/bigint.c
	$(CXX) $(CXXFLAGS) -c utils/bigint.c 
	
isosceles.o: P138/isosceles.c	
	$(CXX) $(CXXFLAGS) -c P138/isosceles.c
	
bigint_test.o: utils/bigint_test.c
	$(CXX) $(CXXFLAGS) -c utils/bigint_test.c 			 
	
clean:
	rm main test *.o