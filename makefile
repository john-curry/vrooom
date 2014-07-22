CC = g++
LIBS =
FLAGS = -g -std=c++11 -Wall -pedantic -o
PROGRAM = vm
FILES=$(addprefix .build/, $(patsubst %.cpp, %.o, $(wildcard *.cpp)))

all: $(PROGRAM)

$(PROGRAM): $(FILES)
	$(CC) $(FLAGS) $@ $^ $(LIBS)

.build/%.o: %.cpp
	$(CC) $(FLAGS) $@ -c $^ $(LIBS)

.PHONY: clean
clean:
	rm -rf .build/* $(PROGRAM)
