hashtabledriver: hash1.o hashtabledriver.o
	g++ -g -Wall -std=c++11 -o hashtabledriver hash1.o  hashtabledriver.o

hashtabledriver.o: hash1.cpp hash1.cpp hash1.h hashtabledriver.o
	g++ -g -Wall -std=c++11 -c hashtabledriver.cpp

hash1.o:	hash1.cpp hash1.h
	g++ -g -Wall -std=c++11 -c hash1.cpp