CXX = g++
CXXFLAGS = -Wall -pedantic -g -O3

all: picker pair grouper fake

fakes.o: fakes.c fakes.h randomizer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

faker.o: faker.c fakes.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

fake: faker.o fakes.o randomizer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

randomizer.o: randomizer.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

set.o: set.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

picker.o: picker.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

picker: picker.o set.o randomizer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

pair: pair.o init.o randomizer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

grouper: grouper.o init.o set.o randomizer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o picker pair grouper fake
