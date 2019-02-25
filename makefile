#makes main
#make main will build
#make clean will destroy

CC = g++
CFLAGS = -g -Wall

default: all 

all:	main.o powerOfTwo.o graph.o 
	$(CC) $(CFLAGS) -o main main.o powerOfTwo.o graph.o

main.o: main.cpp powerOfTwo.h
	$(CC) $(CFLAGS) -c main.cpp

powerOfTwo.o: powerOfTwo.cpp powerOfTwo.h
	$(CC) $(CFLAGS) -c powerOfTwo.cpp

graph.o: graph.cpp graph.h myQueue.h
	$(CC) $(CFLAGS) -c graph.cpp

clean:
	$(RM) main *.o*
