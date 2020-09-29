/*
*
* reader.c
* Memory Reader
*
*/


#include "reader.h"
#include "char.h"

#include <stdlib.h>
#include <string.h>


cl_reader_t* cl_reader_new(char* src) {
	cl_reader_t* rdr = malloc(sizeof(cl_reader_t));
	rdr->beg = src;
	rdr->cur = src;
	rdr->end = src + strlen(src);
	rdr->col = 1;
	rdr->line = 1;
	return rdr;
}


char cl_reader_readbyte(cl_reader_t* rdr) {
	if(rdr->cur < rdr->end) {
		char c = *rdr->cur++;
		if(cl_char_islb(c)) {
			if(cl_char_islb(*rdr->cur) && *rdr->cur != c) ++rdr->cur;
			++rdr->line;
			rdr->col = 1;
		}
		else ++rdr->col;
		return c;
	}
	return CL_READER_EOS;
}


void cl_reader_skip(cl_reader_t* rdr, size_t bytes) {
	rdr->cur += bytes;
	rdr->col += bytes;
}


void cl_reader_close(cl_reader_t* rdr) {
	free(rdr);
}
