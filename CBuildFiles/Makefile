all: setup bin/backlight bin/tmplt

CC := gcc
CFLAGS := -I config -std=c99 -Wall -pedantic

bin/backlight: obj/backlight.o
	$(CC) $(CFLAGS) obj/backlight.o -o bin/backlight

obj/backlight.o: src/backlight.c config/backlight.h
	$(CC) $(CFLAGS) src/backlight.c -c -o obj/backlight.o

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
