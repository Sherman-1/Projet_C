CC = gcc
CFLAGS = -Wall

all: projet_C

projet_C: fonction.o main.o
	$(CC) main.o fonction.o -o projet_C

fonction.o: fonction.c fonction.h
	$(CC) -c fonction.c $(CFLAGS)

main.o: main.c fonction.h
	$(CC) -c main.c $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f projet_C
