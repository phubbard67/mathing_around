#makes main
#make main will build
#make clean will destroy

CC = g++
CFLAGS = -g -Wall

default: all 

all:	main.o powerOfTwo.o graph.o queue.o
	$(CC) $(CFLAGS) -o main main.o powerOfTwo.o graph.o queue.o

main.o: main.cpp powerOfTwo.h
	$(CC) $(CFLAGS) -c main.cpp

powerOfTwo.o: powerOfTwo.c powerOfTwo.h
	$(CC) $(CFLAGS) -c powerOfTwo.cpp

graph.o: graph.cpp graph.h
	$(CC) $(CFLAGS) -c graph.cpp

queue.o: queue.cpp queue.h
	$(CC) $(CFLAGS) -c queue.cpp

clean:
	$(RM) main *.o*
