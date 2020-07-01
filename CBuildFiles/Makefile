all: obj bin bin/backlight

obj:
	mkdir obj

bin:
	mkdir bin

bin/backlight: obj/backlight.o
	gcc obj/backlight.o -o bin/backlight

obj/backlight.o: src/backlight.c
	gcc src/backlight.c -c -o obj/backlight.o

clean:
	rm -rf bin obj
