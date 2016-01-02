#progs : bstlib.c testlib.c
CC=gcc
CFLAGS=-I.
testlib : bstlib.o testlib.o
	$(CC) -o testlib bstlib.o testlib.o $(CFLAGS)

