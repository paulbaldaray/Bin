#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tmplt.h"

#define TRUE 1
#define FALSE 0
#define PANIC(...) { printf(__VA_ARGS__); exit(1); }

const int tmplt_dir_sz = sizeof(tmplt_dir) - 1;

int main(int argc, char **argv) {
	char *curr_dir = malloc(tmplt_dir_sz + 1);
	int curr_dir_sz = tmplt_dir_sz;
	strcpy(curr_dir, tmplt_dir);

	int num_file_names = 0, file_names_sz = 10;
	char **file_names = calloc(file_names_sz, sizeof(char*));

	for (int is_default_action = TRUE, action = 'd', i = 1; i < argc; ++i) {
		char *a = argv[i];
		int asz = strlen(a);

		if (asz == 2 && a[0] == '-') {
			is_default_action = FALSE;
			action = a[1];
			continue;
		}

		FILE *ofile, *ifile;
		char **file_name_ptr, copy_buf[copy_buf_sz];
		int is_eof;

		switch (action) {
			case 'd':
				curr_dir = realloc(curr_dir, tmplt_dir_sz + 1 + asz + 1);
				curr_dir_sz = tmplt_dir_sz + 1 + asz;
				curr_dir[tmplt_dir_sz] = '/';
				strcpy(curr_dir +  tmplt_dir_sz + 1, a);

				if (is_default_action) action = 'f';
				break;

			case 'f':
				if (num_file_names == file_names_sz)
					file_names = realloc(file_names, file_names_sz*=2);

				file_name_ptr = &file_names[num_file_names++];
				*file_name_ptr = realloc(*file_name_ptr, curr_dir_sz + 1 + asz + 1);
				strcpy(*file_name_ptr, curr_dir);
				(*file_name_ptr)[curr_dir_sz] = '/';
				strcpy(*file_name_ptr + curr_dir_sz + 1, a);

				if (is_default_action) action = 'o';
				break;

			case 'o':
				/* Check if all the file_names are valid */
				for (int j = 0; j < num_file_names; ++j)
					if (access(file_names[j], F_OK) != 0)
						PANIC("tmplt: template file '%s' does not exist.\n", file_names[j]);

				if ((ofile = fopen(a, "w")) == NULL)
					PANIC("tmplt: output file '%s' coud not be opened for writing.\n", a);

				for (int j = 0; j < num_file_names; ++j) {
					if ((ifile = fopen(file_names[j], "r")) == NULL)
						PANIC("tmplt: template file '%s' could not be opened for reading.\n", file_names[j]);
					do {
						is_eof = fgets(copy_buf, copy_buf_sz, ifile) == NULL;
						fputs(copy_buf, ofile);
					} while(!is_eof);
					fclose(ifile);
				}
				fclose(ofile);
				break;

			default:
				PANIC("tmplt: unrecognized option '%c'\n", action);
				break;
		}
	}
}
