CC=gcc
CFLAGS=-std=c11 -Wall -Wextra
LDLIBS=-lncurses

all: caesar

caesar: main.o caesar.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o caesar

