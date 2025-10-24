CC = gcc
CFLAGS = -O3 -Wall -Wextra -pedantic -std=gnu89 -I./

all: prog1 prog2

prog1: funciones.o
	$(CC) $(CFLAGS) -o prog1 prog1.c funciones.o

prog2: funciones.o
	$(CC) $(CFLAGS) -o prog2 prog2.c funciones.o

funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c funciones.c

clean:
	rm -f *.o prog1 prog2
