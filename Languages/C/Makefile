# Author: John Buckley
# File: Makefile
# Desc: Makefile to compile program for Dijkstras algorithm in C

#Default compiler
CC = gcc

#Target executable name
TARGET=dijkstra

#Compiler flags for all errors and warnings
CFLAGS=-c -Wall

#make all dependencies and the target
all: $(TARGET)
	make graph.o;
	make main.o;
	make $(TARGET);

#link all .o and create executable
$(TARGET): graph.o main.o
	$(CC) graph.o main.o -o $(TARGET)

#compile main.c to main.o
main.o: main.c
	$(CC) $(CFLAGS) main.c

#compile graph.c to graph.o
graph.o: graph.c
	$(CC) $(CFLAGS) graph.c

#removes object files and executable
clean:
	rm *.o $(TARGET) *~
