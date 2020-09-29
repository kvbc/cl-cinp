/*
*
* reader.h
* Memory Reader
*
*/


#pragma once

#include <stddef.h>
#define CL_READER_EOS -1


typedef struct {
	char* beg;
	char* cur;
	char* end;
	size_t col;
	size_t line;
} cl_reader_t;


cl_reader_t* cl_reader_new(char* src);
char cl_reader_readbyte(cl_reader_t* rdr);
void cl_reader_skip(cl_reader_t* rdr, size_t bytes);
void cl_reader_close(cl_reader_t* rdr);
