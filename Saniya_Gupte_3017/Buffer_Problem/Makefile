# Makefile

CC = gcc
CFLAGS = -Wall -g

all: test

test: fixed_buff_list.o test.o
	$(CC) $(CFLAGS) -o test fixed_buff_list.o test.o

fixed_buff_list.o: fixed_buff_list.c fixed_buff_list.h
	$(CC) $(CFLAGS) -c fixed_buff_list.c

test.o: test.c fixed_buff_list.h
	$(CC) $(CFLAGS) -c test.c

clean:
	rm -f *.o test output.log
