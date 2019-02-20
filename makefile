#makes main
#make main will build
#make clean will destroy

CC = gcc
CFLAGS = -g -Wall

default: math 

math:	main.o powerOfTwo.o 
	$(CC) $(CFLAGS) -o main main.o powerOfTwo.o

main.o: main.c powerOfTwo.h
	$(CC) $(CFLAGS) -c main.c

powerOfTwo.o: powerOfTwo.c powerOfTwo.h
	$(CC) $(CFLAGS) -c powerOfTwo.c

clean:
	$(RM) main *.o*
