#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "backlight.h"

int ftruncate(int filedes, off_t length);
int fileno(FILE* stream);

int per_to_num(int per) {
	return max_brightness * per / 1000 + (per < 0 ? -1 : !!per);
}

char buf[100] = {0};

int main(int argc, char **argv) {
	int per;
	if (argc < 2 || sscanf(argv[1], "%d", &per) != 1 || per < -1000 || per > 1000) {
		printf("backlight: Invalid arguments.\n");
		exit(1);
	}

	FILE *file = fopen(brightness_path, "r+");
	if (file == NULL) {
		printf("backlight: brightness file could not be found.\n");
		exit(1);
	}
	int bval;
	fgets(buf, 100, file);
	if (sscanf(buf, "%d", &bval) != 1) {
		printf("backlight: brightness file coud not be read.\n");
		exit(1);
	}
	
	bval += per_to_num(per);
	if (bval < 0) bval = 0;
	if (bval > max_brightness) bval = max_brightness;
	sprintf(buf, "%d\n", bval);

	ftruncate(fileno(file), 0);
	fseek(file, 0, SEEK_SET);
	fputs(buf, file);
	fclose(file);

	return 0;
}
