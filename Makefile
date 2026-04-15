CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

all: test

test: tablerow.c test.c
	$(CC) $(CFLAGS) -o test.o tablerow.c test.c

clean:
	rm -f test.o
