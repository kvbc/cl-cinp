#include "src/vm.h"
#include <stdio.h>
#include <stdlib.h>


static char* read_file(char* fn) {
	char* buff = NULL;
	FILE* f = fopen(fn, "rb");

	if(f) {
		fseek(f, 0, SEEK_END);
        size_t len = ftell(f);
        fseek(f, 0, SEEK_SET);

        buff = malloc(len + 1);
        size_t read_len = fread(buff, 1, len, f);
        if(len != read_len) {
			free(buff);
			buff = NULL;
        }

        fclose(f);
        buff[len] = '\0';
	}
	else {
		printf("\nFile '%s' not found", fn);
	}

	return buff;
}


int main(int argc, char** argv) {
	if(argc > 1) {
		char* file = read_file(argv[1]);
		if(file == NULL)
			return EXIT_FAILURE;

		cl_vm_t* vm = cl_vm_new();
		cl_vm_run(vm, file);
		cl_vm_close(vm);
		free(file);
	}
	else {
		puts("Expected the filename to read from");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
