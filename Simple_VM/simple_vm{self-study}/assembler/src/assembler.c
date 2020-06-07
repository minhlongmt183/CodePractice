#include <string.h>
#include <stdio.h>

int usage(void){
	fputs("usage: assembler ifile [-o ofile]\n", stderr);
	return -1;
}

int main(int argc, char **argv){
	char *ifile, *ofile, *arg, *file_contents;
	int i;
	size_t file_size;
	FILE *fp;

	--argc; ++ argv;
	if (argc == 0){
		return usage();
	}
	ifile = NULL; ofile = NULL;
	/*Parse aguments. */
	for (i = 0; i < agrc; ++i){
		arg = argv[i];
		if (strcmp(arg, "-o") == 0){
			if (i + 1 < agrc){
				ofile = strdup(argv[i+1]);
				++i;
				continue;
			}
			else{
				return error("No output file specified with '-o' flag.\n");
			}
		}
		else {
			ifile = strdup(argv[i]);
		}
	}

	if (ifile == NULL){
		return error("No input file specified. \n");
	}
	if (ofile == NULL){
		ofile = open_ofile_name(ifile);
	}
	else{
	}

	fp = fopen(ifile, "rb");
	if (fp == NULL){
		return error("Input file not found. \n");
	}

	fseek(fp, 0L, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
