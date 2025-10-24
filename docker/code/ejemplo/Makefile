CC = gcc
CFLAGS = -O3 -Wall -Wextra -pedantic -std=gnu89 -I./

all: prog1 prog2

prog1: funciones.o archivos.o
	$(CC) $(CFLAGS) -o prog1 prog1.c funciones.o archivos.o

prog2: funciones.o archivos.o
	$(CC) $(CFLAGS) -o prog2 prog2.c funciones.o archivos.o

funciones.o: funciones.c
	$(CC) $(CFLAGS) -c funciones.c -o funciones.o

archivos.o: archivos.c
	$(CC) $(CFLAGS) -c archivos.c -o archivos.o

clean:
	rm -f *.o prog1 prog2
