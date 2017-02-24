# makefile for MassEmailList
OBJS = main.o helperfunctions.o
EXES = emailList
CPPFLAGS = -O -std=c++11
CC = g++
DEL = rm -vrf

all: $(EXES)

clean:
	$(DEL) $(OBJS) $(EXES)

emailList: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) -o emailList

# main.o: main.cpp helperfunctions.h
# 	$(CC) -c $(CPPFLAGS) main.cpp
#
# helperfunctions.o: helperfunctions.cpp helperfunctions.h
# 	$(CC) -c $(CPPFLAGS) helperfunctions.cpp

.cpp.o:
	$(CC) -c $(CPPFLAGS) $< -o $@
