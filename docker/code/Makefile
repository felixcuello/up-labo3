CC = gcc
CFLAGS = -Wall

OBJS_COMMON = common.o

all: writer1 writer2 cleanup

common.o: common.c common.h
	$(CC) $(CFLAGS) -c common.c

writer1: common.o
	$(CC) writer1.c -o writer1 common.o

writer2: common.o
	$(CC) writer2.c -o writer2 common.o

cleanup: common.o
	$(CC) cleanup.c -o cleanup common.o

clean:
	rm -f *.o writer1 writer2 cleanup

