#makes hw3


CC = gcc
CFLAGS = -g -Wall

default: hw3

hw3:	hw3.o powerOfTwo.o 
	$(CC) $(CFLAGS) -o hw3 hw3.o powerOfTwo.o

hw3.o: hw3.c powerOfTwo.h
	$(CC) $(CFLAGS) -c hw3.c

powerOfTwo.o: powerOfTwo.c powerOfTwo.h
	$(CC) $(CFLAGS) -c powerOfTwo.c

clean:
	$(RM) hw3 *.o*
