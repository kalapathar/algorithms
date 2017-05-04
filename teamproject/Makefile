all: competition brute_force

clean:
	rm -rf competition.dSYM brute_force.dSYM
	rm competition brute_force

competition: comp.cpp
	g++ -g -Wall -std=c++11 -o competition comp.cpp

brute_force: bf.cpp
	g++ -g -Wall -std=c++11 -o brute_force bf.cpp