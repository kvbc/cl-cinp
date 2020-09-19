/*
*
* reader.c
* Memory Reader
*
*/


#include "reader.h"
#include <stdlib.h>
#include <string.h>



cl_memreader_t* cl_memreader_new(char* data) {
	cl_memreader_t* reader = malloc(sizeof(cl_memreader_t));
	reader->cur = data;
	reader->end = data + strlen(data);
	return reader;
}


char cl_memreader_readbyte(cl_memreader_t* reader) {
	if(reader->cur < reader->end)
		return *reader->cur++;
	return CL_MEMREADER_EOS;
}


void cl_memreader_skip(cl_memreader_t* reader, size_t bytes) {
	reader->cur += bytes;
}


void cl_memreader_close(cl_memreader_t* reader) {
	free(reader);
}