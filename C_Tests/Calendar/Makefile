CXX = gcc
CXXFLAGS = -g -O0 -Wall

all: main.o output.o input.o
	$(CXX) $(CXXFLAGS) -o main main.o output.o input.o

clean:
	rm main *.o