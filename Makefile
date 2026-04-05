CC = g++  
CXX = g++
CFLAGS = -Wall -pedantic -g -O3
CXXFLAGS = -Wall -pedantic -g -O3

all: picker pair grouper

randomizer.o: randomizer.c
	$(CC) $(CFLAGS) -c $< -o $@

set.o: set.c
	$(CC) $(CFLAGS) -c $< -o $@

picker.o: picker.c
	$(CC) $(CFLAGS) -c $< -o $@

picker: picker.o set.o randomizer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

pair: pair.o init.o randomizer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

grouper: grouper.o init.o set.o randomizer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o picker pair grouper
