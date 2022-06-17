# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
CC = g++
 
# ****************************************************
# Targets needed to bring the executable up to date
main: main.o SLLString.o
	$(CC) -o main main.o SLLString.o
 
# The main.o target can be written more simply
 
main.o: main.cpp SLLString.h Node.h
	$(CC) -c main.cpp

SLLString.o: SLLString.h

clean:
	rm -vf *.o *.exe *.obj *.pdb *.ilk