# makefile for MassEmailList
OBJS = main.o helperfunctions.o
EXES = emailList
CPPFLAGS = -O -std=c++11
CC = g++

all: $(EXES)

clean:
	rm -rf $(OBJS) $(EXES)

emailList: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) -o emailList

main.o: main.cpp helperfunctions.h
	$(CC) -c $(CPPFLAGS) main.cpp

helperfunctions: helperfunctions.cpp helperfunctions.h
	$(CC) -c $(CPPFLAGS) helperfunctions.cpp
