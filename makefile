#makes main
#make main will build
#make clean will destroy

CC = gcc
CFLAGS = -g -Wall

default: all 

all:	main.o powerOfTwo.o 
	$(CC) $(CFLAGS) -o main main.o powerOfTwo.o graph.o

main.o: main.c powerOfTwo.h
	$(CC) $(CFLAGS) -c main.c

powerOfTwo.o: powerOfTwo.c powerOfTwo.h
	$(CC) $(CFLAGS) -c powerOfTwo.c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c

clean:
	$(RM) main *.o*
