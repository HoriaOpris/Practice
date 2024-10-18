Compiler = gcc-14
Flags = -Wall -Isrc/app
SRC_DIRS := ./src

SRCS := $(shell find $(SRC_DIRS) -name '*.c')

clean:
	rm *.out

all:
	$(Compiler) $(Flags) $(SRCS) -o Program.out