/*
*
* reader.h
* Memory Reader
*
*/


#pragma once

#include <stddef.h>
#define CL_MEMREADER_EOS -1


typedef struct {
	char* cur;
	char* end;
} cl_memreader_t;


cl_memreader_t* cl_memreader_new(char* data);
char cl_memreader_readbyte(cl_memreader_t* reader);
void cl_memreader_skip(cl_memreader_t* reader, size_t bytes);
void cl_memreader_close(cl_memreader_t* reader);