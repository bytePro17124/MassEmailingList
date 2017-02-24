# makefile for MassEmailList
.SUFFIXES: .cpp .o
OBJS = main.o helperfunctions.o
EXES = emailList
CPPFLAGS = -O -std=c++11
CC = g++
DEL = rm -rf

all: $(EXES)

clean:
	$(DEL) $(OBJS) $(EXES)

emailList: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) -o emailList

# main.o: main.cpp helperfunctions.h
# 	$(CC) -c $(CPPFLAGS) main.cpp -o main.o
#
# helperfunctions.o: helperfunctions.cpp helperfunctions.h
# 	$(CC) -c $(CPPFLAGS) helperfunctions.cpp -o helperfunctions.o

.cpp.o:
	$(CC) -c $(CPPFLAGS) $< -o $@
