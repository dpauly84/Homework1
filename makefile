CC=g++ -Wall

all: parts1

parts1: utils.o parts1.hpp parts1.cpp
	$(CC) -o parts1 parts1.cpp utils.o

utils.o: utils.hpp utils.cpp
	$(CC) -c utils.cpp

tidy :
	rm -f utils.o core

clean :
	rm -f parts1 utils.o core
