all: setup bin/tmplt

CC := gcc
CFLAGS := -I config -std=c99 -Wall -pedantic

bin/tmplt: obj/tmplt.o
	$(CC) $(CFLAGS) obj/tmplt.o -o bin/tmplt

obj/tmplt.o: src/tmplt.c config/tmplt.h
	$(CC) $(CFLAGS) src/tmplt.c -c -o obj/tmplt.o

setup: obj bin

obj:
	mkdir -p obj

bin:
	mkdir -p bin

clean:
	rm -rf obj bin
